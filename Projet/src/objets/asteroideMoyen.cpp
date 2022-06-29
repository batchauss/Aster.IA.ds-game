#include "../../includes/constant.h"

#include "asteroideMoyen.h"
#include "asteroidePetit.h"
#include "vaisseau.h"
#include <iostream>

extern std::vector<Asteroide *> asteroides;
extern Vaisseau *vaisseau;
extern GLfloat score;

AsteroideMoyen::AsteroideMoyen(int i) : Asteroide(i)
{
  this->taille = gameconf::MEDIUM_ASTEROID_BASE_SIZE;
  this->rayon_hitbox = gameconf::MEDIUM_ASTEROID_BASE_HITBOX;
}

void AsteroideMoyen::split()
{

  asteroides.erase(asteroides.begin() + this->_id); // on supprime l'asteroide touché

  // split en deux asteroides moyens
  Asteroide *a1 = new AsteroidePetit(asteroides.size());
  a1->setX(this->posX() - gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a1->setY(this->posY() - gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a1->setZ(this->posZ() - gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a1->setAngle(Rand(gameconf::MEDIUM_ASTEROID_MIN_ANGLE, gameconf::MEDIUM_ASTEROID_MAX_ANGLE));
  asteroides.push_back(a1);

  Asteroide *a2 = new AsteroidePetit(asteroides.size());
  a2->setX(this->posX() + gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a2->setY(this->posY() + gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a2->setZ(this->posZ() + gameconf::MEDIUM_ASTEROID_SPLIT_DISTANCE);
  a2->setAngle(Rand(gameconf::MEDIUM_ASTEROID_MIN_ANGLE, gameconf::MEDIUM_ASTEROID_MAX_ANGLE));
  asteroides.push_back(a2);

  for (unsigned int i = 0; i < asteroides.size(); ++i)
  {
    asteroides.at(i)->setId(i);
  }
  delete this;
}

GLvoid AsteroideMoyen::asteroideTouche()
{
  for (unsigned int i = 0; i < vaisseau->tirs.size(); ++i)
  {
    GLfloat longueur = sqrt((vaisseau->tirs.at(i)->posX() - this->posX()) * (vaisseau->tirs.at(i)->posX() - this->posX()) + (vaisseau->tirs.at(i)->posY() - this->posY()) * (vaisseau->tirs.at(i)->posY() - this->posY()) + (vaisseau->tirs.at(i)->posZ() - this->posZ()) * (vaisseau->tirs.at(i)->posZ() - this->posZ()));

    if (longueur <= this->rayon_hitbox and vaisseau->tirs.at(i)->getTirActif())
    {
      vaisseau->tirs.at(i)->release(vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), vaisseau->getAngle(), vaisseau->getAngle2());
      this->touche = true;
      score += gameconf::MEDIUM_ASTEROID_SCORE;
      break;
    }
  }
}