#include "qt/mainwindow.h"
#include <QApplication>
#include <ctime>

#include "discordRichPresence/interface.h"

int main(int argc, char**argv)
{
  srand(time(0));
  initialise();

	DiscordRichPresence::make().setStatus( DiscordRichPresenceStatus::menu );

  QApplication * a = new QApplication(argc, argv);
    mainwindow * m = new mainwindow(argc, argv);
    m->show();
  return a->exec();
}
