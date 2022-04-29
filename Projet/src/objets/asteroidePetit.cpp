#include "asteroidePetit.h"


AsteroidePetit::AsteroidePetit( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 1; 
}


AsteroidePetit::~AsteroidePetit(){ }