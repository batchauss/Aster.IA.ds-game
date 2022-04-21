#include "actions.h"

extern Vaisseau * vaisseau;

bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

bool keyUpPressed = false;
bool keyDownPressed = false;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
      break;
    
    case ESPACE:
      vaisseau->tirs->setSpeed(1.5);
      vaisseau->setTirActif(true);
      break;
    
    case TOUCHE_MIN_Z :
      zPressed = true;
      vaisseau->setSpeed(1);
      break;

    case TOUCHE_MIN_Q :
      qPressed = true;
      break;

    case TOUCHE_MIN_D :
      dPressed = true;
      break;
  }
}

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

void toucheSpeciale(int key, int x, int y) 
{
  switch(key){

    case GLUT_KEY_UP :
      keyUpPressed = true;
      break;

    case GLUT_KEY_DOWN :
      keyDownPressed = true;
      break;
  }
}

void releaseToucheSpeciale(int key, int x, int y) 
{
  switch(key){

    case GLUT_KEY_UP :
      keyUpPressed = false;
      break;

    case GLUT_KEY_DOWN :
      keyDownPressed = false;
      break;
  }
}

