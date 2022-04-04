#include <GL/glut.h>
#include <GL/gl.h>

GLfloat xcam = 0;
GLfloat ycam = 0;
GLfloat zcam = -6;
GLfloat xrot = 0.0;
GLfloat yrot = 10.0;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xcam, ycam, zcam);
	glRotatef(xrot, 0.0, 1.0, 0.0);
	glRotatef(yrot, 1.0, 0.0, 0.0);
}