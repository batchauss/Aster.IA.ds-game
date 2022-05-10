#include"asteroide.h"

extern std::vector <Asteroide *> asteroides;


Asteroide::Asteroide( int i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse=0;
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

GLvoid Asteroide::contactEntreAsteroide(){
  for (unsigned int i = 0; i< asteroides.size();++i){ 
   if(this->_id !=i){
        GLfloat longueur = sqrt( (asteroides.at(i)->posX()-this->posX())*(asteroides.at(i)->posX()-this->posX()) 
                              +(asteroides.at(i)->posY()-this->posY())*(asteroides.at(i)->posY()-this->posY())
                              +(asteroides.at(i)->posZ()-this->posZ())*(asteroides.at(i)->posZ()-this->posZ()));
    
        if(longueur-this->rayon_hitbox <= this->rayon_hitbox ){
             this->setAngle(this->getAngle()+90);
             this->setX(posX()+0.1); this->setY(posY()+0.1); this->setZ(posZ()+0.1);
              
             asteroides.at(i)->setAngle(asteroides.at(i)->getAngle()+90);
             asteroides.at(i)->setX(posX()); asteroides.at(i)->setY(posY()); asteroides.at(i)->setZ(posZ());
             break;  
        }
   }
  }
  

}

Asteroide::~Asteroide(){ }