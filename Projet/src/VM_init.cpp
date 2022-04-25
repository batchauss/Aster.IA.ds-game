#include <GL/glut.h>
#include <GL/gl.h>
#include "rendu/rendu.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;

Vaisseau * vaisseau = new Vaisseau();

extern struct objmtl v;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	vaisseau->moveForward();
	vaisseau->tirer();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);
	//if(keyUpPressed) vaisseau->setAngle(-2, 0, 0);
	//if(keyDownPressed) vaisseau->setAngle(2, 0, 0);
	renduCamera(vaisseau);
	for(int i=0; i<5;++i){
		 renduTir(vaisseau->tirs[i]);
	}
	renduObjVaisseau(v, vaisseau);
}