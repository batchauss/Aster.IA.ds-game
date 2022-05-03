#include"tir.h"


Tir::Tir(GLfloat x, GLfloat y , GLfloat z){
    this->pos[0]=x;
    this->pos[1]=y;
    this->pos[2]=z;
    this->vitesse_tir=0;
    this->tirActif = false;
    this->posMomentTir[0]=this->pos[0];
    this->posMomentTir[1]=this->pos[1];
    this->posMomentTir[2]=this->pos[2];
}

void Tir::move(GLfloat x, GLfloat y, GLfloat z){ // fait avancer le tir
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
}

void Tir::release(GLfloat x, GLfloat y, GLfloat z){
    this->setSpeed(0);   
    this->setPos(x,y,z);
    this->setposmomentTir(x,y,z);
    this->setTirActif(false);
    this->setAngle(getAngle());
}

Tir::~Tir(){}