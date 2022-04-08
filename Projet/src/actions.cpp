#include "actions.h"

extern GLfloat xCamRot;
extern GLfloat zCamRot;
extern GLfloat xCamPos;
extern GLfloat yCamPos;
extern GLfloat zCamPos;

extern Vaisseau * vaisseau;
GLfloat calculRotationTranslatex;
GLfloat calculRotationTranslatez;

GLfloat angle = 0;
GLfloat xCam = 0;
GLfloat zCam = 0;

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
      break;
      
    case TOUCHE_MIN_Q :
      angle = 5;

      vaisseau->setAngle(vaisseau->getAngle() + angle);

      xCam = xCamPos - vaisseau->posx();
      zCam = zCamPos - vaisseau->posz();
      xCamRot = xCam * cos(angle * 3.14 / 180) + zCam * sin(angle * 3.14 / 180) + vaisseau->posx();
      zCamRot = - xCam * sin(angle * 3.14 / 180) + zCam * cos(angle * 3.14 / 180) + vaisseau->posz() - 30;

      //std::cout << xCam << " " << zCam << std::endl;

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

