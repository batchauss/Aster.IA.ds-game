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
  this->setMinimumSize(800, 800);
  QVBoxLayout * layout = new QVBoxLayout();
  layout->setAlignment(Qt::AlignCenter);
  layout->setSpacing(20);

  /*      Bouton Jouer      */

  QPushButton * jouer = new QPushButton("Jouer");
  jouer->setFixedSize(260, 80);
  QObject::connect(jouer, &QPushButton::clicked,
  [=](){
    this->close();
    return notre_init(argc, argv, &Modelisation);
  });

  /*      Bouton Options      */

  QPushButton * options = new QPushButton("Options");
  options->setFixedSize(260, 80);

  /*      Bouton Quitter      */
  
  QPushButton * quitter = new QPushButton("Quitter");
  quitter->setFixedSize(260, 80);
  QObject::connect(quitter, &QPushButton::clicked,
  [=](){
    this->close();
  });

  QWidget * cWidget = new QWidget;
  cWidget->setLayout(layout);
  this->setCentralWidget(cWidget);

  layout->addWidget(jouer);
  layout->addWidget(options);
  layout->addWidget(quitter);
}

mainwindow::~mainwindow(){}