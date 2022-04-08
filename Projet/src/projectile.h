#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "init.h"

class Projectile {
public:
    Projectile(GLfloat pos[3]);     // Prends en paramètre dans la construction la position du vaisseau
    ~Projectile();
    
    void modelisation();            // Modélisation du projectile

private:
    GLfloat pos[3];                 // Position du projectile
};

#endif 