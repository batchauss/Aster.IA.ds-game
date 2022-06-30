#include "../../includes/constant.h"

#include "hud.h"

extern bool finActivated;
extern bool pauseActivated;
extern GLuint texture[2];
extern std::string pseudonyme;

int tempsDef;

GLvoid barreVie(GLfloat vie)
{
    if (!pauseActivated)
    {
        // Début 2D
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(hud::PROJECTION_LEFT, hud::PROJECTION_RIGHT, hud::PROJECTION_BOTTOM, hud::PROJECTION_TOP, hud::PROJECTION_NEAR_VAL, hud::PROJECTION_FAR_VAL);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glDisable(GL_LIGHTING);

        glPushMatrix();
        GLfloat posx = hud::PSEUDO_DEFAULT_POSITION;
        switch (pseudonyme.size())
        {
        case 10:
            posx = hud::PSEUDO_POSITION_TEN;
            break;
        case 9:
            posx = hud::PSEUDO_POSITION_NINE;
            break;
        case 8:
            posx = hud::PSEUDO_POSITION_EIGHT;
            break;
        case 7:
            posx = hud::PSEUDO_POSITION_SEVEN;
            break;
        case 6:
            posx = hud::PSEUDO_POSITION_SIX;
            break;
        case 5:
            posx = hud::PSEUDO_POSITION_FIVE;
            break;
        case 4:
            posx = hud::PSEUDO_POSITION_FOUR;
            break;
        case 3:
            posx = hud::PSEUDO_POSITION_THREE;
            break;
        case 2:
            posx = hud::PSEUDO_POSITION_TWO;
            break;
        case 1:
            posx = hud::PSEUDO_POSITION_ONE;
            break;
        }
        vBitmapOutput(posx, hud::BITMAP_Y, hud::BITMAP_SCALEX, hud::BITMAP_SCALEY, pseudonyme, GLUT_STROKE_ROMAN, hud::BITMAP_LINE_WIDTH);
        glPopMatrix();

        glTranslatef(hud::LIFE_INDICATOR_TRANSLATE_X, hud::LIFE_INDICATOR_TRANSLATE_Y, hud::LIFE_INDICATOR_TRANSLATE_Z);

        if (vie > hud::MAX_LIFE_DELIMITER)
            glColor3f(hud::MAX_LIFE_RED, hud::MAX_LIFE_GREEN, hud::MAX_LIFE_BLUE);
        else if (vie > hud::LOW_LIFE_DELIMITER)
            glColor3f(hud::MIDDLE_LIFE_RED, hud::MIDDLE_LIFE_GREEN, hud::MIDDLE_LIFE_BLUE);
        else
            glColor3f(hud::LOW_LIFE_RED, hud::LOW_LIFE_GREEN, hud::LOW_LIFE_BLUE);

        glScalef(vie / hud::LIFE_INDICATOR_SCALEX, hud::LIFE_INDICATOR_SCALEY, hud::LIFE_INDICATOR_SCALEZ);
        glutSolidCube(hud::LIFE_INDICATOR_SIZE);

        // End 2D
        glEnable(GL_LIGHTING);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }
}

GLvoid timer(int tempsRetenu)
{
    int tempsMax = hud::MAX_TIME;

    int tempsPasse = tempsMax - glutGet(GLUT_ELAPSED_TIME);
    int tempsActuel = tempsPasse + tempsRetenu;

    tempsDef = tempsActuel;

    if (tempsActuel <= 0)
        finActivated = true;

    glColor3f(hud::TIMER_RED, hud::TIMER_GREEN, hud::TIMER_BLUE);
    std::string tmp = intPadding(tempsActuel);
    vBitmapOutput(hud::TIMER_BITMAP_X, hud::TIMER_BITMAP_Y, hud::TIMER_BITMAP_SCALEX, hud::TIMER_BITMAP_SCALEY, tmp, GLUT_STROKE_ROMAN, hud::TIMER_BITMAP_LINE_WIDTH);
}

std::string intPadding(int i)
{
    if (i <= 0)
        return "STOP";
    std::string s = std::to_string(i);

    if (s.size() == 6)
        s = s.substr(0, 3) + "." + s.substr(3, 1);
    else if (s.size() == 5)
        s = s.substr(0, 2) + "." + s.substr(2, 2);
    else if (s.size() == 4)
        s = s.substr(0, 1) + '.' + s.substr(1, 2);
    else if (s.size() == 3)
        s = "0." + s.substr(0, 2);

    return s;
}

GLvoid afficheScore(GLfloat score)
{
    int s = score;
    vBitmapOutput(hud::SCORE_BITMAP_X, hud::SCORE_BITMAP_Y, hud::SCORE_BITMAP_SCALEX, hud::SCORE_BITMAP_SCALEY, std::to_string(s) + "pts", GLUT_STROKE_ROMAN, hud::SCORE_BITMAP_LINE_WIDTH);
}

void vBitmapOutput(GLfloat x, GLfloat y, GLfloat scalex, GLfloat scaley, std::string string, void *font, GLfloat lineWidth)
{
    // Début 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    glColor3f(hud::BITMAP_RED, hud::BITMAP_GREEN, hud::BITMAP_BLUE);
    glLineWidth(lineWidth);
    glScalef(hud::BITMAP_SCALE, hud::BITMAP_SCALE, hud::BITMAP_SCALE);
    glScalef(1.2, 1.4, 1);
    glScalef(scalex, scaley, 1);

    glTranslatef(x, y, 0);

    int len;
    len = string.size(); // Calcule la longueur de la chaîne
    for (int i = 0; i < len; i++)
        glutStrokeCharacter(font, string[i]); // Affiche chaque caractère de la chaîne

    // End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid decoHUD()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(hud::PROJECTION_LEFT, hud::PROJECTION_RIGHT, hud::PROJECTION_BOTTOM, hud::PROJECTION_TOP, hud::PROJECTION_NEAR_VAL, hud::PROJECTION_FAR_VAL);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    glColor3f(hud::HUD_RED, hud::HUD_GREEN, hud::HUD_BLUE);
    glLineWidth(hud::HUD_LINE_WIDTH);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-hud::HUD_ORIGIN, -hud::HUD_ORIGIN);
    glVertex2f(hud::HUD_ORIGIN, -hud::HUD_ORIGIN);
    glVertex2f(hud::HUD_ORIGIN, hud::HUD_EXTREMITY_ONE);
    glVertex2f(hud::HUD_EXTREMITY_TWO, hud::HUD_EXTREMITY_ONE);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(hud::HUD_EXTREMITY_THREE, hud::HUD_EXTREMITY_TWO);
    glVertex2f(hud::HUD_EXTREMITY_THREE, hud::HUD_ORIGIN);
    glVertex2f(hud::HUD_EXTREMITY_FOUR, hud::HUD_ORIGIN);
    glVertex2f(hud::HUD_EXTREMITY_FIVE, hud::HUD_EXTREMITY_ONE);
    glVertex2f(-hud::HUD_EXTREMITY_FIVE, hud::HUD_EXTREMITY_ONE);
    glVertex2f(-hud::HUD_EXTREMITY_FOUR, hud::HUD_ORIGIN);
    glVertex2f(-hud::HUD_ORIGIN, hud::HUD_ORIGIN);
    glVertex2f(-hud::HUD_ORIGIN, -hud::HUD_ORIGIN);
    glEnd();

    // End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid vieSoucoupe(int vie, GLfloat angle)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(hud::PROJECTION_LEFT, hud::PROJECTION_RIGHT, hud::PROJECTION_BOTTOM, hud::PROJECTION_TOP, hud::PROJECTION_NEAR_VAL, hud::PROJECTION_FAR_VAL);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glTranslatef(hud::ENEMY_X, hud::ENEMY_Y, hud::ENEMY_Z);
    glPushMatrix();
    glTranslatef(hud::SECOND_ENEMY_X, hud::ENEMY_Y, hud::SECOND_ENEMY_Z);
    glScalef(0.1, 0.1, 0.1);
    glScalef(0.2, 0.4, 0.2);
    glCallList(5);
    glPopMatrix();
    glRotatef(angle, hud::ENEMY_ROTATE_X, hud::ENEMY_ROTATE_Y, hud::ENEMY_ROTATE_Z);
    glPushMatrix();
    glCallList(8);
    glPopMatrix();

    if (vie > hud::ENEMY_LOW_LIFE_DELIMITER)
    {
        glPushMatrix();
        glTranslatef(hud::ENEMY_MINLIFE_TRANSLATE_X, hud::ENEMY_MINLIFE_TRANSLATE_Y, hud::ENEMY_MINLIFE_TRANSLATE_Z);
        glCallList(8);
        glPopMatrix();
        if (vie == hud::ENEMY_MAX_LIFE_DELIMITER)
        {
            glPushMatrix();
            glTranslatef(hud::ENEMY_MAXLIFE_TRANSLATE_X, hud::ENEMY_MAXLIFE_TRANSLATE_Y, hud::ENEMY_MAXLIFE_TRANSLATE_Z);
            glCallList(8);
            glPopMatrix();
        }
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}