#include "asteroideGrand.h"
#include "asteroideMoyen.h"
#include "vaisseau.h"
#include<iostream>

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;

AsteroideGrand::AsteroideGrand( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse = 0.1;
    this->taille=3; 
    this->rayon_hitbox=10;
}

  void AsteroideGrand::split() { // l'astéroide se sépare en deux quand il est touché
      std::cout<<"gros cassé: "<<this->_id<<" ";
      std::cout<<" emplacement: "<<asteroides.at(this->_id)->getId()<<" ";
      asteroides.erase(asteroides.begin()+this->_id); //on supprime l'asteroide touché
      std::cout<<" taille avant split : "<<asteroides.size();
      

      Asteroide * a1 =new  AsteroideMoyen(asteroides.size()+1);
      a1->setX(this->posX()-4);
	    a1->setY(this->posY()-4);
	    a1->setZ(this->posZ()-4);
	    a1->setAngle(Rand(1,360)); 
      asteroides.push_back(a1);


      Asteroide * a2 =new  AsteroideMoyen(asteroides.size()+1);
      a2->setX(this->posX()+4);
	    a2->setY(this->posY()+4);
	    a2->setZ(this->posZ()+4);
	    a2->setAngle(Rand(1,360)); 
      asteroides.push_back(a2);

      for(unsigned int i = 0; i<asteroides.size();++i){
        asteroides.at(i)->setId(i);
      }

   std::cout<<" taille apres split du gros : "<<asteroides.size()<<std::endl;
  }


GLvoid AsteroideGrand::asteroideTouche(){
  for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
    GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                            +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                            +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()));
    
    if(longueur <= this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif()){
      vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle());
      this->split(); // le gros asteroide se casse en 2 moyens
      break;  
    }
  }
}

AsteroideGrand::~AsteroideGrand(){ }