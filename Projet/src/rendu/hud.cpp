#include "hud.h"

extern bool pauseActivated;

GLvoid barreVie(GLfloat vie){
    if(!pauseActivated){
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
    }
}

GLvoid boutonPause(){
    //Début 2D
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

        glTranslatef(-4, 4, 0);
	    glScalef(0.2, 1 , 1);
        glutSolidCube(1);
        glTranslatef(1.5, 0, 0);
        glutSolidCube(1);
        
    //End 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid timer(){
    glColor3d(0.2,0.6,0.2);
    vBitmapOutput("TEXTE ECRIT EN VERT",GLUT_BITMAP_TIMES_ROMAN_24);
}

void vBitmapOutput(char * string, void *font)
{
        //Début 2D
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glRasterPos2i(10, 10);
	int len;
	len = (int) strlen(string); // Calcule la longueur de la chaîne
	for(int i = 0; i < len; i++) glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
    
    //End 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}