#include "actions.h"
#include<iostream>
extern Vaisseau * vaisseau;

bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

Tir * t ;
bool keyUpPressed = false;
bool keyDownPressed = false;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
      break;
    
    case ESPACE:
        
        vaisseau->tirs[4]->setSpeed(1.5); 
        vaisseau->tirs[4]->setTirActif(true); 
        
        //on decale tous les elements de tirs[] vers la droite ( le vaisseau tire le tirs[4] a chaque fois)           
        t=vaisseau->tirs[4];
        for( int i = 4; i>=0;--i){
          if (i !=0) vaisseau->tirs[i]=vaisseau->tirs[i-1];
          else vaisseau->tirs[i] =t;
        }

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

