#include <GL/glut.h>
#include <GL/gl.h>

#include "rendu/rendu.h"

#include "fonctions/frontiere.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;
extern bool keyRightPressed;
extern bool keyLeftPressed;

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;

extern GLuint texture[5];

GLvoid VM_init() {
	vaisseau->moveForward();
	vaisseau->tirer();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);

	if(keyUpPressed) vaisseau->setAngle2(-2);
	if(keyDownPressed) vaisseau->setAngle2(2);

	renduCamera(vaisseau);

	for(int i=0; i<5;++i){
		 renduTir(vaisseau->tirs.at(i));
	}

	glPushMatrix();
		glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
		glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
		glRotatef(- vaisseau->getAngle2(), 1, 0, 0);
		glCallList(1);
	glPopMatrix();

	for(unsigned int i=0;i<asteroides.size();++i){
		glPushMatrix();
			
			glTranslatef(asteroides.at(i)->posX(),asteroides.at(i)->posY(),asteroides.at(i)->posZ());
            glRotatef(asteroides.at(i)->getAngle(),1,1,1);
			asteroides.at(i)->moveForward();

			asteroides.at(i)->contactEntreAsteroide();
			
			if(asteroides.at(i)->getTaille()==1){
				glCallList(2);   		
			    glFlush();
			}
			else if(asteroides.at(i)->getTaille()==2){
				glCallList(3);   		
			    glFlush();
			}
			else if(asteroides.at(i)->getTaille()==3){
				glCallList(4);   		
			    glFlush();
			}
			asteroides.at(i)->asteroideTouche();
			if(asteroides.at(i)->getTouche() == true){ 
				asteroides.at(i)->setTouche(false);
				asteroides.at(i)->split();
				i = i-1;
			}
		glPopMatrix();		
	}

	frontieres(texture[0]);
}