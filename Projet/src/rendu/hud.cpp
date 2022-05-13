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

GLvoid timer(int tempsRetenu){
    int tempsMax = 60000;

    int tempsPasse = tempsMax - glutGet(GLUT_ELAPSED_TIME);
    int tempsActuel = tempsPasse + tempsRetenu;

    glColor3d(0.2,0.6,0.2);
    std::string tmp = intPadding(tempsActuel);
    vBitmapOutput(-165, 900, tmp, GLUT_STROKE_ROMAN);
}

std::string intPadding(int i){
    if(i <= 0) return "STOP";
    std::string s = std::to_string(i);
    
    if(s.size() == 5){
        s = s.substr(0, 2) + "." + s.substr(2, 2);
    }
    else if(s.size() == 4){
        s = s.substr(0, 1) + '.' + s.substr(1, 2);
    }
    else if(s.size() == 3){
        s = "0." + s.substr(0, 2);
    }
    return s;
}

GLvoid afficheScore(GLfloat score){
    int s = score;
    vBitmapOutput(1000, 900, std::to_string(s), GLUT_STROKE_ROMAN);
}

void vBitmapOutput(GLfloat x, GLfloat y, std::string string, void *font)
{
    //Début 2D
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5);
    glScalef(1/1520.38, 1/1520.38, 1/1520.38);
    glScalef(1.2, 1.4, 1.4);

    glTranslatef(x, y, 0);

	int len;
	len = string.size(); // Calcule la longueur de la chaîne
	for(int i = 0; i < len; i++) glutStrokeCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
    
    //End 2D
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}