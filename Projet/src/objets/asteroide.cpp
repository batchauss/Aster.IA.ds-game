#include"asteroide.h"

Asteroide::Asteroide( int i){
    this->_id=i; 
    this->_x=r[i][0];
    this->_y=r[i][1];
    this->_z=r[i][2];
    this->_angle = angle_ast[i];  
    this->vitesse = 0.1; 
}


void Asteroide::move(GLfloat x, GLfloat y, GLfloat z){
    this->_x +=x;
    this->_y +=y;
    this->_z +=z;

    if (_x >=100) _x -= 200;
    else if (_y >=100) _y -= 200;
    else if (_z >=100) _z -= 200;

    else if (_x <=-100) _x += 200;
    else if (_y <=-100) _y += 200;
    else if (_z <=-100) _z += 200;
}

void Asteroide::moveForward(){
    GLfloat deplacementAstX = vitesse  * sin(getAngle() *3.14 /180);
    GLfloat deplacementAstY = vitesse  * cos(getAngle() *3.14 /180);
    GLfloat deplacementAstZ = vitesse  * cos(getAngle() *3.14 /180);

    this->move(deplacementAstX,deplacementAstY,deplacementAstZ);
}

Asteroide::~Asteroide(){ }