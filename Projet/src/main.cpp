#include "mainwindow.h"
#include <QApplication>

int main(int argc, char**argv)
{
  initialise();

  QApplication * a = new QApplication(argc, argv);

  mainwindow * m = new mainwindow(argc, argv);
  m->show();

  return a->exec();
}
