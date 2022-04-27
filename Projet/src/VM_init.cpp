#include <GL/glut.h>
#include <GL/gl.h>
#include "rendu/rendu.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;

Vaisseau * vaisseau = new Vaisseau();

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vaisseau->moveForward();
	vaisseau->tirer();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(3);
	if(dPressed) vaisseau->setAngle(-3);
	if(keyUpPressed) vaisseau->setAngle2(-3);
	if(keyDownPressed) vaisseau->setAngle2(3);
	renduCamera(vaisseau);
	for(int i=0; i<5;++i){
		 renduTir(vaisseau->tirs[i]);
	}
	glPushMatrix();
		glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
		glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
		glRotatef(- vaisseau->getAngle2(), 1, 0, 0);
		glCallList(1);
		glFlush();
	glPopMatrix();
}