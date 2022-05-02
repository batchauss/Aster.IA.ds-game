#include "asteroidePetit.h"

extern std::vector<Asteroide *> asteroides;

AsteroidePetit::AsteroidePetit( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 1; 
    this->taille=1;
}

void AsteroidePetit::split(){
    asteroides.erase(asteroides.begin());
}

AsteroidePetit::~AsteroidePetit(){ }