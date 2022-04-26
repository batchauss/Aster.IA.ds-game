#include <GL/glut.h>
#include <GL/gl.h>
#include "rendu/rendu.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;
extern bool keyRightPressed;
extern bool keyLeftPressed;

Vaisseau * vaisseau = new Vaisseau();

extern struct obj v;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vaisseau->moveForward();
	vaisseau->tirer();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);

	if(keyUpPressed) vaisseau->setAngle2(-2);
	if(keyDownPressed) vaisseau->setAngle2(2);
	if(keyRightPressed) vaisseau->setAngle3(-2);
	if(keyLeftPressed) vaisseau->setAngle3(2);
	renduCamera(vaisseau);
	for(int i=0; i<5;++i){
		 renduTir(vaisseau->tirs.at(i));
	}
	renduObjVaisseau(v, vaisseau);
}
