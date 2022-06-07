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
    const unsigned int BIG_ASTEROID_SCORE = 20;
    const unsigned int MEDIUM_ASTEROID_SCORE = 50;

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

    // BIG ASTEROID STATS
    const unsigned int BIG_ASTEROID_BASE_SIZE = 3;
    const unsigned int BIG_ASTEROID_BASE_HITBOX = 25;
    const unsigned int BIG_ASTEROID_SPLIT_DISTANCE = 4;
    const unsigned int BIG_ASTEROID_MIN_ANGLE = 1;
    const unsigned int BIG_ASTEROID_MAX_ANGLE = 360;

    // MEDIUM ASTEROID STATS
    const unsigned int MEDIUM_ASTEROID_BASE_SIZE = 2;
    const unsigned int MEDIUM_ASTEROID_BASE_HITBOX = 12;
    const unsigned int MEDIUM_ASTEROID_SPLIT_DISTANCE = 2;
    const unsigned int MEDIUM_ASTEROID_MIN_ANGLE = 1;
    const unsigned int MEDIUM_ASTEROID_MAX_ANGLE = 360;

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