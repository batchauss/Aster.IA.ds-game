#pragma once

#include "lib/discord.h" // discord::

enum class DiscordRichPresenceStatus { menu, playing, stop };

class DiscordRichPresence {

public:
	// Si instance est nullptr : Génère une instance de DiscordRichPresence la stock dans la statique
	// Sinon : Retourne l'instance de la variable
	// ( Factory , Uniq )
	static DiscordRichPresence& make();

	// Destructeur pour gérer les canaux de discussion
	~DiscordRichPresence();

	// Supression volontaire des opérateurs de recopie pour évité des problèmes
	DiscordRichPresence(const DiscordRichPresence & original) = delete;
	DiscordRichPresence operator=(const DiscordRichPresence & orignal) = delete;

	void setStatus(DiscordRichPresenceStatus state); // Write Pipe

private:
	// Retourne le timestamp du moment où la fonction est invoquer
	discord::Timestamp now() const;

	// Génère une instance qui fork pour split, et setup le pipe
	DiscordRichPresence();

	// Routine d'envoie à discord
	void run();

	static DiscordRichPresence* instance;	// Stock l'uniqu instance
	int dataChannel;

	void update(discord::Activity & activity,discord::Core* core,bool & end);

};
