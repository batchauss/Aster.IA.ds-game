#include <GL/glut.h>
#include <GL/gl.h>

#include "rendu/rendu.h"
#include "rendu/hud.h"
#include "touches/actions.h"
#include "fonctions/frontiere.h"
#include "fonctions/frames.h"

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;
extern bool keyRightPressed;
extern bool keyLeftPressed;

int temps_precedent =0;
int temps_invincible;

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;
extern Vaisseau * ennemi;

extern GLuint texture[2];

GLvoid VM_init() {
	vaisseau->moveForward();
	vaisseau->tirer();
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);

	if(keyUpPressed) vaisseau->setAngle2(-2);
	if(keyDownPressed) vaisseau->setAngle2(2);

	renduCamera(vaisseau);
	

	for(unsigned int i=0; i<vaisseau->tirs.size();++i){
		 renduTir(vaisseau->tirs.at(i));
	}

	glPushMatrix();
		barreVie(vaisseau->getVie());
		glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
		glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
		glRotatef(- vaisseau->getAngle2(), 1, 0, 0);
		if(vaisseau->invincible ==true) glCallList(6);
		else glCallList(1);
	glPopMatrix();

 
	for(unsigned int i=0;i<asteroides.size();++i){
		glPushMatrix();			
			glTranslatef(asteroides.at(i)->posX(),asteroides.at(i)->posY(),asteroides.at(i)->posZ());
            glRotatef(asteroides.at(i)->getAngle(),1,1,1);
			asteroides.at(i)->moveForward();
			
			//contact entre le vaisseau et un asteroide
			if(vaisseau->invincible==false && vaisseau->collisionVaisseauAsteroide(asteroides.at(i))  ){
				std::cout<<"vaisseau touché, vie :"<<vaisseau->getVie()<<std::endl;
				vaisseau->invincible=true;
				temps_invincible = (int)temps_acceleration_reelle(1) +3;
	   		}
			//invincible pendant 3 seconde apres contact
			if(temps_invincible == (int)temps_acceleration_reelle(1))  vaisseau->invincible=false;

			   
			
			if(vaisseau->collisionVaisseauVaisseau(ennemi)){
				vaisseau->setVie(vaisseau->getVie()-20);
			}

			if(vaisseau->getVie()==0) {
				std::cout<<"vous avez perdu"<<std::endl;
				exit(1);
			}
			
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

  // soucoupe de l'ennemi
  if(temps_acceleration_reelle(1)>5 && ennemi->getVie()!=0){
	glPushMatrix();
		ennemi->moveForward();
		
		ennemi->tirer();
		ennemi->setSpeed(1);
		ennemi->setAngle2(2);
		ennemi->setAngle(0);
		glTranslatef(ennemi->posx(), ennemi->posy(), ennemi->posz());
		glRotatef(180 + ennemi->getAngle(),0,1, 0);
		glCallList(5);
		//l'ennemi tire deux ballles par secondes
		if((int)temps_acceleration_reelle(2)%1==0 &&(int)temps_acceleration_reelle(1) !=temps_precedent){
			actionTir(ennemi);
			temps_precedent=(int)temps_acceleration_reelle(1);
		}
		for(unsigned int i=0; i<ennemi->tirs.size();++i){
		 renduTir(ennemi->tirs.at(i));
	}
	glPopMatrix();
  }
  

	frontieres(texture[0]);
	if(vaisseau->getVie()<=30) grille(1.0 ,0.0 ,0.0); // la couleur de la grille deviens rouge si la vie du vaisseau est basse
	else  grille(1.0 ,0.0 ,1.0);

	
}