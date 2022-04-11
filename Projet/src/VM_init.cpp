#include <GL/glut.h>
#include <GL/gl.h>
#include "rendu/rendu.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;

Vaisseau * vaisseau = new Vaisseau();

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vaisseau->moveForward();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);
	renduCamera(vaisseau);
	renduVaisseau(vaisseau);
}
