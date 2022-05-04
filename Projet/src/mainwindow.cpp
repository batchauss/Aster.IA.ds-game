#include "mainwindow.h"

extern GLvoid VM_init();

GLvoid Modelisation()
{
  VM_init();
  glutSwapBuffers();
}

mainwindow::mainwindow(int argc, char**argv)
    : QMainWindow()
{
  this->showFullScreen();

  /*      Menu principal      */

  QWidget * menuPWidget = new QWidget;

  //  Bouton Jouer

  QPushButton * jouer = new QPushButton("Jouer");
  jouer->setFixedSize(400, 100);
  QObject::connect(jouer, &QPushButton::clicked,
  [=](){
    this->close();
    return notre_init(argc, argv, &Modelisation);
  });

  //  Bouton Options

  QPushButton * options = new QPushButton("Options");
  options->setFixedSize(190, 50);
  QObject::connect(options, &QPushButton::clicked,
  [=](){
    
  });

  //  Bouton Quitter
  
  QPushButton * quitter = new QPushButton("Quitter");
  quitter->setFixedSize(190, 50);
  QObject::connect(quitter, &QPushButton::clicked,
  [=](){
    this->close();
  });

  //  Layout

  QGridLayout * layout = new QGridLayout();
  layout->setAlignment(Qt::AlignCenter);
  layout->setHorizontalSpacing(20);
 
  layout->addWidget(jouer, 0, 0, 2, 4);
  layout->addWidget(options, 2, 0, 1, 1);
  layout->addWidget(quitter, 2, 1, 1, 1);

  menuPWidget->setLayout(layout);

  /*      Central Widget      */

  this->setCentralWidget(menuPWidget);
}

mainwindow::~mainwindow(){}