#pragma once

#include "../init.h"
#include "camera.h"
#include "tir.h"
#include "asteroide.h"
#include <vector>

class Vaisseau {

public : 
    Vaisseau(int nbBalles);
    ~Vaisseau();
    void move(GLfloat x, GLfloat y, GLfloat z);             // Permet d'incrémenter la position du vaisseau par x y z
    

    GLfloat posx(){ return this->pos[0]; }                  // Accesseur sur pos[0] (posx)
    GLfloat posy(){ return this->pos[1]; }                  // Accesseur sur pos[1] (posy)
    GLfloat posz(){ return this->pos[2]; }                  // Accesseur sur pos[2] (posz)
    
    GLfloat getAngle(){ return this->angle[0]; }
    GLfloat getAngle2(){ return this->angle[1]; }

    GLfloat getSpeed(){return this->vitesse;}
    GLfloat getVie(){return this->vie;}

    GLfloat getLongueur(){return this->longueur;}
    GLfloat getLargeur(){return this->largeur;}
    GLfloat getHauteur(){return this->hauteur;}

    std::string getStatut(){return this->statut;}

    void setPos(GLfloat x, GLfloat y, GLfloat z){           // Modifie pos
        this->pos[0] = x;
        this->pos[1] = y;
        this->pos[2] = z;
    }
    void setAngle(GLfloat a);
    void setAngle2(GLfloat a);

    void setVie(GLfloat v){this->vie =v;}
    
    void calculmoveForward();
    void moveForward();
    void decreaseSpeed();
    void setSpeed(GLfloat v){ 
        this->vitesse=v;
    }
    void setHitbox( GLfloat lo, GLfloat la, GLfloat h){
         this->longueur =lo;
         this->largeur=la;
         this->hauteur=h;
    }

    void setStatut(std::string s){this->statut =s;}
    
    GLvoid tirer();

    bool collisionVaisseauAsteroide( Asteroide * a);

    bool collisionVaisseauVaisseau( Vaisseau *v);

    bool invincible;

    Camera * camera;
    std::vector <Tir *> tirs; // tableau de munitions

private :
    GLfloat pos[3]; //position x y z du vaisseau
    GLfloat angle[2]; // angle rotations
    GLfloat vitesse;
    GLfloat longueur;
    GLfloat largeur;
    GLfloat hauteur;
    GLfloat vie;
    std::string statut;
};
