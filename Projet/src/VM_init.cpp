#include <GL/glut.h>
#include <GL/gl.h>

#include "rendu/rendu.h"
#include "rendu/hud.h"
#include "rendu/decor.h"
#include "touches/actions.h"
#include "rendu/frontiere.h"

extern GLfloat score;

extern bool zPressed;
extern bool qPressed;
extern bool dPressed;
extern bool keyUpPressed;
extern bool keyDownPressed;
extern bool keyRightPressed;
extern bool keyLeftPressed;

int temps_invincible;
extern int tempsDef;

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;
extern Vaisseau * ennemi;

extern GLuint texture[2];

GLfloat angleHeart = 0;
extern GLvoid vieSoucoupe(int i, GLfloat angle);

GLvoid VM_init() {
	vaisseau->moveForward();
	
	if(!vaisseau->invincible)vaisseau->tirer(); //le vaisseau ne tire pas lorsqu'il est invincible
	if(!zPressed) vaisseau->decreaseSpeed();
	if(qPressed) vaisseau->setAngle(2);
	if(dPressed) vaisseau->setAngle(-2);

	if(keyUpPressed) vaisseau->setAngle2(-2);
	if(keyDownPressed) vaisseau->setAngle2(2);

	renduCamera(vaisseau);
	
	for(unsigned int i=0; i<vaisseau->tirs.size();++i){
		if(!vaisseau->invincible) renduTir(1,vaisseau->tirs.at(i));
	}

	glPushMatrix();
		barreVie(vaisseau->getVie());
		glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
		glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
		glRotatef(- vaisseau->getAngle2(), 1, 0, 0);
		
		//transparence du vaisseau quand il est touché
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
				vaisseau->invincible=true;
				temps_invincible = tempsDef - 3000;
				asteroides.at(i)->setTouche(true);
	   		}
			
			if(vaisseau->invincible==false && vaisseau->collisionVaisseauVaisseau(ennemi)){
				if(vaisseau->getVie()>=30 )vaisseau->setVie(vaisseau->getVie()-30);
				else vaisseau->setVie(0);
				vaisseau->invincible=true;
				temps_invincible = tempsDef - 3000;
			}

			if(vaisseau->getVie()==0) {
				exit(1);
			}
			
			glCallList(asteroides.at(i)->getTaille() + 1);   		
			glFlush();

			asteroides.at(i)->asteroideTouche();
			if(asteroides.at(i)->getTouche() == true){ 
				asteroides.at(i)->setTouche(false);
				asteroides.at(i)->split();
				i = i-1;
			}

				//vaisseau invincible pendant 3 seconde apres contact
				if(temps_invincible > tempsDef)  vaisseau->invincible=false;
		glPopMatrix();
	}



  // soucoupe de l'ennemi
  if(tempsDef < 80000 && ennemi->getVie()>0){  //delai de l'apparition de l'ennemi
	glPushMatrix();
	
		vieSoucoupe(ennemi->getVie(), angleHeart++);
		deplacementEnnemi();
	
	glPopMatrix(); 
	ennemiTouche();
  }

  

  frontieres(texture[0]);
  if(vaisseau->getVie()<=30) grille(1.0 ,0.0 ,0.0); // la couleur de la grille deviens rouge si la vie du vaisseau est basse
  else { grille(1.0 , 0.0 ,1.0); }

  afficheScore(score);

  glCallList(9);//decor de planetes hors frontieres
}