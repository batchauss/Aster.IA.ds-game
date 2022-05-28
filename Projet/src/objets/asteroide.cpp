#include"asteroide.h"

extern std::vector <Asteroide *> asteroides;


Asteroide::Asteroide( int i){
    this->_id=i; 
    //coordonnées aléatoires dans l'univers au départ
    this->_x=Rand(-199,199);
    this->_y=Rand(-199,199);
    this->_z=Rand(-199,199);
    this->_angle = Rand(0,360);  
    this->vitesse=Rand(0.1,1.2);
    this->taille=0;
    this->rayon_hitbox=0;
    this->touche = false;
}


void Asteroide::move(GLfloat x, GLfloat y, GLfloat z){
    this->_x +=x;
    this->_y +=y;
    this->_z +=z;

    // gestion de l'asteroide qui franchit la frontière 
    if (posX() >200) _x -= 400;
    else if (posX() <-200) _x += 400;

    if (posY()>200) _y -= 400;
    else if (posY() <-200) _y += 400;
    
    if (posZ() >200) _z -= 400;
    else if (posZ() <-200) _z += 400;
}

void Asteroide::moveForward(){
    GLfloat deplacementAstX = -vitesse  * sin(getAngle() *3.14 /180);
    GLfloat deplacementAstY = vitesse  * cos(getAngle() *3.14 /180);
    GLfloat deplacementAstZ = -vitesse  * cos(getAngle() *3.14 /180);

    this->move(deplacementAstX,deplacementAstY,deplacementAstZ);
}

Asteroide::~Asteroide(){
 }