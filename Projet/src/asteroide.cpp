#include"asteroide.h"
extern float vitesse_reelle;

Asteroide::Asteroide(GLfloat x, GLfloat y, GLfloat z, GLfloat rad, GLfloat sli, GLfloat sta){
    this->_x=x;
    this->_y=y;
    this->_z=z;
    this->_radius=rad;
    this->_slide=sli;
    this->_stack=sta;
    this->_angle = (float)((float)rand() * (360+1) / (RAND_MAX-1));
}

GLvoid Asteroide::renduAsteroide(){
   glPushMatrix();
   {
    glColor3f(0.5,0.5,0.5);
    glTranslatef(_x,_y,_z);

    
    glutSolidSphere(_radius,_slide,_stack);
   }
   glPopMatrix();
}

 Asteroide::~Asteroide(){ }