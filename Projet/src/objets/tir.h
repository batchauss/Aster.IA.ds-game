#ifndef TIR_H
#define TIR_H

#include "../init.h"

class Tir {
    public:
        Tir(GLfloat x, GLfloat y , GLfloat z);
        ~Tir();

        GLfloat longueur;

        //accesseurs sur la position du tir
        GLfloat posX(){ return this->pos[0];}
        GLfloat posY(){ return this->pos[1];}
        GLfloat posZ(){ return this->pos[2];}

        //accesseurs sur la position du tir au moment ou espace est pressé
        GLfloat posXmomentTir(){ return this->posMomentTir[0];}
        GLfloat posYmomentTir(){ return this->posMomentTir[1];}
        GLfloat posZmomentTir(){ return this->posMomentTir[2];}    
        
        GLfloat getAngle(){ return this->angleTir[0];}
        GLfloat getAngle2(){ return this->angleTir[1];}
        GLfloat getAngle3(){ return this->angleTir[2];}

        GLfloat getSpeed(){return this->vitesse_tir;}
        GLfloat getTirActif(){return this->tirActif;}

        //modificateurs de position 
        GLvoid setPos(GLfloat x ,GLfloat y,GLfloat z){
             this->pos[0]=x;
             this->pos[1]=y;
             this->pos[2]=z;
        }

        //modificateurs de la position du tir au moment ou ESPACE est pressé
        GLvoid setposXmomentTir(GLfloat x){ this->posMomentTir[0]=x;}
        GLvoid setposYmomentTir(GLfloat y){ this->posMomentTir[1]=y;}
        GLvoid setposZmomentTir(GLfloat z){ this->posMomentTir[2]=z;}

        GLvoid setposmomentTir(GLfloat x,GLfloat y,GLfloat z){ 
            this->posMomentTir[0]=x;
            this->posMomentTir[1]=y;
            this->posMomentTir[2]=z;
        }

        GLvoid setAngle(GLfloat a){ this->angleTir[0]=a;}
        GLvoid setAngle2(GLfloat a){ this->angleTir[1]=a;}
        GLvoid setAngle3(GLfloat a){ this->angleTir[2]=a;}

        //modifie la vitesse du tir
        GLvoid setSpeed(GLfloat v){ this->vitesse_tir=v;}

        GLvoid setTirActif(bool b) { tirActif = b;}

        void move(GLfloat x, GLfloat y, GLfloat z);

    private:
        GLfloat pos[3];
        GLfloat posMomentTir[3]; // position au moment du tir
        GLfloat angleTir[3];
        GLfloat vitesse_tir;
        bool tirActif ;
};

#endif