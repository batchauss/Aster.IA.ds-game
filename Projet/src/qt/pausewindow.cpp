#include "pausewindow.h"

pausewindow::pausewindow()
    : QMainWindow()
{
this->setAttribute(Qt::WA_TranslucentBackground, true);
this->showFullScreen();

QWidget * menuPause = new QWidget();

  //Boutons

  QPushButton * reprendreButton = new QPushButton("Reprendre");
  reprendreButton->setFixedSize(300, 100);
  QObject::connect(reprendreButton, &QPushButton::clicked,
  [=](){

  });

  QPushButton * exitButton = new QPushButton("Quitter le jeu");
  exitButton->setFixedSize(300, 100);
  QObject::connect(exitButton, &QPushButton::clicked,
  [=](){

  });

  //  Layout

  QGridLayout * layoutOption = new QGridLayout();
  layoutOption->setAlignment(Qt::AlignCenter);
  layoutOption->setHorizontalSpacing(20);

  layoutOption->addWidget(reprendreButton, 0 , 0);
  layoutOption->addWidget(exitButton, 0, 1);

  menuPause->setLayout(layoutOption);
  this->setCentralWidget(menuPause);
}

pausewindow::~pausewindow(){}