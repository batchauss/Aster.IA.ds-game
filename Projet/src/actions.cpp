#include "actions.h"

extern GLfloat xrot;
extern GLfloat yrot; 

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
  }
}

void touche_speciale(int key, int x, int y) 
{
  switch(key){

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
  }
}

