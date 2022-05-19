#include "mainwindow.h"

extern GLvoid VM_init();

std::string pseudonyme;

extern GLfloat ambiente[4];
extern bool pauseActivated;

int tempsAvant;
int tempsApres;
int tempsRetenu = 0;

bool doPauseOnce = false;
bool doUnpauseOnce = false;

GLvoid Modelisation()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

  decoHUD();
  timer(tempsRetenu);

  if(!pauseActivated){  // Lorque pause n'est pas actif

    if(doUnpauseOnce){
      tempsRetenu += tempsApres - tempsAvant;
      doUnpauseOnce = false;
    }

    for(unsigned int i=0; i<3; i++) ambiente[i] = 0.7;
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);

    VM_init();
    glutSwapBuffers();

    doPauseOnce = false;
  }
  else if(!doPauseOnce){ // effectué une seule fois => bouton de pause activé
    renduPause();

    tempsAvant = glutGet(GLUT_ELAPSED_TIME);
    
    for(unsigned int i=0; i<3; i++) ambiente[i] = 0.3;
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);
    VM_init();
    glutSwapBuffers();

    doPauseOnce = true;
    doUnpauseOnce = true;
  }
  else {
    tempsApres = glutGet(GLUT_ELAPSED_TIME);
  }
}

void mainwindow::alignCenterWindow(){
  QDesktopWidget * widget = QApplication::desktop();
  int desktop_width = widget->width();
  int desktop_height = widget->height();
  int x = desktop_width / 2 - width() / 2;
  int y = desktop_height / 2 - height() / 2;
  this->move(QPoint(x, y));
}

/*      Menu principal      */
void mainwindow::createWidgetMenuPrincipal(int argc, char**argv){
  QWidget * menuPrincipal = new QWidget();
  this->widgets->addWidget(menuPrincipal);

  //  Text area pseudo

  QLineEdit * pseudo = new QLineEdit();
  pseudo->setAlignment(Qt::AlignCenter);
  pseudo->setFixedSize(400, 50);
  pseudo->setMaxLength(10);
  pseudo->setPlaceholderText("PSEUDO");
  int r = rand() % 1000 + 1;
  pseudo->setText("Anon" + QString::number(r));
  pseudo->setFont(QFont("Cochin", 15));

  //  Bouton Jouer

  QPushButton * jouer = new QPushButton("JOUER");
  jouer->setFont(QFont("Times", 30));
  jouer->setFixedSize(400, 100);
  QObject::connect(jouer, &QPushButton::clicked,
  [=](){
    pseudonyme = pseudo->text().toStdString();
    this->close();
    return notre_init(argc, argv, &Modelisation);
  });

  //  Bouton Options

  QPushButton * options = new QPushButton("Options");
  options->setFixedSize(190, 50);
  options->setFont(QFont("Times", 15));
  QObject::connect(options, &QPushButton::clicked,
  [=](){
    switchMenuOption();
  });

  //  Bouton Quitter
  
  QPushButton * quitter = new QPushButton("Quitter");
  quitter->setFixedSize(190, 50);
  quitter->setFont(QFont("Times", 15));
  QObject::connect(quitter, &QPushButton::clicked,
  [=](){
    this->close();
  });

  //  Layout

  QGridLayout * layout = new QGridLayout();
  layout->setAlignment(Qt::AlignCenter);
  layout->setHorizontalSpacing(20);
  layout->setVerticalSpacing(10);
 
  layout->addWidget(pseudo, 0, 0, 1, 2);
  layout->addWidget(jouer, 1, 0, 1, 2);
  layout->addWidget(options, 2, 0);
  layout->addWidget(quitter, 2, 1);

  menuPrincipal->setLayout(layout);

}

/*      Menu options      */
void mainwindow::createWidgetMenuOption(){
  QWidget * menuOption = new QWidget();
  this->widgets->addWidget(menuOption);
   
  //  Options

  QComboBox * languageCB = new QComboBox();
  languageCB->addItem("Français");
  languageCB->addItem("English");

  QComboBox * tailleFenetreCB = new QComboBox();
  tailleFenetreCB->addItem("1280x960");
  tailleFenetreCB->addItem("1920x1080");
  tailleFenetreCB->addItem("Fullscreen");


  //  Layout

  QGridLayout * layoutOption = new QGridLayout();
  layoutOption->setAlignment(Qt::AlignCenter);
  layoutOption->setHorizontalSpacing(20);

  layoutOption->addWidget(new QLabel("Langue : "), 0, 0);
  layoutOption->addWidget(languageCB, 0 , 1);
  layoutOption->addWidget(new QLabel("Taille de la fenêtre : "), 1, 0);
  layoutOption->addWidget(tailleFenetreCB, 1, 1);

  QPushButton * quitterOptions = new QPushButton("Quitter (Sans sauvegarder)");
  QObject::connect(quitterOptions, &QPushButton::clicked,
  [=](){
    switchMenuPrincipal();
  });
  layoutOption->addWidget(quitterOptions, 2, 0);

  QPushButton * confirmeOptions = new QPushButton("Confirmer");
  QObject::connect(confirmeOptions, &QPushButton::clicked,
  [=](){
    switchMenuPrincipal();
  });
  layoutOption->addWidget(confirmeOptions, 2, 1);

  menuOption->setLayout(layoutOption);
}

mainwindow::mainwindow(int argc, char**argv)
    : QMainWindow()
{
  widgets = new QStackedWidget();
  this->showFullScreen();
  /*      Central Widget      */

  createWidgetMenuPrincipal(argc, argv);
  createWidgetMenuOption();

  this->setCentralWidget(widgets);
  

  this->setWindowIcon(QIcon(":/pic/aste.ico"));
    QPixmap bkgnd(":/pic/background.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
  
}

mainwindow::~mainwindow(){}