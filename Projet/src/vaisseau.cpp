#include "vaisseau.h"

Vaisseau::Vaisseau(){
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;
    this->angle = 0;
}

void Vaisseau::modelisation(){
    glPushMatrix();
        glTranslatef(posx(), posy(), posz());
        glRotatef(180 + this->angle, 0, 1, 0);
        glutSolidCone(1, 5, 30, 30);
    glPopMatrix();
}

void Vaisseau::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
    modelisation();
}