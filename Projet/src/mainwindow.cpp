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

  QWidget * menuPrincipal = new QWidget();
  QWidget * menuOption = new QWidget();

  /*      Menu principal      */

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
    this->setCentralWidget(menuOption);
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

  menuPrincipal->setLayout(layout);

  /*      Menu options      */

  //  Options

  QComboBox * languageCB = new QComboBox();
  languageCB->addItem("Français");
  languageCB->addItem("English");

  QComboBox * tailleFenetreCB = new QComboBox();
  tailleFenetreCB->addItem("1280x960");
  tailleFenetreCB->addItem("1920x1080");

  //  Layout

  QGridLayout * layoutOption = new QGridLayout();
  layoutOption->setAlignment(Qt::AlignCenter);
  layoutOption->setHorizontalSpacing(20);

  layoutOption->addWidget(new QLabel("Langue : "), 0, 0);
  layoutOption->addWidget(languageCB, 0 , 1);
  layoutOption->addWidget(new QLabel("Taille de la fenêtre : "), 1, 0);
  layoutOption->addWidget(tailleFenetreCB, 1, 1);

  layoutOption->addWidget(new QPushButton("Quitter (Sans sauvegarder)"), 2, 0);
  layoutOption->addWidget(new QPushButton("Confirmer"), 2, 1);


  menuOption->setLayout(layoutOption);

  /*      Central Widget      */

  this->setCentralWidget(menuPrincipal);
}

mainwindow::~mainwindow(){}