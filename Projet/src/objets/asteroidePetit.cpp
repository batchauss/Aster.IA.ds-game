#include "asteroidePetit.h"
#include<iostream>
#include"vaisseau.h"

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;
extern  GLfloat score ;

AsteroidePetit::AsteroidePetit( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 0.8; 
    this->taille=1;
    this->rayon_hitbox=5;
}

void AsteroidePetit::split(){
    asteroides.erase(asteroides.begin()+this->_id); // suppression du petit asteroide
    
    for(unsigned int i = 0; i<asteroides.size();++i){ // on reassigne l'id des asteroides
        asteroides.at(i)->setId(i);
    }
}

 GLvoid AsteroidePetit::asteroideTouche(){
    for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
        GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                                +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                                +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()) );
    
    if(longueur<=this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif()){
       vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(), vaisseau->getAngle2());
      this->touche =true;
      score +=100;
      break;
    }
    
  }
 }

AsteroidePetit::~AsteroidePetit(){ }