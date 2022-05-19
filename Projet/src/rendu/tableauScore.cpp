#include "tableauScore.h"

GLvoid renduPause(){
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    boutonPause();

    glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
            glVertex2f(-1.9, -4.3);
            glVertex2f(1.9, -4.3);
            glVertex2f(1.9, 3.3);
            glVertex2f(-1.9, 3.3);
        glEnd();
        glColor3f(0.4, 0, 0.8);
        glBegin(GL_QUADS);
            glVertex2f(-2, -4.5);
            glVertex2f(2, -4.5);
            glVertex2f(2, 3.5);
            glVertex2f(-2, 3.5);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        
    glPopMatrix();
            
    //End 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

}

GLvoid boutonPause(){
    glPushMatrix();
        glTranslatef(-4, 4, 0);
	    glScalef(0.2, 1, 1);
        glutSolidCube(1);
        glTranslatef(1.5, 0, 0);
        glutSolidCube(1);
    glPopMatrix();
}