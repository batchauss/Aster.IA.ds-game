#ifndef TIR_H
#define TIR_H

#include "../init.h"

class Tir {
    public:
        Tir(GLfloat x, GLfloat y , GLfloat z);
        ~Tir();

        //accesseurs sur la position du tir
        GLfloat posX(){ return this->pos[0];}
        GLfloat posY(){ return this->pos[1];}
        GLfloat posZ(){ return this->pos[2];}
        
        GLfloat getAngle(){ return this->angleTir;}
        GLfloat getSpeed(){return this->vitesse_tir;}
        GLfloat getTirActif(){return this->tirActif;}

        //modificateurs de position 
        GLvoid setPos(GLfloat x ,GLfloat y,GLfloat z){
             this->pos[0]=x;
             this->pos[1]=y;
             this->pos[2]=z;
        }

        GLvoid setAngle(GLfloat a){ this->angleTir=a;}

        //modifie la vitesse du tir
        GLvoid setSpeed(GLfloat v){ this->vitesse_tir=v;}

        GLvoid setTirActif(bool b) { tirActif = b;}

        void move(GLfloat x, GLfloat y, GLfloat z);

    private:
        GLfloat pos[3];
        GLfloat angleTir;
        GLfloat vitesse_tir;
         bool tirActif ;
};

#endif