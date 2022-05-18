#include "actions.h"
#include<iostream>

extern Vaisseau * vaisseau;
extern std::vector<int> getScores();


bool zPressed = false;
bool qPressed = false;
bool dPressed = false;

bool pauseActivated = false;

Tir * t ;
bool keyUpPressed = false;
bool keyDownPressed = false;
bool keyLeftPressed = false;
bool keyRightPressed = false;

extern int argc;
extern char** argv;

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

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      if(pauseActivated) pauseActivated = false;
      else pauseActivated = true;
      break;
    
    case ESPACE:

        if(!vaisseau->invincible)actionTir(vaisseau);
        getScores();

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


