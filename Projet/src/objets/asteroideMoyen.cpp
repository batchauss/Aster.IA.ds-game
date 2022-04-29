#include"asteroideMoyen.h"

AsteroideMoyen::AsteroideMoyen( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse =0.5;
}
AsteroideMoyen::~AsteroideMoyen(){ }