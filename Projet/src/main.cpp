#include "qt/mainwindow.h"
#include <QApplication>
#include <ctime>


int main(int argc, char**argv)
{
  srand(time(0));
  initialise();

  QApplication * a = new QApplication(argc, argv);
    mainwindow * m = new mainwindow(argc, argv);
    m->show();
  return a->exec();
}
