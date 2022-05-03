#include"asteroide.h"


Asteroide::Asteroide( int i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse=0;
    this->taille=0;
    this->rayon_hitbox=0;
}


void Asteroide::move(GLfloat x, GLfloat y, GLfloat z){
    this->_x +=x;
    this->_y +=y;
    this->_z +=z;


    if (posX() >100) _x -= 200;
    else if (posX() <-100) _x += 200;

    if (posY()>100) _y -= 200;
    else if (posY() <-100) _y += 200;
    
    if (posZ() >100) _z -= 200;
    else if (posZ() <-100) _z += 200;
}

void Asteroide::moveForward(){
    GLfloat deplacementAstX = -vitesse  * sin(getAngle() *3.14 /180);
    GLfloat deplacementAstY = vitesse  * cos(getAngle() *3.14 /180);
    GLfloat deplacementAstZ = -vitesse  * cos(getAngle() *3.14 /180);

    this->move(deplacementAstX,deplacementAstY,deplacementAstZ);
}

Asteroide::~Asteroide(){ }