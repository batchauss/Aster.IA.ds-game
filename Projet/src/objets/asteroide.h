#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "../init.h"
#include "math.h"
extern GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
extern GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide


class Asteroide {
    
     public :
        Asteroide(int i);
        ~Asteroide();

    //Accesseur sur l'id de l'astéroide
        GLfloat getId(){return this->_id;}

    //Accesseurs sur x,y et z
        GLfloat  posX() const{ return this->_x;}
        GLfloat posY() const{ return this->_y;}
        GLfloat posZ() const{ return this->_z;}

    //Accesseur sur l'angle
        GLfloat getAngle() const{return this->_angle;}

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
                
    private:

        int _id; //id de l'asteroide 

        GLfloat _x;  //coordonnées x,y,z de l'astéroide
        GLfloat _y;
        GLfloat _z;

        GLfloat _angle; // angle de l'astéroide (qui va servir à determiner la direction unique )
        GLfloat vitesse;
        

        


        

};


#endif