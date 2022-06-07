#include <GL/gl.h>

namespace gameconf
{
    const unsigned int INVINCIBILITY_TIME = 3000;

    // GAME CONFIG
    const unsigned int BASE_SCORE = 0;
    const unsigned int PLAYER_BASE_BULLETS_NUMBER = 10;
    const unsigned int ENEMY_BASE_BULLETS_NUMBER = 5;
    const int BASE_ASTEROIDS_NUMBER = 4;
    const int POSITIVE_AREA_SIZE = 200;
    const int NEGATIVE_AREA_SIZE = -200;
    const unsigned int ASTEROID_OUT_OF_AREA_RELOCATE = 400;

    // ASTEROIDS STATS
    const int ASTEROID_MIN_RAND_POS = -199;
    const unsigned int ASTEROID_MAX_RAND_POS = 199;
    const unsigned int ASTEROID_MIN_ANGLE = 0;
    const unsigned int ASTEROID_MAX_ANGLE = 360;
    const GLfloat ASTEROID_MIN_SPEED = 0.1f;
    const GLfloat ASTEROID_MAX_SPEED = 1.2f;
    const unsigned int ASTEROID_BASE_SIZE = 0;
    const unsigned int ASTEROID_BASE_HITBOX = 0;
    const unsigned int ASTEROID_MOVE_FORWARD_ANGLE = 180;
    const bool ASTEROID_BASE_TOUCH = false;

    // ENNEMY STATS
    const int ENEMY_SPAWN_DELAY = 80000;
    const unsigned int ENEMY_CONTACT_DAMAGE = 30;
    const unsigned int ENEMY_BASE_LIFE = 30;
    const unsigned int ENEMY_MIN_LIFE = 0;
    const int ENEMY_MIN_RAND_POS = -100;
    const unsigned int ENEMY_MAX_RAND_POS = 100;

    // PLAYER STATS
    const unsigned int PLAYER_MIN_LIFE = 30;
    const unsigned int PLAYER_DEAD = 0;

};

namespace playercontrols
{
    const int NEGATIVE_MOVEMENT = -2;
    const unsigned int POSITIVE_MOVEMENT = 2;
};