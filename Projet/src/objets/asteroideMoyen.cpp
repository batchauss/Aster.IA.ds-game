
#include"asteroideMoyen.h"
#include"asteroidePetit.h"
#include"vaisseau.h"
#include<iostream>

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;

AsteroideMoyen::AsteroideMoyen( int i) :Asteroide(i){
    this->_id=i; 
    this->_x=0;
    this->_y=0;
    this->_z=0;
    this->_angle = 0;  
    this->vitesse =0.05;
    this->taille=2;
    this->rayon_hitbox=5;
}

void AsteroideMoyen::split(){
   std::cout<<"moyen cassé: "<<this->_id<<" ";
   std::cout<<" emplacement: "<<asteroides.at(this->_id)->getId()<<" ";
    asteroides.erase(asteroides.begin()+this->_id); //on supprime l'asteroide touché


     std::cout<<" taille avant split du moyen : "<<asteroides.size();
       Asteroide * a1 =new  AsteroidePetit(asteroides.size()+1);
      a1->setX(this->posX()-2);
	    a1->setY(this->posY()-2);
	    a1->setZ(this->posZ()-2);
	    a1->setAngle(Rand(1,360)); 
      asteroides.push_back(a1);

      Asteroide * a2 =new  AsteroidePetit(asteroides.size()+1);
      a2->setX(this->posX()+2);
	    a2->setY(this->posY()+2);
	    a2->setZ(this->posZ()+2);
	    a2->setAngle(Rand(1,360)); 
      asteroides.push_back(a2);


      for(unsigned int i = 0; i<asteroides.size();++i){
         asteroides.at(i)->setId(i);
     }

   std::cout<<" taille apres split du moyen : "<<asteroides.size()<<std::endl;
  }

 GLvoid AsteroideMoyen::asteroideTouche(){
     for (unsigned int i = 0; i< vaisseau->tirs.size();++i){ 
        GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX()) 
                                +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                                +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()) );
    
    if(longueur<=this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif()){
      vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle());
;      this->split();  // l'asteroide se casse en 2 petits
      break;
    }
   
   }
    
  }

AsteroideMoyen::~AsteroideMoyen(){ }