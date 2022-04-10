#include <GL/glut.h>
#include <GL/gl.h>
#include "objets/vaisseau.h"
#include "objets/camera.h"

Vaisseau * vaisseau = new Vaisseau();
Camera * camera = new Camera(vaisseau);

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/*		Caméra		*/
	camera->lookAt();
	vaisseau->modelisation();
}