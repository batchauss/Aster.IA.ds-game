#include "../../includes/constant.h"

#include "mainwindow.h"

extern GLvoid VM_init();

std::string pseudonyme;
extern GLfloat score;

extern GLfloat ambiente[4];
extern bool pauseActivated;
extern bool finActivated;

int tempsAvant = gameconf::BASETIME;
int tempsApres = gameconf::BASETIME;
int tempsRetenu = gameconf::BASETIME;

bool doPauseOnce = false;
bool doUnpauseOnce = false;

extern GLvoid renduFin();

GLvoid Modelisation()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if (finActivated)
  {
    finJeu(score, pseudonyme);
    glutSwapBuffers();
  }
  else if (!pauseActivated)
  { // Lorque pause n'est pas actif

    decoHUD();
    timer(tempsRetenu);

    if (doUnpauseOnce)
    {
      tempsRetenu += tempsApres - tempsAvant;
      doUnpauseOnce = false;
    }

    for (unsigned int i = 0; i < 3; i++)
      ambiente[i] = gameconf::GAME_AMBIENTE_LIGHT;
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);

    VM_init();
    glutSwapBuffers();

    doPauseOnce = false;
  }
  else if (!doPauseOnce)
  { // effectué une seule fois => bouton de pause activé
    timer(tempsRetenu);
    renduPause();
    tempsAvant = glutGet(GLUT_ELAPSED_TIME);

    for (unsigned int i = 0; i < 3; i++)
      ambiente[i] = gameconf::PAUSE_AMBIENTE_LIGHT;

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);
    VM_init();
    glutSwapBuffers();

    doPauseOnce = true;
    doUnpauseOnce = true;
  }
  else
  {
    tempsApres = glutGet(GLUT_ELAPSED_TIME);
  }
}

void mainwindow::alignCenterWindow()
{
  QDesktopWidget *widget = QApplication::desktop();
  int desktop_width = widget->width();
  int desktop_height = widget->height();
  int x = desktop_width / 2 - width() / 2;
  int y = desktop_height / 2 - height() / 2;
  this->move(QPoint(x, y));
}

#include <QFontDatabase>
#include <iostream>
/*      Menu principal      */
void mainwindow::createWidgetMenuPrincipal(int argc, char **argv)
{
  QFontDatabase k;
const QStringList fontFamilies = k.families();
for (const QString &s : fontFamilies) {
    std::cout << "-" << s.toStdString() << std::endl;
  }
  QWidget *menuPrincipal = new QWidget();
  this->widgets->addWidget(menuPrincipal);

  //  Text area pseudo

  QLineEdit *pseudo = new QLineEdit();
  pseudo->setAlignment(Qt::AlignCenter);
  pseudo->setFixedSize(menu::PSEUDO_AREA_SIZE_X, menu::PSEUDO_AREA_SIZE_Y);
  pseudo->setMaxLength(menu::PSEUDO_MAX_LENGTH);
  pseudo->setPlaceholderText("PSEUDO");
  int r = rand() % 1000 + 1;
  pseudo->setText("Anon" + QString::number(r));
  pseudo->setFont(QFont("Cochin", lang_fr::PSEUDO_BOX_FONTSIZE));
  pseudo->setCursor(Qt::IBeamCursor);
  menuPrincipal->setStyleSheet(
    QString("QLineEdit {") +
    QString("color: white;") +
    QString("background-color: rgba( 45, 45, 45, 60% );") +
    QString("border-radius: 50px;") +
    QString("border-width: 1px;") +
    QString("border-style: solid;") +
    QString("border-top-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #66c9ff, stop: 0.1 #66c9ff, stop: 0.2 #00ffdd, stop: 0.3 #66c9ff, stop: 1 #66c9ff);") +
    QString("border-left-color: #66c9ff;") +
    QString("border-right-color: #66c9ff;") +
    QString("border-bottom-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 1 #66c9ff, stop: 0.9 #66c9ff, stop: 0.8 #00ffdd, stop: 0.7 #66c9ff, stop: 0 #66c9ff);") +
    QString("}") +
    QString("QPushButton {") +
    QString("font-family: Monospace;") +
    QString("color: white;") +
    QString("background-color: rgba( 102, 201, 255, 20% );") +
    QString("border-width: 1px;") +
    QString("border-style: solid;") +
    QString("border-top-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #66c9ff, stop: 0.1 #66c9ff, stop: 0.2 #00ffdd, stop: 0.3 #66c9ff, stop: 1 #66c9ff);") +
    QString("border-left-color: #66c9ff;") +
    QString("border-right-color: #66c9ff;") +
    QString("border-bottom-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 1 #66c9ff, stop: 0.9 #66c9ff, stop: 0.8 #00ffdd, stop: 0.7 #66c9ff, stop: 0 #66c9ff);") +
    QString("}") +
    QString("QLineEdit:hover {") +
    QString("background-color: rgba( 45, 45, 45, 0% );") +
    QString("}") +
    QString("QLineEdit:focus {") +
    QString("background-color: rgba( 45, 45, 45, 0% );") +
    QString("}")
  );

  //  Bouton Jouer

  QPushButton *jouer = new QPushButton("JOUER");
  jouer->setFont(QFont("Times", lang_fr::PLAY_BUTTON_FONTSIZE));
  jouer->setFixedSize(lang_fr::PLAY_BUTTON_SIZE_X, lang_fr::PLAY_BUTTON_SIZE_Y);
  jouer->setCursor(Qt::PointingHandCursor);
  QObject::connect(jouer, &QPushButton::clicked,
                   [=]()
                   {
                     pseudonyme = pseudo->text().toStdString();
                     this->close();
                     return notre_init(argc, argv, &Modelisation);
                   });

  //  Bouton Options

  QPushButton *options = new QPushButton("Options");
  options->setFixedSize(lang_fr::OPTIONS_BUTTON_SIZE_X, lang_fr::OPTIONS_BUTTON_SIZE_Y);
  options->setFont(QFont("Times", lang_fr::OPTIONS_BUTTON_FONTSIZE));
  options->setCursor(Qt::PointingHandCursor);
  QObject::connect(options, &QPushButton::clicked,
                   [=]()
                   {
                     switchMenuOption();
                   });

  //  Bouton Quitter

  QPushButton *quitter = new QPushButton("Quitter");
  quitter->setFixedSize(lang_fr::QUIT_BUTTON_SIZE_X, lang_fr::QUIT_BUTTON_SIZE_Y);
  quitter->setFont(QFont("Times", lang_fr::QUIT_BUTTON_FONTSIZE));
  quitter->setCursor(Qt::PointingHandCursor);
  QObject::connect(quitter, &QPushButton::clicked,
                   [=]()
                   {
                     this->close();
                   });

  //  Layout

  QGridLayout *layout = new QGridLayout();
  layout->setAlignment(Qt::AlignCenter);
  layout->setHorizontalSpacing(menu::HORIZONTAL_SPACING);
  layout->setVerticalSpacing(menu::VERTICAL_SPACING);

  layout->addWidget(pseudo, menu::PSEUDO_PLACEMENT[0], menu::PSEUDO_PLACEMENT[1], menu::PSEUDO_PLACEMENT[2], menu::PSEUDO_PLACEMENT[3]);
  layout->addWidget(jouer, menu::PLAY_PLACEMENT[0], menu::PLAY_PLACEMENT[1], menu::PLAY_PLACEMENT[2], menu::PLAY_PLACEMENT[3]);
  layout->addWidget(options, menu::OPTIONS_PLACEMENT[0], menu::OPTIONS_PLACEMENT[1]);
  layout->addWidget(quitter, menu::QUIT_PLACEMENT[0], menu::QUIT_PLACEMENT[1]);

  menuPrincipal->setLayout(layout);
}

/*      Menu options      */
void mainwindow::createWidgetMenuOption()
{
  QWidget *menuOption = new QWidget();
  this->widgets->addWidget(menuOption);

  //  Options

  QComboBox *languageCB = new QComboBox();
  languageCB->addItem("Français");
  languageCB->addItem("English");

  QComboBox *tailleFenetreCB = new QComboBox();
  tailleFenetreCB->addItem("1290x980");
  tailleFenetreCB->addItem("1920x1080");
  tailleFenetreCB->addItem("Fullscreen");

  //  Layout

  QGridLayout *layoutOption = new QGridLayout();
  layoutOption->setAlignment(Qt::AlignCenter);
  layoutOption->setHorizontalSpacing(menu::OPT_HORIZONTAL_SPACING);

  layoutOption->addWidget(new QLabel("Langue : "), lang_fr::LANG_SIZE_X, lang_fr::LANG_SIZE_Y);
  layoutOption->addWidget(languageCB, menu::OPT_LANG_PLACEMENT[0], menu::OPT_LANG_PLACEMENT[1]);
  layoutOption->addWidget(new QLabel(" Taille de la fenêtre: "), lang_fr::LANG_SIZE_X, lang_fr::LANG_SIZE_Y);
  layoutOption->addWidget(tailleFenetreCB, menu::OPT_WINDOW_PLACEMENT[0], menu::OPT_WINDOW_PLACEMENT[1]);

  QPushButton *quitterOptions = new QPushButton("Quitter (Sans sauvegarder)");
  QObject::connect(quitterOptions, &QPushButton::clicked,
                   [=]()
                   {
                     switchMenuPrincipal();
                   });
  layoutOption->addWidget(quitterOptions, menu::OPT_QUIT_PLACEMENT[0], menu::OPT_QUIT_PLACEMENT[1]);

  QPushButton *confirmeOptions = new QPushButton("Confirmer");
  QObject::connect(confirmeOptions, &QPushButton::clicked,
                   [=]()
                   {
                     switchMenuPrincipal();
                   });
  layoutOption->addWidget(confirmeOptions, menu::OPT_SAVE_PLACEMENT[0], menu::OPT_SAVE_PLACEMENT[1]);

  menuOption->setLayout(layoutOption);
}

mainwindow::mainwindow(int argc, char **argv)
    : QMainWindow()
{
  widgets = new QStackedWidget();
  this->showFullScreen();
  /*      Central Widget      */

  createWidgetMenuPrincipal(argc, argv);
  createWidgetMenuOption();

  this->setCentralWidget(widgets);

  this->setWindowIcon(QIcon(QString::fromStdString(config(configKey::PATH_TO_ASSETS)+"pic/aste.ico")));
  QPixmap bkgnd(QString::fromStdString(config(configKey::PATH_TO_ASSETS)+"pic/background.png"));
  QPalette palette;
  palette.setBrush(QPalette::Window, bkgnd);
  this->setPalette(palette);
}
