#include"hud.h"
extern Vaisseau * vaisseau;

GLvoid barreVie(GLfloat vie){

//Début 2D
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

        glTranslatef(0, 0.3, 0);

        if(vie>70) glColor3f(0.0, 1.0, 0.0);
        else if (vie>50) glColor3f(1.0, 1.0, 0.0);
        else  glColor3f(1.0, 0.0, 0.0);

		glScalef(vie/120, 0.05, 0.05);
        glutSolidCube(1);

//End 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glPushMatrix();
}