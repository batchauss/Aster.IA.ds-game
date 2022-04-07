#include <GL/glut.h>
#include <GL/gl.h>
#include "vaisseau.h"

GLfloat xcam = 0;
GLfloat ycam = 0;
GLfloat zcam = 30.0;
GLfloat xrot = 0.0;
GLfloat yrot = 0.0;

extern Vaisseau * vaisseau;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/*		Caméra		*/
	GLfloat VaisseauPos[3] = {vaisseau->posx(), vaisseau->posy(), vaisseau->posz()};

	gluLookAt(VaisseauPos[0], VaisseauPos[1] + 10, VaisseauPos[2] + 30, VaisseauPos[0], VaisseauPos[1], VaisseauPos[2], 0, 1, 0);
}