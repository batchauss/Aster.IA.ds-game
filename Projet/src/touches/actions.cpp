#include "actions.h"
#include<iostream>

extern Vaisseau * vaisseau;

bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

bool pauseActivated = false;
bool finActivated = false;

Tir * t ;
bool keyUpPressed = false;
bool keyDownPressed = false;
bool keyLeftPressed = false;
bool keyRightPressed = false;

extern int argc;
extern char** argv;

extern void reinitialisation();

void actionTir( Vaisseau *v){
  v->tirs.back()->setSpeed(2.6);
        v->tirs.back()->setTirActif(true);

        v->tirs.back()->setposXmomentTir(v->posx());
        v->tirs.back()->setposYmomentTir(v->posy());
        v->tirs.back()->setposZmomentTir(v->posz());

        t=v->tirs.at(v->tirs.size()-1);
        v->tirs.insert(v->tirs.begin(),t);
        v->tirs.pop_back();
}

// /!\ x & y unused but required for the glut signature
void touche(unsigned char key, int x, int y)
{
  switch(key){
    case ESCAPE :
      if(pauseActivated) pauseActivated = false;
      else pauseActivated = true;
      break;

    case ESPACE:
        if(!vaisseau->invincible)actionTir(vaisseau);
      break;

    case TOUCHE_MIN_Z :
      zPressed = true;
      vaisseau->setSpeed(2);
      break;

    case TOUCHE_MIN_Q :
      qPressed = true;
      break;

    case TOUCHE_MIN_D :
      dPressed = true;
      break;

    case TOUCHE_MIN_R :
      if(pauseActivated || finActivated){
        pauseActivated = false;
        finActivated = false;
        reinitialisation();
      }
      break;

    case TOUCHE_MIN_L :
      if(pauseActivated || finActivated){
        exit(1);
      }
      break;
  }
}

// /!\ x & y unused but required for the glut signature
void releaseTouche(unsigned char key, int x, int y){
  switch(key){
    case TOUCHE_MIN_Z :
      zPressed = false;
      break;

    case TOUCHE_MIN_Q :
      qPressed = false;
      break;

    case TOUCHE_MIN_D :
      dPressed = false;
      break;

  }
}

// /!\ x & y unused but required for the glut signature
void toucheSpeciale(int key, int x, int y)
{
  switch(key){

    case GLUT_KEY_UP :
      keyUpPressed = true;
      break;

    case GLUT_KEY_DOWN :
      keyDownPressed = true;
      break;

    case GLUT_KEY_LEFT :
      keyLeftPressed = true;
      break;

    case GLUT_KEY_RIGHT :
      keyRightPressed = true;
      break;
  }
}

// /!\ x & y unused but required for the glut signature
void releaseToucheSpeciale(int key, int x, int y)
{
  switch(key){

    case GLUT_KEY_UP :
      keyUpPressed = false;
      break;

    case GLUT_KEY_DOWN :
      keyDownPressed = false;
      break;

    case GLUT_KEY_LEFT :
      keyLeftPressed = false;
      break;

    case GLUT_KEY_RIGHT :
      keyRightPressed = false;
      break;
  }
}
