#include "asteroideGrand.h"
#include "asteroideMoyen.h"
#include "vaisseau.h"
#include<iostream>

extern std::vector<Asteroide *> asteroides;
extern Vaisseau * vaisseau;
extern  GLfloat score ;

AsteroideGrand::AsteroideGrand( int i) :Asteroide(i){
    this->taille=3;
    this->rayon_hitbox=25;
}

  void AsteroideGrand::split() { // l'astéroide se sépare en deux quand il est touché

      asteroides.erase(asteroides.begin()+this->_id); //on supprime l'asteroide touché

      Asteroide * a1 =new  AsteroideMoyen(asteroides.size());
      a1->setX(this->posX()-4);
	    a1->setY(this->posY()-4);
	    a1->setZ(this->posZ()-4);
	    a1->setAngle(Rand(1,360));
      asteroides.push_back(a1);

      Asteroide * a2 =new  AsteroideMoyen(asteroides.size());
      a2->setX(this->posX()+4);
	    a2->setY(this->posY()+4);
	    a2->setZ(this->posZ()+4);
	    a2->setAngle(Rand(1,360));
      asteroides.push_back(a2);

      for(unsigned int i = 0; i<asteroides.size();++i){
        asteroides.at(i)->setId(i);
      }
      delete this;
  }


GLvoid AsteroideGrand::asteroideTouche(){
  for (unsigned int i = 0; i< vaisseau->tirs.size();++i){
    GLfloat longueur = sqrt( (vaisseau->tirs.at(i)->posX()-this->posX())*(vaisseau->tirs.at(i)->posX()-this->posX())
                            +(vaisseau->tirs.at(i)->posY()-this->posY())*(vaisseau->tirs.at(i)->posY()-this->posY())
                            +(vaisseau->tirs.at(i)->posZ()-this->posZ())*(vaisseau->tirs.at(i)->posZ()-this->posZ()));

    if(longueur <= this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif()){
      vaisseau->tirs.at(i)->release(vaisseau->posx(),vaisseau->posy(),vaisseau->posz(),vaisseau->getAngle(), vaisseau->getAngle2());
      this->touche =true;
      score +=20;
      break;
    }
  }
}
