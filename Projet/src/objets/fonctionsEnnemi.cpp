#include "fonctionsEnnemi.h"
#include "vaisseau.h"

extern Vaisseau * ennemi;
extern Vaisseau * vaisseau;
extern  GLfloat score ;

void deplacementEnnemi(){
    ennemi->moveForward();		
	ennemi->tirer();
	ennemi->setSpeed(0);
	ennemi->setAngle2(2);
	ennemi->setAngle(0);
    ennemi->setHitbox(7,7,7);
	glTranslatef(ennemi->posx(), ennemi->posy(), ennemi->posz());
	glRotatef(180 + ennemi->getAngle(),0,1, 0);
    
    
	glCallList(5);
}

void ennemiTouche(){ // notre vaisseau touche la soucoupe
 for (unsigned int i = 0; i< vaisseau->tirs.size();++i){      
    if(abs(ennemi->posx() - vaisseau->tirs.at(i)->posX()) < ennemi->getLargeur()  && vaisseau->tirs.at(i)->getTirActif())
    {     
      if(abs(ennemi->posy() - vaisseau->tirs.at(i)->posY()) < ennemi->getHauteur()   && vaisseau->tirs.at(i)->getTirActif())
      {         
          if(abs(ennemi->posz() - vaisseau->tirs.at(i)->posZ()) < ennemi->getLongueur()  && vaisseau->tirs.at(i)->getTirActif())
          {
             vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(), vaisseau->getAngle2());
             ennemi->setVie(ennemi->getVie()-10);
          }
      }
    } 
   }
   if(ennemi->getVie()<=0)  {
       score +=300;
       //delete ennemi;
   }
}



void tirEnnemi(){ // la soucoupe touche le joueur
 for (unsigned int i = 0; i< ennemi->tirs.size();++i){      
    if(abs(vaisseau->posx() - ennemi->tirs.at(i)->posX()) < vaisseau->getLargeur() )
    {     
      if(abs(vaisseau->posy() - ennemi->tirs.at(i)->posY()) < vaisseau->getHauteur() )
      {         
          if(abs(vaisseau->posz() - ennemi->tirs.at(i)->posZ()) < vaisseau->getLongueur())
          {
             ennemi->tirs.at(i)->release(ennemi->posx(),ennemi->posy(),ennemi->posz(),ennemi->getAngle(), ennemi->getAngle2());
             vaisseau->setVie(vaisseau->getVie()-10);             
          }
      }
    } 
   }
 
}