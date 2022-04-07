#include "init.h"
#include "math.h"
extern GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
extern GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide


class Asteroide {
    
     public :
        Asteroide(int i , GLfloat rad, GLfloat sli, GLfloat sta);
        ~Asteroide();
        GLvoid renduAsteroide();

        GLfloat getId(){return this->_id;}

        GLfloat posX(){ return this->_x;}
        GLfloat posY(){ return this->_y;}
        GLfloat posZ(){ return this->_z;}

        GLfloat getAng(){return this->_angle;}

        void setId( int i){ this->_id=i;}

        
        void setX(GLfloat x){    this->_x = x;}
        void setY(GLfloat y){    this->_y = y;}
        void setZ(GLfloat z){    this->_z = z;}
       

        void setAng(GLfloat angle){
            this->_angle=angle;
        }
        

        
    private:

        int _id;

        GLfloat _x;
        GLfloat _y;
        GLfloat _z;

        
        GLfloat _radius;
        GLfloat _slide;
        GLfloat _stack;

        GLfloat _angle; 
        //GLfloat random_coord[3]; // tableau de coordonnées aléatoires pour les astéroides

        


        

};