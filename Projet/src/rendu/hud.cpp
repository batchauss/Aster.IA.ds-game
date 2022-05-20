#include "hud.h"

extern bool pauseActivated;
extern GLuint texture[2];
extern std::string pseudonyme;

int tempsDef;

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
    glDisable(GL_LIGHTING);

        glPushMatrix();
            GLfloat posx, posy;
            switch(pseudonyme.size()){
                case 10: posx = -350; break;
                case 9: posx = -320; break;
                case 8: posx = -280; break;
                case 7: posx = -250; break;
                case 6: posx = -220; break;
                case 5: posx = -190; break;
                case 4: posx = -160; break;
                case 3: posx = -130; break;
                case 2: posx = -90; break;
                case 1: posx = -50; break;
            }
            vBitmapOutput(posx, 300, 0.3, 0.3, pseudonyme, GLUT_STROKE_ROMAN, 3);
        glPopMatrix();

        glTranslatef(0, 0.3, 0);

        if(vie>70) glColor3f(0.0, 1.0, 0.0);
        else if (vie>50) glColor3f(1.0, 1.0, 0.0);
        else  glColor3f(1.0, 0.0, 0.0);

		glScalef(vie / 120, 0.05, 0.05);
        glutSolidCube(1);

    //End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    }
}

GLvoid timer(int tempsRetenu){
    int tempsMax = 100000;

    int tempsPasse = tempsMax - glutGet(GLUT_ELAPSED_TIME);
    int tempsActuel = tempsPasse + tempsRetenu;

    tempsDef = tempsActuel;

    glColor3f(0.2,0.6,0.2);
    std::string tmp = intPadding(tempsActuel);
    vBitmapOutput(-165, 900, 1, 1, tmp, GLUT_STROKE_ROMAN, 4);
}

std::string intPadding(int i){
    if(i <= 0) return "STOP";
    std::string s = std::to_string(i);
    
    if(s.size() == 6)      s = s.substr(0, 3) + "." + s.substr(3, 1);
    else if(s.size() == 5) s = s.substr(0, 2) + "." + s.substr(2, 2);
    else if(s.size() == 4) s = s.substr(0, 1) + '.' + s.substr(1, 2);
    else if(s.size() == 3) s = "0." + s.substr(0, 2);

    return s;
}

GLvoid afficheScore(GLfloat score){
    int s = score;
    vBitmapOutput(780, 900, 1, 1, std::to_string(s)+"pts", GLUT_STROKE_ROMAN, 5);
}

void vBitmapOutput(GLfloat x, GLfloat y, GLfloat scalex, GLfloat scaley, std::string string, void *font, GLfloat lineWidth)
{
    //Début 2D
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(lineWidth);
    glScalef(1/1520.38, 1/1520.38, 1/1520.38);
    glScalef(1.2, 1.4, 1);
    glScalef(scalex, scaley, 1);

    glTranslatef(x, y, 0);

	int len;
	len = string.size(); // Calcule la longueur de la chaîne
	for(int i = 0; i < len; i++) glutStrokeCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
    
    //End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid decoHUD(){
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    glColor3f(0.4, 0, 0.8);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-4.8, -4.8);
        glVertex2f(4.8, -4.8);
        glVertex2f(4.8, 3.85);
        glVertex2f(5, 3.85);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(2.8, 5);
        glVertex2f(2.8, 4.8);
        glVertex2f(1, 4.8);
        glVertex2f(0.8, 3.85);
        glVertex2f(-0.8, 3.85);
        glVertex2f(-1, 4.8);
        glVertex2f(-4.8, 4.8);
        glVertex2f(-4.8, -4.8);
    glEnd();

    //End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid vieSoucoupe(int vie, GLfloat angle){
    glMatrixMode (GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(4.5, 1, 0);
    glPushMatrix();
        glTranslatef(0, 1, 0);
        glScalef(0.1, 0.1, 0.1);
        glScalef(0.2, 0.4, 0.2);
        glCallList(5);
    glPopMatrix();
    glRotatef(angle, 0, 1, 0);
    glPushMatrix();
        glCallList(8);
    glPopMatrix();

    if(vie > 10) {
        glPushMatrix();
            glTranslatef(0, -1, 0);
            glCallList(8);
        glPopMatrix();
        if(vie == 30) {
            glPushMatrix();
                glTranslatef(0, -2, 0);
                glCallList(8);
            glPopMatrix();
        }
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}