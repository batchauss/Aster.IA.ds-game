#include <GL/glut.h>
#include <GL/gl.h>
#include "vaisseau.h"
#include "camera.h"

extern Vaisseau * vaisseau;
extern Camera * camera;

GLfloat xCamRot = 0.0;
GLfloat zCamRot = 0.0;
GLfloat xCamPos;
GLfloat yCamPos;
GLfloat zCamPos;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/*		Caméra		*/
	xCamPos = vaisseau->posx() + xCamRot;
	yCamPos = vaisseau->posy() + 10;
	zCamPos = vaisseau->posz() + 30 + zCamRot;

	gluLookAt(xCamPos, yCamPos, zCamPos, vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}