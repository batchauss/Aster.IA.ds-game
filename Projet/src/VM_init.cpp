#include <GL/glut.h>
#include <GL/gl.h>
#include "rendu/rendu.h"

Vaisseau * vaisseau = new Vaisseau();

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	renduCamera(vaisseau);
	renduVaisseau(vaisseau);
}