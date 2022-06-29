#include <GL/gl.h>
#include "math.h"
#include <string>

namespace gameconf
{
    const unsigned int INVINCIBILITY_TIME = 3000;

    const GLfloat DEG2RAD = M_PI / 180;

    const int BASETIME = 0;
    const GLfloat GAME_AMBIENTE_LIGHT = 0.7f;
    const GLfloat PAUSE_AMBIENTE_LIGHT = 0.3f;

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

namespace menu
{
    const unsigned int PSEUDO_AREA_SIZE_X = 400;
    const unsigned int PSEUDO_AREA_SIZE_Y = 50;
    const unsigned int PSEUDO_MAX_LENGTH = 10;

    const unsigned int HORIZONTAL_SPACING = 20;
    const unsigned int VERTICAL_SPACING = 10;
    const unsigned int PSEUDO_PLACEMENT[4] = {0, 0, 1, 2};
    const unsigned int PLAY_PLACEMENT[4] = {1, 0, 1, 2};
    const unsigned int OPTIONS_PLACEMENT[2] = {2, 0};
    const unsigned int QUIT_PLACEMENT[2] = {2, 1};

    // Language possible
    const std::string LANG_FR = "Français";
    const std::string LANG_EN = "English";

    // Screen options
    const std::string SIZE1280 = "1290x980";
    const std::string SIZE1920 = "1920x1080";
    const std::string SIZEFULLSCREEN = "Fullscreen";

    // Options layout
    const unsigned int OPT_HORIZONTAL_SPACING = 20;

    const unsigned int OPT_LANG_PLACEMENT[2] = {0, 1};
    const unsigned int OPT_WINDOW_PLACEMENT[2] = {1, 1};
    const unsigned int OPT_QUIT_PLACEMENT[2] = {2, 0};
    const unsigned int OPT_SAVE_PLACEMENT[2] = {2, 1};

};

namespace lang_fr
{
    const std::string PSEUDO_BOX_LABEL = "PSEUDO";
    const std::string PSEUDO_BOX_DEFAULT = "Anon";
    const std::string PSEUDO_BOX_FONT = "Cochin";
    const unsigned int PSEUDO_BOX_FONTSIZE = 15;

    const unsigned int PLAY_BUTTON_SIZE_X = 400;
    const unsigned int PLAY_BUTTON_SIZE_Y = 100;
    const std::string PLAY_BUTTON_TEXT = "JOUER";
    const std::string PLAY_BUTTON_FONT = "Times";
    const unsigned int PLAY_BUTTON_FONTSIZE = 30;

    const unsigned int OPTIONS_BUTTON_SIZE_X = 190;
    const unsigned int OPTIONS_BUTTON_SIZE_Y = 50;
    const std::string OPTIONS_BUTTON_TEXT = "Options";
    const std::string OPTIONS_BUTTON_FONT = "Times";
    const unsigned int OPTIONS_BUTTON_FONTSIZE = 15;

    const unsigned int QUIT_BUTTON_SIZE_X = 190;
    const unsigned int QUIT_BUTTON_SIZE_Y = 50;
    const std::string QUIT_BUTTON_TEXT = "Quitter";
    const std::string QUIT_BUTTON_FONT = "Times";
    const unsigned int QUIT_BUTTON_FONTSIZE = 15;

    const unsigned int LANG_SIZE_X = 0;
    const unsigned int LANG_SIZE_Y = 0;
    const std::string LANG_LABEL = "Langue : ";

    const unsigned int WINDOW_SIZE_X = 1;
    const unsigned int WINDOW_SIZE_Y = 0;
    const std::string WINDOW_LABEL = "Taille de la fenêtre : ";

    const std::string OPT_QUIT_BUTTON_TEXT = "Quitter (Sans sauvegarder)";

    const std::string OPT_SAVE_BUTTON_TEXT = "Confirmer";
};

namespace background
{
    const unsigned int OBJ_NUMBER = 9;

    // PLANET 1
    const unsigned int P1_TRANSLATE_X = 200;
    const unsigned int P1_TRANSLATE_Y = 1000;
    const unsigned int P1_TRANSLATE_Z = 0;

    const unsigned int P1_SCALE_X = 10;
    const unsigned int P1_SCALE_Y = 10;
    const unsigned int P1_SCALE_Z = 10;

    const GLfloat P1_RED = 1;
    const GLfloat P1_GREEN = 1;
    const GLfloat P1_BLUE = 0.5f;

    const unsigned int P1_SPHERE_RADIUS = 10;
    const unsigned int P1_SPHERE_SLICES = 20;
    const unsigned int P1_SPHERE_STACKS = 20;

    const unsigned int P1_RING_ROTATE_ANGLE = 40;
    const unsigned int P1_RING_ROTATE_X = 1;
    const unsigned int P1_RING_ROTATE_Y = 1;
    const unsigned int P1_RING_ROTATE_Z = 1;

    const unsigned int P1_RING_SCALE_X = 1;
    const unsigned int P1_RING_SCALE_Y = 1;
    const GLfloat P1_RING_SCALE_Z = 0.1f;

    const GLfloat P1_RING_RED = 0.5f;
    const GLfloat P1_RING_GREEN = 0.35f;
    const GLfloat P1_RING_BLUE = 0.05f;

    const unsigned int P1_RING_INNER_RADIUS = 5;
    const unsigned int P1_RING_OUTER_RADIUS = 20;
    const unsigned int P1_RING_NSIDES = 20;
    const unsigned int P1_RING_RINGS = 20;

    // PLANET 2

    const unsigned int P2_TRANSLATE_X = 300;
    const unsigned int P2_TRANSLATE_Y = -1000;
    const unsigned int P2_TRANSLATE_Z = 200;

    const unsigned int P2_SCALE_X = 10;
    const unsigned int P2_SCALE_Y = 10;
    const unsigned int P2_SCALE_Z = 10;

    const GLfloat P2_RED = 0;
    const GLfloat P2_GREEN = 0;
    const GLfloat P2_BLUE = 1;

    const unsigned int P2_SPHERE_RADIUS = 10;
    const unsigned int P2_SPHERE_SLICES = 20;
    const unsigned int P2_SPHERE_STACKS = 20;

    const unsigned int P2_RING_ROTATE_ANGLE = -30;
    const unsigned int P2_RING_ROTATE_X = 1;
    const unsigned int P2_RING_ROTATE_Y = 1;
    const unsigned int P2_RING_ROTATE_Z = 1;

    const unsigned int P2_RING_SCALE_X = 1;
    const unsigned int P2_RING_SCALE_Y = 1;
    const GLfloat P2_RING_SCALE_Z = 0.1f;

    const GLfloat P2_RING_RED = 0.5f;
    const GLfloat P2_RING_GREEN = 0.5f;
    const GLfloat P2_RING_BLUE = 0.9f;

    const unsigned int P2_RING_INNER_RADIUS = 5;
    const unsigned int P2_RING_OUTER_RADIUS = 20;
    const unsigned int P2_RING_NSIDES = 20;
    const unsigned int P2_RING_RINGS = 20;

};

namespace gamearea
{

    const unsigned int AREA_SIZE = 200;
    const unsigned int TEXTURE_SIZE = 2000;
    const unsigned int NUMBER_OF_TEXTURE_REPETITION = 10;

    // cube
    const unsigned int CUBE_ROTATION_ANGLE = 90;
    const GLfloat CUBE_ROTATION_X = 0.0f;
    const GLfloat CUBE_ROTATION_Y = 1.0f;
    const GLfloat CUBE_ROTATION_Z = 0.0f;
    const int CUBE_ORIGIN = 0;

    // textures
    const int BOTTOM_ROTATION_ANGLE = -90;
    const GLfloat BOTTOM_ROTATION_X = 1.0f;
    const GLfloat BOTTOM_ROTATION_Y = 0.0f;
    const GLfloat BOTTOM_ROTATION_Z = 0.0f;

    const int TOP_ROTATION_ANGLE = 189;
    const GLfloat TOP_ROTATION_X = 1.0f;
    const GLfloat TOP_ROTATION_Y = 0.0f;
    const GLfloat TOP_ROTATION_Z = 0.0f;

    // limits
    const int LIMIT_ROTATION_ANGLE = 45;
    const GLfloat LIMIT_FIRST_ROTATION_X = 1.0f;
    const GLfloat LIMIT_FIRST_ROTATION_Y = 0.0f;
    const GLfloat LIMIT_FIRST_ROTATION_Z = 0.0f;

    const GLfloat LIMIT_SECOND_ROTATION_X = 0.0f;
    const GLfloat LIMIT_SECOND_ROTATION_Y = 1.0f;
    const GLfloat LIMIT_SECOND_ROTATION_Z = 0.0f;

    const int LIMIT_NEGATIVE_ROTATION_ANGLE = -45;
    const GLfloat LIMIT_THIRD_ROTATION_X = 1.0f;
    const GLfloat LIMIT_THIRD_ROTATION_Y = 0.0f;
    const GLfloat LIMIT_THIRD_ROTATION_Z = 0.0f;

    const GLfloat LIMIT_FOURTH_ROTATION_X = 0.0f;
    const GLfloat LIMIT_FOURTH_ROTATION_Y = 1.0f;
    const GLfloat LIMIT_FOURTH_ROTATION_Z = 0.0f;

    // grid
    const GLfloat GRID_WIDTH = 1.2f;
    const unsigned int GRID_COEFFICIENT_LINES = 40;
    const unsigned int GRID_ROTATE_ANGLE = 90;
    const GLfloat GRID_FIRST_ROTATION_X = 0.0f;
    const GLfloat GRID_FIRST_ROTATION_Y = 0.0f;
    const GLfloat GRID_FIRST_ROTATION_Z = 1.0f;
    const GLfloat GRID_SECOND_ROTATION_X = 1.0f;
    const GLfloat GRID_SECOND_ROTATION_Y = 0.0f;
    const GLfloat GRID_SECOND_ROTATION_Z = 0.0f;
};

namespace hud
{
    const GLdouble PROJECTION_LEFT = -5.0;
    const GLdouble PROJECTION_RIGHT = 5.0;
    const GLdouble PROJECTION_BOTTOM = -5.0;
    const GLdouble PROJECTION_TOP = 5.0;
    const GLdouble PROJECTION_NEAR_VAL = -1.0;
    const GLdouble PROJECTION_FAR_VAL = 1.0;

    const GLfloat PSEUDO_DEFAULT_POSITION = 0.0f;

    const GLfloat PSEUDO_POSITION_ONE = -50.0f;
    const GLfloat PSEUDO_POSITION_TWO = -90.0f;
    const GLfloat PSEUDO_POSITION_THREE = -130.0f;
    const GLfloat PSEUDO_POSITION_FOUR = -160.0f;
    const GLfloat PSEUDO_POSITION_FIVE = -190.0f;
    const GLfloat PSEUDO_POSITION_SIX = -220.0f;
    const GLfloat PSEUDO_POSITION_SEVEN = -250.0f;
    const GLfloat PSEUDO_POSITION_EIGHT = -280.0f;
    const GLfloat PSEUDO_POSITION_NINE = -320.0f;
    const GLfloat PSEUDO_POSITION_TEN = -350.0f;

    const GLfloat BITMAP_Y = 300.0f;
    const GLfloat BITMAP_SCALEX = 0.3f;
    const GLfloat BITMAP_SCALEY = 0.3f;
    const GLfloat BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat LIFE_INDICATOR_TRANSLATE_X = 0.0f;
    const GLfloat LIFE_INDICATOR_TRANSLATE_Y = 0.3f;
    const GLfloat LIFE_INDICATOR_TRANSLATE_Z = 0.0f;

    const unsigned int MAX_LIFE_DELIMITER = 70;
    const unsigned int LOW_LIFE_DELIMITER = 50;

    const GLfloat MAX_LIFE_RED = 0.0f;
    const GLfloat MAX_LIFE_GREEN = 1.0f;
    const GLfloat MAX_LIFE_BLUE = 0.0f;

    const GLfloat MIDDLE_LIFE_RED = 1.0f;
    const GLfloat MIDDLE_LIFE_GREEN = 1.0f;
    const GLfloat MIDDLE_LIFE_BLUE = 0.0f;

    const GLfloat LOW_LIFE_RED = 1.0f;
    const GLfloat LOW_LIFE_GREEN = 0.0f;
    const GLfloat LOW_LIFE_BLUE = 0.0f;

    const unsigned int LIFE_INDICATOR_SCALEX = 120;
    const GLfloat LIFE_INDICATOR_SCALEY = 0.05f;
    const GLfloat LIFE_INDICATOR_SCALEZ = 0.05f;

    const unsigned int LIFE_INDICATOR_SIZE = 1;

    // timer

    const unsigned int MAX_TIME = 100000;

    const GLfloat TIMER_RED = 0.2f;
    const GLfloat TIMER_GREEN = 0.6f;
    const GLfloat TIMER_BLUE = 0.2f;

    const GLfloat TIMER_BITMAP_X = -165.0f;
    const GLfloat TIMER_BITMAP_Y = 900.0f;
    const GLfloat TIMER_BITMAP_SCALEX = 1.0f;
    const GLfloat TIMER_BITMAP_SCALEY = 1.0f;
    const GLfloat TIMER_BITMAP_LINE_WIDTH = 4.0f;

    // score

    const GLfloat SCORE_BITMAP_X = 780.0f;
    const GLfloat SCORE_BITMAP_Y = 900.0f;
    const GLfloat SCORE_BITMAP_SCALEX = 1.0f;
    const GLfloat SCORE_BITMAP_SCALEY = 1.0f;
    const GLfloat SCORE_BITMAP_LINE_WIDTH = 5.0f;

    // bitmap output
    const GLfloat BITMAP_RED = 1.0f;
    const GLfloat BITMAP_GREEN = 1.0f;
    const GLfloat BITMAP_BLUE = 1.0f;

    const GLfloat BITMAP_SCALE = 1.0f / 1520.38f;

    // decorative hud
    const GLfloat HUD_RED = 0.4f;
    const GLfloat HUD_GREEN = 0.0f;
    const GLfloat HUD_BLUE = 0.8f;

    const GLfloat HUD_LINE_WIDTH = 4.0f;

    const GLfloat HUD_ORIGIN = 4.8f;

    const GLfloat HUD_EXTREMITY_ONE = 3.85f;
    const GLfloat HUD_EXTREMITY_TWO = 5.0f;
    const GLfloat HUD_EXTREMITY_THREE = 2.8f;
    const GLfloat HUD_EXTREMITY_FOUR = 1.0f;
    const GLfloat HUD_EXTREMITY_FIVE = 0.8f;

    // enemy hud
    const GLfloat ENEMY_X = 4.5f;
    const GLfloat ENEMY_Y = 1.0f;
    const GLfloat ENEMY_Z = 0.0f;

    const GLfloat SECOND_ENEMY_X = 0.0f;
    const GLfloat SECOND_ENEMY_Z = 0.0f;

    const GLfloat ENEMY_ROTATE_X = 0.0f;
    const GLfloat ENEMY_ROTATE_Y = 1.0f;
    const GLfloat ENEMY_ROTATE_Z = 0.0f;

    const unsigned int ENEMY_MAX_LIFE_DELIMITER = 30;
    const unsigned int ENEMY_LOW_LIFE_DELIMITER = 10;

    const unsigned int ENEMY_MAXLIFE_TRANSLATE_X = 0;
    const int ENEMY_MAXLIFE_TRANSLATE_Y = -2;
    const unsigned int ENEMY_MAXLIFE_TRANSLATE_Z = 0;

    const unsigned int ENEMY_MINLIFE_TRANSLATE_X = 0;
    const int ENEMY_MINLIFE_TRANSLATE_Y = -1;
    const unsigned int ENEMY_MINLIFE_TRANSLATE_Z = 0;
};

namespace render
{

    const GLfloat LVL_ONE = 5.0f;
    const GLfloat LVL_TWO = 12.0f;
    const GLfloat LVL_THREE = 25.0f;

    const GLfloat BULLET_ONE = 1.0f;
    const GLfloat BULLET_ZERO = 0.0f;

    const GLfloat BULLET_ROTATE_X = 0.0f;
    const GLfloat BULLET_ROTATE_Y = 1.0f;
    const GLfloat BULLET_ROTATE_Z = 0.0f;

    const GLfloat BULLET_SCALE_X = 0.2f;
    const GLfloat BULLET_SCALE_Y = 0.2f;
    const GLfloat BULLET_SCALE_Z = 0.4f;

    const GLfloat BULLET_SIZE = 1.0f;

    const GLfloat SHIP_SIZE = 0.5f;

    const GLfloat ENEMY_SIZE = 7.0f;

    const GLfloat PLANET_SIZE = 7.0f;

    const GLfloat HEART_SIZE = 0.015f;
    const GLfloat HEART_SIZE_Y = 0.025f;

    const GLdouble PROJECTION_LEFT = -5.0;
    const GLdouble PROJECTION_RIGHT = 5.0;
    const GLdouble PROJECTION_BOTTOM = -5.0;
    const GLdouble PROJECTION_TOP = 5.0;
    const GLdouble PROJECTION_NEAR_VAL = -1.0;
    const GLdouble PROJECTION_FAR_VAL = 1.0;

    // end screen
    const GLfloat SCORE_X = -400.0f;
    const GLfloat SCORE_Y = 1200.0f;
    const GLfloat SCORE_SCALE_X = 0.5f;
    const GLfloat SCORE_SCALE_Y = 0.5f;
    const GLfloat SCORE_LINE_WIDTH = 5.0f;

    const GLfloat HEIGHT_SPACE = 800.0f;
    const GLfloat HEIGHT_SPACE_DIFF = 200.0f;

    const GLfloat PLAYER_SCORE_X = -500.0f;
    const GLfloat PLAYER_SCORE_SCALE_X = 0.5f;
    const GLfloat PLAYER_SCORE_SCALE_Y = 0.5f;
    const GLfloat PLAYER_SCORE_LINE_WIDTH = 3.0f;

    // end buttons
    const GLfloat BUTTONS_COLOR = 1.0f;

    const GLfloat END_REPLAY_BUTTONS_BITMAP_X = -1200.0f;
    const GLfloat END_REPLAY_BUTTONS_BITMAP_Y = -1300.0f;
    const GLfloat END_REPLAY_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat END_REPLAY_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat END_REPLAY_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat END_LABEL_REPLAY_BUTTONS_BITMAP_X = -1200.0f;
    const GLfloat END_LABEL_REPLAY_BUTTONS_BITMAP_Y = -1450.0f;
    const GLfloat END_LABEL_REPLAY_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat END_LABEL_REPLAY_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat END_LABEL_REPLAY_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat END_QUIT_BUTTONS_BITMAP_X = 700.0f;
    const GLfloat END_QUIT_BUTTONS_BITMAP_Y = -1300.0f;
    const GLfloat END_QUIT_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat END_QUIT_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat END_QUIT_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat END_LABEL_QUIT_BUTTONS_BITMAP_X = 700.0f;
    const GLfloat END_LABEL_QUIT_BUTTONS_BITMAP_Y = -1450.0f;
    const GLfloat END_LABEL_QUIT_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat END_LABEL_QUIT_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat END_LABEL_QUIT_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    // end window

    const GLfloat BLACK_R = 0.0f;
    const GLfloat BLACK_G = 0.0f;
    const GLfloat BLACK_B = 0.0f;

    const GLfloat FIRST_QUAD_POINT_ONE = -1.9f;
    const GLfloat FIRST_QUAD_POINT_TWO = -4.3f;
    const GLfloat FIRST_QUAD_POINT_THREE = 1.9f;
    const GLfloat FIRST_QUAD_POINT_FOUR = 3.3f;

    const GLfloat SECOND_QUAD_R = 0.4f;
    const GLfloat SECOND_QUAD_G = 0.0f;
    const GLfloat SECOND_QUAD_B = 0.8f;

    const GLfloat SECOND_QUAD_POINT_ONE = -2.0f;
    const GLfloat SECOND_QUAD_POINT_TWO = -4.5f;
    const GLfloat SECOND_QUAD_POINT_THREE = 2.0f;
    const GLfloat SECOND_QUAD_POINT_FOUR = 3.5f;

    // PAUSE MENU
    const GLfloat HIGHSCORE_BITMAP_X = -900.0f;
    const GLfloat HIGHSCORE_BITMAP_Y = 1200.0f;
    const GLfloat HIGHSCORE_BITMAP_SCALEX = 0.5f;
    const GLfloat HIGHSCORE_BITMAP_SCALEY = 0.5f;
    const GLfloat HIGHSCORE_BITMAP_LINE_WIDTH = 5.0f;

    const GLfloat HIGHSCORE_SCORE_X = -900.0f;
    const GLfloat HIGHSCORE_SCORE_SCALE_X = 0.5f;
    const GLfloat HIGHSCORE_SCORE_SCALE_Y = 0.5f;
    const GLfloat HIGHSCORE_SCORE_LINE_WIDTH = 3.0f;

    // line separation

    const GLfloat LINE_R = 0.4f;
    const GLfloat LINE_G = 0.0f;
    const GLfloat LINE_B = 0.8f;

    const GLfloat LINE_POINT_ONE = 0.6f;
    const GLfloat LINE_POINT_TWO = 3.0f;
    const GLfloat LINE_POINT_THREE = -1.0f;

    // buttons
    const GLfloat PAUSE_R = 1.0f;
    const GLfloat PAUSE_G = 1.0f;
    const GLfloat PAUSE_B = 1.0f;

    const GLfloat PAUSE_RESUME_BUTTONS_BITMAP_X = -1500.0f;
    const GLfloat PAUSE_RESUME_BUTTONS_BITMAP_Y = -1400.0f;
    const GLfloat PAUSE_RESUME_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_RESUME_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_RESUME_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat PAUSE_LABEL_RESUME_BUTTONS_BITMAP_X = -1500.0f;
    const GLfloat PAUSE_LABEL_RESUME_BUTTONS_BITMAP_Y = -1550.0f;
    const GLfloat PAUSE_LABEL_RESUME_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_LABEL_RESUME_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_LABEL_RESUME_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat PAUSE_REPLAY_BUTTONS_BITMAP_X = -250.0f;
    const GLfloat PAUSE_REPLAY_BUTTONS_BITMAP_Y = -1400.0f;
    const GLfloat PAUSE_REPLAY_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_REPLAY_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_REPLAY_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_X = -250.0f;
    const GLfloat PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_Y = -1550.0f;
    const GLfloat PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat PAUSE_QUIT_BUTTONS_BITMAP_X = 800.0f;
    const GLfloat PAUSE_QUIT_BUTTONS_BITMAP_Y = -1400.0f;
    const GLfloat PAUSE_QUIT_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_QUIT_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_QUIT_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    const GLfloat PAUSE_LABEL_QUIT_BUTTONS_BITMAP_X = 800.0f;
    const GLfloat PAUSE_LABEL_QUIT_BUTTONS_BITMAP_Y = -1550.0f;
    const GLfloat PAUSE_LABEL_QUIT_BUTTONS_BITMAP_SCALEX = 0.3f;
    const GLfloat PAUSE_LABEL_QUIT_BUTTONS_BITMAP_SCALEY = 0.5f;
    const GLfloat PAUSE_LABEL_QUIT_BUTTONS_BITMAP_LINE_WIDTH = 3.0f;

    // pause button
    const GLfloat PAUSE_CUBE_ONE_TRANSLATE_X = -4.0f;
    const GLfloat PAUSE_CUBE_ONE_TRANSLATE_Y = 4.0f;
    const GLfloat PAUSE_CUBE_ONE_TRANSLATE_Z = 0.0f;

    const GLfloat PAUSE_CUBE_ONE_SCALE_X = 0.2f;
    const GLfloat PAUSE_CUBE_ONE_SCALE_Y = 1.0f;
    const GLfloat PAUSE_CUBE_ONE_SCALE_Z = 1.0f;

    const GLfloat PAUSE_CUBE_SIZE = 1.0f;

    const GLfloat PAUSE_CUBE_TWO_TRANSLATE_X = 1.5f;
    const GLfloat PAUSE_CUBE_TWO_TRANSLATE_Y = 0.0f;
    const GLfloat PAUSE_CUBE_TWO_TRANSLATE_Z = 0.0f;
};
