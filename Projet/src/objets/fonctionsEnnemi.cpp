#include "fonctionsEnnemi.h"
#include "vaisseau.h"

extern Vaisseau * ennemi;
extern Vaisseau * vaisseau;
extern  GLfloat score ;

void deplacementEnnemi(){
    ennemi->moveForward();		
	ennemi->tirer();
	ennemi->setSpeed(1);
	ennemi->setAngle2(2);
	ennemi->setAngle(0);
	glTranslatef(ennemi->posx(), ennemi->posy(), ennemi->posz());
	glRotatef(180 + ennemi->getAngle(),0,1, 0);
	glCallList(5);
}

void ennemiTouche(){
 for (unsigned int i = 0; i< vaisseau->tirs.size();++i){      
    if(abs(ennemi->posx() - vaisseau->tirs.at(i)->posX()) < ennemi->getLargeur() +vaisseau->tirs.at(i)->posX() && vaisseau->tirs.at(i)->getTirActif())
    {
      
      if(abs(ennemi->posy() - vaisseau->posy()) < ennemi->getHauteur() + vaisseau->tirs.at(i)->posY()&& vaisseau->tirs.at(i)->getTirActif())
      {
          
          if(abs(ennemi->posz() - vaisseau->posz()) < ennemi->getLongueur() + vaisseau->tirs.at(i)->posZ()&& vaisseau->tirs.at(i)->getTirActif())
          {
             vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(), vaisseau->getAngle2());
             ennemi->setVie(ennemi->getVie()-10);
             std::cout<<" vie de l' ennemi  : "<<ennemi->getVie();
          }
      }
    } 
   }
   if(ennemi->getVie()<=0)  {
       score +=300;
       delete ennemi;
   }

}