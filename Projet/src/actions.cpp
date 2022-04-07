#include "actions.h"

extern GLfloat xcam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

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
      calculRotationTranslatex = -0.4 * sin(vaisseau->getAngle() * 3.14 / 180);
      calculRotationTranslatez =  -0.4 * cos(vaisseau->getAngle() * 3.14 / 180);
      vaisseau->move(calculRotationTranslatex, 0, calculRotationTranslatez);
      xcam += -calculRotationTranslatex;
      zcam += -calculRotationTranslatez;
      break;
    case TOUCHE_MIN_Q :
      vaisseau->setAngle(vaisseau->getAngle() + 5);
      //xrot -= 5;
      break;
    case TOUCHE_MIN_D :
      vaisseau->setAngle(vaisseau->getAngle() - 5);
      //xrot += 5;
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

