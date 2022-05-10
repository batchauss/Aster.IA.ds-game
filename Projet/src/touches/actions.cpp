#include "actions.h"
#include<iostream>

extern Vaisseau * vaisseau;

bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

bool pauseActivated = false;

Tir * t ;
bool keyUpPressed = false;
bool keyDownPressed = false;
bool keyLeftPressed = false;
bool keyRightPressed = false;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      if(pauseActivated) pauseActivated = false;
      else pauseActivated = true;
      break;
    
    case ESPACE:
        
        vaisseau->tirs.back()->setSpeed(1.6); 
        vaisseau->tirs.back()->setTirActif(true);

        vaisseau->tirs.back()->setposXmomentTir(vaisseau->posx());
        vaisseau->tirs.back()->setposYmomentTir(vaisseau->posy());
        vaisseau->tirs.back()->setposZmomentTir(vaisseau->posz()); 

        t=vaisseau->tirs.at(vaisseau->tirs.size()-1);
        vaisseau->tirs.insert(vaisseau->tirs.begin(),t);
        vaisseau->tirs.pop_back();

      break;
    
    case TOUCHE_MIN_Z :
      zPressed = true;
      vaisseau->setSpeed(1.3);
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

    case GLUT_KEY_LEFT :
      keyLeftPressed = true;
      break;

    case GLUT_KEY_RIGHT :
      keyRightPressed = true;
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

    case GLUT_KEY_LEFT :
      keyLeftPressed = false;
      break;

    case GLUT_KEY_RIGHT :
      keyRightPressed = false;
      break;      
  }
}

