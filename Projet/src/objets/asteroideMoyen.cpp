
#include"asteroideMoyen.h"
#include"asteroidePetit.h"
#include"vaisseau.h"

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;

AsteroideMoyen::AsteroideMoyen( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse =0.5;
    this->taille=2;
    this->rayon_hitbox=5;
}

void AsteroideMoyen::split(){
    Asteroide * a1 =new  AsteroidePetit(asteroides.size()+1);
    a1->setX(this->posX());
	  a1->setY(this->posY());
	  a1->setZ(this->posZ());
	  a1->setAngle(Rand(1,360)); 
    asteroides.push_back(a1);

    Asteroide * a2 =new  AsteroidePetit(asteroides.size()+1);
    a2->setX(this->posX());
	  a2->setY(this->posY());
	  a2->setZ(this->posZ());
	  a2->setAngle(Rand(1,360)); 
    asteroides.erase(asteroides.begin()+_id);
    asteroides.push_back(a2);

    for(int i = _id; i<asteroides.size();++i){
        asteroides.at(i)->setId(i);
      }
}

 bool AsteroideMoyen::asteroideTouche(){
     for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
        GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                                +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                                +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()) );
    
    if(longueur<=this->rayon_hitbox){
      vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(), vaisseau->getAngle2());
;      this->split();
      return false ;
    }
   
   }
    
  }

AsteroideMoyen::~AsteroideMoyen(){ }