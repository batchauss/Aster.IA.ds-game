#include "decor.h"
#include"../fonctions/frames.h"

GLvoid decorPlanetes(){
	glNewList(9, GL_COMPILE_AND_EXECUTE);

	//planete avec anneau
      glPushMatrix();
	    glTranslatef(200,1000,0);
		glScalef(10,10,10);
		//planete
  		glColor3f(1,1,0.5);
		glutSolidSphere(10,20,20);
		//anneau
		glRotatef(40,1,1,1);
		glScalef(1,1,0.1);
		glColor3f(0.5f, 0.35f, 0.05f);
		glutSolidTorus(5,20,20,20);		
      glPopMatrix();

	  //planete anneau bleu
	  glPushMatrix();
		glTranslatef(300,-1000,200);
		glScalef(10,10,10);
		//planete
  		glColor3f(0,0,1);
		glutSolidSphere(10,20,20);
		//anneau
		glRotatef(-30,1,1,1);
		glScalef(1,1,0.1);
		glColor3f(0.5,0.5,0.9);
		glutSolidTorus(5,20,20,20);		
      glPopMatrix();

	  //grosse planete jaune
	  glPushMatrix();
	  	glColor3f(1,0.5,0);
		glTranslatef(1000,300,-200);
		glutSolidSphere(300,20,20);
	  glPopMatrix();

	  glPushMatrix();
	  	glColor3f(1,0,0.5);
		glTranslatef(-1000,400,0);
		glTranslatef(300,-1000,200);
		glutSolidSphere(100,20,20);
	  glPopMatrix();


    glEndList();

}