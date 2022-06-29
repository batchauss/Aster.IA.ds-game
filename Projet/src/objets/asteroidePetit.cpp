#include "../../includes/constant.h"

#include "asteroidePetit.h"
#include <iostream>
#include "vaisseau.h"

extern std::vector<Asteroide *> asteroides;
extern Vaisseau *vaisseau;
extern GLfloat score;

AsteroidePetit::AsteroidePetit(int i) : Asteroide(i)
{
    this->taille = gameconf::SMALL_ASTEROID_BASE_SIZE;
    this->rayon_hitbox = gameconf::SMALL_ASTEROID_BASE_HITBOX;
}

void AsteroidePetit::split()
{
    asteroides.erase(asteroides.begin() + this->_id); // suppression du petit asteroide

    for (unsigned int i = 0; i < asteroides.size(); ++i)
    { // on reassigne l'id des asteroides
        asteroides.at(i)->setId(i);
    }
    delete this;
}

GLvoid AsteroideMoyen::asteroideTouche()
{
  for (auto & tir : vaisseau->tirs)
  {
    auto P2 = []( float a ) { return a * a; };

    GLfloat longueur = sqrt(  P2( tir->posX() - this->posX() )
                     + P2( tir->posY() - this->posY() )
                     + P2( tir->posZ() - this->posZ() ) );

    if (
     (longueur <= this->rayon_hitbox) and (tir->getTirActif())
    ) {
      tir->release(
        vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 
        vaisseau->getAngle(), vaisseau->getAngle2()
      );
      this->touche = true;
      score += gameconf::SMALL_ASTEROID_SCORE;
      break;
    }
  }
}