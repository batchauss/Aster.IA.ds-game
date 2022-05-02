#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "../init.h"
#include "math.h"


class Asteroide {
    
     public :
        Asteroide(int i);
        ~Asteroide();

    //Accesseur sur l'id de l'astéroide
        GLfloat getId(){return this->_id;}

    //Accesseurs sur x,y et z
        GLfloat  posX() { return this->_x;}
        GLfloat posY() { return this->_y;}
        GLfloat posZ() { return this->_z;}

    //Accesseur sur l'angle
        GLfloat getAngle() {return this->_angle;}

    //Accesseur sur ma taille de l'astéroide
        GLfloat getTaille(){return this->taille;}

    //modifie l'id de l'asteroide
        void setId( int i){ this->_id=i;}

    //modifie les coordonnées x,y,z de l'asteroide    
        void setX(GLfloat x){    this->_x = x;}  
        void setY(GLfloat y){    this->_y = y;}
        void setZ(GLfloat z){    this->_z = z;}
       

        void setAngle(GLfloat angle){
            this->_angle=angle;
        }

        void move(GLfloat x, GLfloat y, GLfloat z);
        void moveForward();

        virtual void split() = 0;
                
    protected:

        int _id; //id de l'asteroide 

        GLfloat _x;  //coordonnées x,y,z de l'astéroide
        GLfloat _y;
        GLfloat _z;

        GLfloat _angle; // angle de l'astéroide (qui va servir à determiner la direction unique )
        GLfloat vitesse;
        GLfloat taille;
        
};

#endif