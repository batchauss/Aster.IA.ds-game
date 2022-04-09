#include <GL/glut.h>
#include <GL/gl.h>
#include "vaisseau.h"
#include "camera.h"

extern Camera * camera;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/*		Caméra		*/
	camera->lookAt();
}