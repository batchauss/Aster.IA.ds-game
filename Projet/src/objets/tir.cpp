#include"tir.h"

Tir::Tir(GLfloat x, GLfloat y , GLfloat z){
    this->pos[0]=x;
    this->pos[1]=y;
    this->pos[2]=z;
    this->vitesse_tir=0;
}

void Tir::move(GLfloat x, GLfloat y, GLfloat z){ // fait avancer le tir
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;

    //gestion de la frontiere de l'univers
    if (this->pos[0] > 50) this->pos[0] -=100;
    else if (this->pos[0] < -50) this->pos[0] +=100;

    if (this->pos[1] > 50) this->pos[1] -=100;
    else if (this->pos[1] < -50) this->pos[1] +=100;

    if (this->pos[2] > 50) this->pos[2] -=100;
    else if (this->pos[2] < -50) this->pos[2] +=100;
}

Tir::~Tir(){}