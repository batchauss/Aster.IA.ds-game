#include "init.h"
#include "math.h"
extern GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
extern GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide


class Asteroide {
    
     public :
        Asteroide(int i , GLfloat rad, GLfloat sli, GLfloat sta);
        ~Asteroide();
        GLvoid renduAsteroide();

    //Accesseur sur l'id de l'astéroide
        GLfloat getId(){return this->_id;}

    //Accesseurs sur x,y et z
        GLfloat posX(){ return this->_x;}
        GLfloat posY(){ return this->_y;}
        GLfloat posZ(){ return this->_z;}

    //Accesseur sur l'angle
        GLfloat getAng(){return this->_angle;}

    //modifie l'id de l'asteroide
        void setId( int i){ this->_id=i;}

    //modifie les coordonnées x,y,z de l'asteroide    
        void setX(GLfloat x){    this->_x = x;}  
        void setY(GLfloat y){    this->_y = y;}
        void setZ(GLfloat z){    this->_z = z;}
       

        void setAng(GLfloat angle){
            this->_angle=angle;
        }
        

        
    private:

        int _id; //id de l'asteroide 

        GLfloat _x;  //coordonnées x,y,z de l'astéroide
        GLfloat _y;
        GLfloat _z;

        
        GLfloat _radius;
        GLfloat _slide;
        GLfloat _stack;

        GLfloat _angle; // angle de l'astéroide (qui va servir à determiner la direction unique )
        

        


        

};