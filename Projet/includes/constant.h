#include <GL/gl.h>
#include "math.h"

namespace gameconf
{
    const unsigned int INVINCIBILITY_TIME = 3000;

    const GLfloat DEG2RAD = M_PI / 180;

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
    const unsigned int SMALL_ASTEROID_SCORE = 100;

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
    const unsigned int ASTEROID_CONTACT_DAMAGE = 10;

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

    // SMALL ASTEROID STATS
    const unsigned int SMALL_ASTEROID_BASE_SIZE = 1;
    const unsigned int SMALL_ASTEROID_BASE_HITBOX = 5;

    // ENNEMY STATS
    const int ENEMY_SPAWN_DELAY = 80000;
    const unsigned int ENEMY_CONTACT_DAMAGE = 30;
    const unsigned int ENEMY_BASE_LIFE = 30;
    const unsigned int ENEMY_MIN_LIFE = 0;
    const int ENEMY_MIN_RAND_POS = -100;
    const unsigned int ENEMY_MAX_RAND_POS = 100;
    const unsigned int ENEMY_SPEED = 1;
    const unsigned int ENEMY_PITCH = 2;
    const unsigned int ENEMY_YAW = 0;
    const unsigned int ENEMY_HITBOX = 7;
    const unsigned int ENEMY_ROTATE = 180;
    const unsigned int ENEMY_LIFE_LOST = 10;
    const unsigned int ENEMY_DAMAGE = 10;

    // PLAYER STATS
    const unsigned int PLAYER_MIN_LIFE = 30;
    const unsigned int PLAYER_DEAD = 0;
    const unsigned int PLAYER_BASE_POSITION = 0;
    const unsigned int PLAYER_BASE_ROTATION = 0;
    const unsigned int PLAYER_BASE_SPEED = 0;
    const unsigned int PLAYER_LENGTH = 3;
    const unsigned int PLAYER_WIDTH = 3;
    const unsigned int PLAYER_HEIGHT = 3;
    const unsigned int PLAYER_BASE_LIFE = 100;
    const bool PLAYER_SPAWNING_INVINCIBILITY = false;
    const unsigned int PLAYER_OUT_OF_ARENA_RELOCATION = 400;
    const unsigned int BULLET_OUT_OF_ARENA_RELOCATION = 400;
    const unsigned int PLAYER_PITCH_LIMIT = 60;

    // CAMERA CONFIG
    const unsigned int CAMERA_Y = 10;
    const unsigned int CAMERA_Z = 20;

};

namespace playercontrols
{
    const int NEGATIVE_MOVEMENT = -2;
    const unsigned int POSITIVE_MOVEMENT = 2;
    const GLfloat POSITIVE_SPEED_DECREASE = 0.96;
    const GLfloat NEGATIVE_SPEED_DECREASE = 0.90;
};