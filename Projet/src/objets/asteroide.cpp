#include "../../includes/constant.h"

#include "asteroide.h"

extern std::vector<Asteroide *> asteroides;

Asteroide::Asteroide(int i)
{
    this->_id = i;
    // coordonnées aléatoires dans l'univers au départ
    this->_x = Rand(gameconf::ASTEROID_MIN_RAND_POS, gameconf::ASTEROID_MAX_RAND_POS);
    this->_y = Rand(gameconf::ASTEROID_MIN_RAND_POS, gameconf::ASTEROID_MAX_RAND_POS);
    this->_z = Rand(gameconf::ASTEROID_MIN_RAND_POS, gameconf::ASTEROID_MAX_RAND_POS);
    this->_angle = Rand(gameconf::ASTEROID_MIN_ANGLE, gameconf::ASTEROID_MAX_ANGLE);
    this->vitesse = Rand(gameconf::ASTEROID_MIN_SPEED, gameconf::ASTEROID_MAX_SPEED);
    this->taille = gameconf::ASTEROID_BASE_SIZE;
    this->rayon_hitbox = gameconf::ASTEROID_BASE_HITBOX;
    this->touche = gameconf::ASTEROID_BASE_TOUCH;
}

void Asteroide::move(GLfloat x, GLfloat y, GLfloat z)
{
    this->_x += x;
    this->_y += y;
    this->_z += z;

    // gestion de l'asteroide qui franchit la frontière
    if (posX() > gameconf::POSITIVE_AREA_SIZE)
        _x -= gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;
    else if (posX() < gameconf::NEGATIVE_AREA_SIZE)
        _x += gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;

    if (posY() > gameconf::POSITIVE_AREA_SIZE)
        _y -= gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;
    else if (posY() < gameconf::NEGATIVE_AREA_SIZE)
        _y += gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;

    if (posZ() > gameconf::POSITIVE_AREA_SIZE)
        _z -= gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;
    else if (posZ() < gameconf::NEGATIVE_AREA_SIZE)
        _z += gameconf::ASTEROID_OUT_OF_AREA_RELOCATE;
}

void Asteroide::moveForward()
{
    GLfloat deplacementAstX = -vitesse * sin(getAngle() * M_PI / gameconf::ASTEROID_MOVE_FORWARD_ANGLE);
    GLfloat deplacementAstY = vitesse * cos(getAngle() * M_PI / gameconf::ASTEROID_MOVE_FORWARD_ANGLE);
    GLfloat deplacementAstZ = -vitesse * cos(getAngle() * M_PI / gameconf::ASTEROID_MOVE_FORWARD_ANGLE);

    this->move(deplacementAstX, deplacementAstY, deplacementAstZ);
}

Asteroide::~Asteroide()
{
}