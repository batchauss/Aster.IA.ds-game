#include "asteroideGrand.h"
#include "asteroideMoyen.h"

extern std::vector<Asteroide *> asteroides;

AsteroideGrand::AsteroideGrand( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 0.1;
    this->taille=3; 
}

  void AsteroideGrand::split() { // l'astéroide se sépare en deux quand il est touché

      Asteroide * a1 =new  AsteroideMoyen(asteroides.size()+1);
      a1->setX(this->posX());
	  a1->setY(this->posY());
	  a1->setZ(this->posZ());
	  a1->setAngle(Rand(1,360)); 
      asteroides.push_back(a1);

      Asteroide * a2 =new  AsteroideMoyen(asteroides.size()+1);
      a2->setX(this->posX());
	  a2->setY(this->posY());
	  a2->setZ(this->posZ());
	  a2->setAngle(Rand(1,360)); 
      asteroides.erase(asteroides.begin());
      asteroides.push_back(a2);

  }

AsteroideGrand::~AsteroideGrand(){ }