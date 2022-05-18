#include "decor.h"

GLvoid decorPlanetes(){
      glPushMatrix();
	    glTranslatef(0,400,0);
		//planete
  		glColor3f(1,1,0.5);
		glutSolidSphere(10,20,20);
		//anneau
		glRotatef(40,1,1,1);
		glScalef(1,1,0.1);
		glColor3f(0.5f, 0.35f, 0.05f);
		glutSolidTorus(5,20,20,20);		
  glPopMatrix();
}