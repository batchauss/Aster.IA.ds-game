#include "actions.h"
#include<iostream>
extern Vaisseau * vaisseau;

bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

Tir * t ;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
      break;
    
    case ESPACE:
        
        vaisseau->tirs.back()->setSpeed(1.5); 
        vaisseau->tirs.back()->setTirActif(true); 
        std::cout<<vaisseau->tirs.size() << " ";
        
        t=vaisseau->tirs.at(vaisseau->tirs.size()-1);
        vaisseau->tirs.insert(vaisseau->tirs.begin(),t);
        vaisseau->tirs.pop_back();

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

void touche_speciale(int key, int x, int y) 
{
  /*switch(key){

    case GLUT_KEY_UP :
        xrot -= 10.0;
      break;
    
    case GLUT_KEY_DOWN :
    
      xrot += 10.0;
      break;

    case GLUT_KEY_LEFT :
      yrot -= 10.0;
      break;

    case GLUT_KEY_RIGHT :
      yrot += 10.0;
      break;
  }*/
}

