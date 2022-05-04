#include "asteroidePetit.h"

#include"vaisseau.h"

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;

AsteroidePetit::AsteroidePetit( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 0.8; 
    this->taille=1;
    this->rayon_hitbox=2;
}

void AsteroidePetit::split(){
    asteroides.erase(asteroides.begin()+_id);
}

 bool AsteroidePetit::asteroideTouche(){
     for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
        GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                                +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                                +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()) );
    
    if(longueur<=this->rayon_hitbox){
       vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle());
      this->split();
      return false ;
    }
    
  }
 }

AsteroidePetit::~AsteroidePetit(){ }