#include "interface.h"

#include <unistd.h> // fork, pipe, read, write
#include <stdlib.h> // exit
#include <fcntl.h> // fcntl
#include <csignal> // std::signal
#include <poll.h>
#include <cstdint> // uint64_t

#include <chrono> // std::chrono
#include <thread> // std::thread
#include <iostream> // std::cout

bool is_pipe_closed(int fd) {
    struct pollfd pfd = {
        .fd = fd,
        .events = POLLOUT,
		.revents = 0,
    };

    if (poll(&pfd, 1, 1) < 0) {
        return false;
    }

    return pfd.revents & POLLERR;
}

namespace config {
	const int DISCORD_MAX_TRY = 5;
	const uint64_t DISCORD_APP_ID = 981131950960037929;
	const std::chrono::duration DISCORD_RETRY_DELAY = std::chrono::seconds(60);
	const std::chrono::duration DISCORD_PING_INTERVAL = std::chrono::milliseconds(750);
};

discord::Timestamp DiscordRichPresence::now() const {
	return std::chrono::duration_cast<std::chrono::seconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
}

DiscordRichPresence& DiscordRichPresence::make() {
	if( DiscordRichPresence::instance == nullptr ) {
		return *(DiscordRichPresence::instance = new DiscordRichPresence());
	} else {
		return *(DiscordRichPresence::instance);
	}
}

DiscordRichPresence::DiscordRichPresence() {
	// Création système échange de donnée
	int channels[2];
	if( pipe(channels) != 0 ) {
		std::cout << "Error while trying to create pipe for discordRichPresence sub program" << std::endl;
		delete this;
		exit(1);
	};

	// La lecture ne doit pas être bloquante
	fcntl( channels[0] , F_SETFL , fcntl(channels[0], F_GETFL) | O_NONBLOCK );

	// Création sub process
	int pid = fork();

	// Split traitement père / fils
	if( pid == 0 ) { // Processus fils
		// Le fils n'écrira pas sur le canal d'échange
		close(channels[1]);
		// sauvegarde du canal d'échange
		this->dataChannel = channels[0];
		// Lancement de la routine
		this->run();
		delete this;
		exit(0);

	} else { // Processus père
		// Le père ne lira pas sur le canal d'échange
		close(channels[0]);
		// sauvegarde du canal d'échange
		this->dataChannel = channels[1];
	}
}

DiscordRichPresence::~DiscordRichPresence() {
	// Fermeture du canal d'échange
	close(dataChannel);
}

void DiscordRichPresence::setStatus(DiscordRichPresenceStatus state) {
	ssize_t returnCode = write(dataChannel, &state, sizeof(DiscordRichPresenceStatus));
	if( returnCode != 0 ) {
		std::cout << "Error while trying to send data to rich presence sub program" << std::endl;
		delete this;
		exit(1);
	};;
}

void DiscordRichPresence::run() {
	discord::Timestamp ts_begin = now();

	// Log in to the discord app
	discord::Core* core{};
	auto result = discord::Core::Create(
		config::DISCORD_APP_ID,
		EDiscordCreateFlags::DiscordCreateFlags_NoRequireDiscord,
		&core
	);

	// If unable to log in or fail
	if (!core) {
		int fail_code = static_cast<int>(result);
		switch( fail_code ) {
			case 4:
				std::cout << "Discord not started" << std::endl;
				std::this_thread::sleep_for(config::DISCORD_RETRY_DELAY);
				if( ! is_pipe_closed(this->dataChannel) ) {
					return this->run();
				} else {
					return;
				}

			default:
				std::cout << "Failed to setup discord SDK! (err :" << fail_code << ")" << std::endl;
				return;
		}
	}

	// Initiate activity state
    discord::Activity activity{};
    activity.SetType(discord::ActivityType::Playing);
    activity.SetApplicationId(981131950960037929);
    activity.SetDetails("Soon");
    activity.SetState("En développement ⌨️ ");
    activity.GetAssets().SetSmallImage("dev-tools");
    activity.GetAssets().SetSmallText("Dev tools");
    activity.GetAssets().SetLargeImage("task-list");
    activity.GetAssets().SetLargeText("Prochainement ...");
    activity.GetTimestamps().SetStart(ts_begin);
    core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
	    std::cout << ((result == discord::Result::Ok) ? "Succeeded" : "Failed")
				 << " updating activity!\n";
    });

    	/**
    	 * Loop to send info
    	 **/
    	// Handle cleanly interruption
	bool end = false;
    	do {
    		core->RunCallbacks();

			update(activity,core,end);

    		std::this_thread::sleep_for(config::DISCORD_PING_INTERVAL);
    	} while (!end);

	delete core;
}

DiscordRichPresence* DiscordRichPresence::instance = 0;

void DiscordRichPresence::update(discord::Activity & activity,discord::Core* core,bool & end) {

	DiscordRichPresenceStatus rep;
	int readCode = read(this->dataChannel , &rep , sizeof(DiscordRichPresenceStatus) );
	if( readCode == 0 ) {
		end = true;
		return;
	} else
	if( readCode == -1 ) {
		// Nothing to read, nothing to do
	} else {
		switch (rep) {
			case DiscordRichPresenceStatus::stop :
				exit(0);

			case DiscordRichPresenceStatus::playing :
			     activity.SetState("En partie");
			     activity.GetTimestamps().SetStart(now());
				break;

			case DiscordRichPresenceStatus::menu :
			     activity.SetState("Dans les menu");
			     activity.GetTimestamps().SetStart(now());
				break;
		}



		     core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {
		 	    std::cout << ((result == discord::Result::Ok) ? "Succeeded" : "Failed")
		 				 << " updating activity!\n";
		     });
	}
}
