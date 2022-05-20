#include "renduFin.h"

GLvoid renduFin(){
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);
    
    //  Ecriture des scores
    glPushMatrix();
        vBitmapOutput(-400, 1200, 0.5, 0.5, "HIGHSCORES", GLUT_STROKE_ROMAN, 5);
        std::vector<std::string> scores = bestScores();
        GLfloat espacementHauteur = 800;
        for(unsigned int i=0; i < scores.size(); i++){
            vBitmapOutput(-500, espacementHauteur, 0.5, 0.5, scores.at(i), GLUT_STROKE_ROMAN, 3);
            espacementHauteur -= 200;
        }
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