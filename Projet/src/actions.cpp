#include "actions.h"

extern Camera * camera;
extern Vaisseau * vaisseau;

GLfloat calculRotationTranslatex;
GLfloat calculRotationTranslatez;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
      break;
    
    case TOUCHE_MIN_Z :
      calculRotationTranslatex = -0.5 * sin(vaisseau->getAngle() * 3.14 / 180);
      calculRotationTranslatez =  -0.5 * cos(vaisseau->getAngle() * 3.14 / 180);
      vaisseau->move(calculRotationTranslatex, 0, calculRotationTranslatez);
      camera->move(calculRotationTranslatex, 0, calculRotationTranslatez);
      break;
      
    case TOUCHE_MIN_Q :
      vaisseau->setAngle(vaisseau->getAngle() + 5);
      camera->rotation(5);
      break;

    case TOUCHE_MIN_D :
      vaisseau->setAngle(vaisseau->getAngle() - 5);
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

