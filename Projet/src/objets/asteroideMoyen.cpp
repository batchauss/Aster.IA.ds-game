
#include"asteroideMoyen.h"
#include"asteroidePetit.h"
#include"vaisseau.h"
#include<iostream>

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;
extern  GLfloat score ;

AsteroideMoyen::AsteroideMoyen( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse =0.6;
    this->taille=2;
    this->rayon_hitbox=12;
}

void AsteroideMoyen::split(){

    asteroides.erase(asteroides.begin()+this->_id); //on supprime l'asteroide touché

    //split en deux asteroides moyens
       Asteroide * a1 =new  AsteroidePetit(asteroides.size());
      a1->setX(this->posX()-2);
	    a1->setY(this->posY()-2);
	    a1->setZ(this->posZ()-2);
	    a1->setAngle(Rand(1,360)); 
      asteroides.push_back(a1);

      Asteroide * a2 =new  AsteroidePetit(asteroides.size());
      a2->setX(this->posX()+2);
	    a2->setY(this->posY()+2);
	    a2->setZ(this->posZ()+2);
	    a2->setAngle(Rand(1,360)); 
      asteroides.push_back(a2);

      for(unsigned int i = 0; i<asteroides.size();++i){
         asteroides.at(i)->setId(i);
     }
  }

 GLvoid AsteroideMoyen::asteroideTouche(){
     for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
        GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                                +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                                +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()) );
    
    if(longueur<=this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif()){
      vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(),vaisseau->getAngle2());
      this->touche =true;
      score +=50;
      std::cout<<score <<" points "<<std::endl;
      break;
    }
   
   }
    
  }

AsteroideMoyen::~AsteroideMoyen(){ }