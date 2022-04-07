#include <GL/glut.h>
#include <GL/gl.h>

GLfloat xcam = 0;
GLfloat ycam = 0;
GLfloat zcam = -50.0;
GLfloat xrot = 0.0;
GLfloat yrot = 0.0;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(xcam, ycam, zcam, 0, 0, 0, 1, 1, 1);
	//glTranslatef(xcam, ycam, zcam);
	glRotatef(yrot, 0.0, 1.0, 0.0);
	glRotatef(xrot, 1.0, 0.0, 0.0);
}