#include"asteroideMoyen.h"
#include"asteroidePetit.h"

extern std::vector<Asteroide *> asteroides;

AsteroideMoyen::AsteroideMoyen( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse =0.5;
    this->taille=2;
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
      asteroides.erase(asteroides.begin());
      asteroides.push_back(a2);
}

AsteroideMoyen::~AsteroideMoyen(){ }