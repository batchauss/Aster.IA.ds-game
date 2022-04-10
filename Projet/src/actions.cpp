#include "actions.h"

extern Camera * camera;
extern Vaisseau * vaisseau;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
      break;
    
    case TOUCHE_MIN_Z :
      vaisseau->moveForward();
      break;
      
    case TOUCHE_MIN_Q :
      vaisseau->setAngle(5);
      break;

    case TOUCHE_MIN_D :
      vaisseau->setAngle(-5);
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

