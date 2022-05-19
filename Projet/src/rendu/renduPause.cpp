#include "renduPause.h"

GLvoid renduPause(){
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    boutonPause();
    
    //  Ecriture des scores
    glPushMatrix();
        vBitmapOutput(-900, 1200, 0.5, 0.5, "HIGHSCORES", GLUT_STROKE_ROMAN, 5);
        std::vector<std::string> scores = bestScores();
        GLfloat espacementHauteur = 800;
        for(unsigned int i=0; i < scores.size(); i++){
            vBitmapOutput(-900, espacementHauteur, 0.5, 0.5, scores.at(i), GLUT_STROKE_ROMAN, 3);
            espacementHauteur -= 200;
        }
    glPopMatrix();

    //  Séparation ligne blanche
    glColor3f(0.4, 0, 0.8);
    glPushMatrix();
        glBegin(GL_LINE_STRIP);
            glVertex2f(0.6, 3);
            glVertex2f(0.6, -1);
        glEnd();
    glPopMatrix();

    //  Affichage "boutons"
    glColor3f(1, 1, 1);
    vBitmapOutput(-1200, -1300, 0.3, 0.5, " Rejouer", GLUT_STROKE_ROMAN, 3);
    vBitmapOutput(-1200, -1450, 0.3, 0.5, "Touche R", GLUT_STROKE_ROMAN, 3);
    vBitmapOutput(700, -1300, 0.3, 0.5, " Quitter", GLUT_STROKE_ROMAN, 3);
    vBitmapOutput(700, -1450, 0.3, 0.5, "Touche L", GLUT_STROKE_ROMAN, 3);

    //  Fenêtre
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
            
    //End 2D
    glEnable(GL_LIGHTING);
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