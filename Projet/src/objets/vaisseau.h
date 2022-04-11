#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "../init.h"
#include "camera.h"

class Vaisseau {

public : 
    Vaisseau();
    ~Vaisseau();
    void move(GLfloat x, GLfloat y, GLfloat z);             // Permet d'incrémenter la position du vaisseau par x y z

    GLfloat posx(){ return this->pos[0]; }                  // Accesseur sur pos[0] (posx)
    GLfloat posy(){ return this->pos[1]; }                  // Accesseur sur pos[1] (posy)
    GLfloat posz(){ return this->pos[2]; }                  // Accesseur sur pos[2] (posz)
    GLfloat getAngle(){ return this->angle; }               // Accesseur sur angle
    
    void setPos(GLfloat x, GLfloat y, GLfloat z){           // Modifie pos
        this->pos[0] = x;
        this->pos[1] = y;
        this->pos[2] = z;
    }
    void setAngle(GLfloat angle);                           // Modifie angle
    
    void calculmoveForward();
    void moveForward();
    void decreaseSpeed();
    void setSpeed(GLfloat v){ vitesse = v; }

    Camera * camera;

private :
    GLfloat pos[3]; //position x y z du vaisseau
    GLfloat angle;  //angle du vaisseau
    GLfloat vitesse;
};

#endif 