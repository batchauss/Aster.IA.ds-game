#include"hud.h"
extern Vaisseau * vaisseau;

GLvoid barreVie(GLfloat vie){
    glPushMatrix();
    	
	    glTranslatef(vaisseau->posx(), vaisseau->posy()+15, vaisseau->posz());
        //glTranslatef(vaisseau->posx()+5, vaisseau->posy(), vaisseau->posz());
        glRotatef(180 +vaisseau->getAngle(), 0, 1, 0);
        
        if(vie>70) glColor3f(0.0,1.0,0.0);
        else if (vie>50) glColor3f(1.0,1.0,0.0);
        else  glColor3f(1.0,0.0,0.0);

		glScalef(vie/10,0.8,0.1);
        glutSolidCube(1);
	glPopMatrix();
}