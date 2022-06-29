#include "../../includes/constant.h"

#include "renduPause.h"

GLvoid renduPause()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(render::PROJECTION_LEFT, render::PROJECTION_RIGHT, render::PROJECTION_BOTTOM, render::PROJECTION_TOP, render::PROJECTION_NEAR_VAL, render::PROJECTION_FAR_VAL);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    boutonPause();

    //  Ecriture des scores
    glPushMatrix();
    vBitmapOutput(render::HIGHSCORE_BITMAP_X, render::HIGHSCORE_BITMAP_Y, render::HIGHSCORE_BITMAP_SCALEX, render::HIGHSCORE_BITMAP_SCALEY, "HIGHSCORES", GLUT_STROKE_ROMAN, render::HIGHSCORE_BITMAP_LINE_WIDTH);
    std::vector<std::string> scores = bestScores();
    GLfloat espacementHauteur = render::HEIGHT_SPACE;
    for (unsigned int i = 0; i < scores.size(); i++)
    {
        vBitmapOutput(render::HIGHSCORE_SCORE_X, espacementHauteur, render::HIGHSCORE_SCORE_SCALE_X, render::HIGHSCORE_SCORE_SCALE_Y, scores.at(i), GLUT_STROKE_ROMAN, render::HIGHSCORE_SCORE_LINE_WIDTH);
        espacementHauteur -= render::HEIGHT_SPACE_DIFF;
    }
    glPopMatrix();

    //  Séparation ligne blanche
    glColor3f(render::LINE_R, render::LINE_G, render::LINE_B);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glVertex2f(render::LINE_POINT_ONE, render::LINE_POINT_ONE);
    glVertex2f(render::LINE_POINT_ONE, render::LINE_POINT_TWO);
    glEnd();
    glPopMatrix();

    //  Affichage "boutons"
    // glColor3f(1, 1, 1);
    glColor3f(render::PAUSE_R, render::PAUSE_G, render::PAUSE_B);
    vBitmapOutput(render::PAUSE_RESUME_BUTTONS_BITMAP_X, render::PAUSE_RESUME_BUTTONS_BITMAP_Y, render::PAUSE_RESUME_BUTTONS_BITMAP_SCALEX, render::PAUSE_RESUME_BUTTONS_BITMAP_SCALEY, "  Reprendre", GLUT_STROKE_ROMAN, render::PAUSE_RESUME_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::PAUSE_LABEL_RESUME_BUTTONS_BITMAP_X, render::PAUSE_LABEL_RESUME_BUTTONS_BITMAP_Y, render::PAUSE_LABEL_RESUME_BUTTONS_BITMAP_SCALEX, render::PAUSE_LABEL_RESUME_BUTTONS_BITMAP_SCALEY, "Touche Echap", GLUT_STROKE_ROMAN, render::PAUSE_LABEL_RESUME_BUTTONS_BITMAP_LINE_WIDTH);

    vBitmapOutput(render::PAUSE_REPLAY_BUTTONS_BITMAP_X, render::PAUSE_REPLAY_BUTTONS_BITMAP_Y, render::PAUSE_REPLAY_BUTTONS_BITMAP_SCALEX, render::PAUSE_REPLAY_BUTTONS_BITMAP_SCALEY, " Rejouer", GLUT_STROKE_ROMAN, render::PAUSE_REPLAY_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_X, render::PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_Y, render::PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_SCALEX, render::PAUSE_LABEL_REPLAY_BUTTONS_BITMAP_SCALEY, "Touche R", GLUT_STROKE_ROMAN, render::PAUSE_REPLAY_BUTTONS_BITMAP_LINE_WIDTH);

    vBitmapOutput(render::PAUSE_QUIT_BUTTONS_BITMAP_X, render::PAUSE_QUIT_BUTTONS_BITMAP_Y, render::PAUSE_QUIT_BUTTONS_BITMAP_SCALEX, render::PAUSE_QUIT_BUTTONS_BITMAP_SCALEY, " Quitter", GLUT_STROKE_ROMAN, render::PAUSE_QUIT_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::PAUSE_LABEL_QUIT_BUTTONS_BITMAP_X, render::PAUSE_LABEL_QUIT_BUTTONS_BITMAP_Y, render::PAUSE_LABEL_QUIT_BUTTONS_BITMAP_SCALEX, render::PAUSE_LABEL_QUIT_BUTTONS_BITMAP_SCALEY, "Touche L", GLUT_STROKE_ROMAN, render::PAUSE_LABEL_QUIT_BUTTONS_BITMAP_LINE_WIDTH);

    //  Fenêtre
    glPushMatrix();
    glColor3f(render::BLACK_R, render::BLACK_G, render::BLACK_B);
    glBegin(GL_QUADS);
    glVertex2f(render::FIRST_QUAD_POINT_ONE, render::FIRST_QUAD_POINT_TWO);
    glVertex2f(render::FIRST_QUAD_POINT_THREE, render::FIRST_QUAD_POINT_TWO);
    glVertex2f(render::FIRST_QUAD_POINT_THREE, render::FIRST_QUAD_POINT_FOUR);
    glVertex2f(render::FIRST_QUAD_POINT_ONE, render::FIRST_QUAD_POINT_FOUR);
    glEnd();
    glColor3f(render::SECOND_QUAD_R, render::SECOND_QUAD_G, render::SECOND_QUAD_B);
    glBegin(GL_QUADS);
    glVertex2f(render::SECOND_QUAD_POINT_ONE, render::SECOND_QUAD_POINT_TWO);
    glVertex2f(render::SECOND_QUAD_POINT_THREE, render::SECOND_QUAD_POINT_TWO);
    glVertex2f(render::SECOND_QUAD_POINT_THREE, render::SECOND_QUAD_POINT_FOUR);
    glVertex2f(render::SECOND_QUAD_POINT_ONE, render::SECOND_QUAD_POINT_FOUR);
    glEnd();
    glPopMatrix();

    // End 2D
    glEnable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

GLvoid boutonPause()
{
    glPushMatrix();
    glTranslatef(render::PAUSE_CUBE_ONE_TRANSLATE_X, render::PAUSE_CUBE_ONE_TRANSLATE_Y, render::PAUSE_CUBE_ONE_TRANSLATE_Z);
    glScalef(render::PAUSE_CUBE_ONE_SCALE_X, render::PAUSE_CUBE_ONE_SCALE_Y, render::PAUSE_CUBE_ONE_SCALE_Z);
    glutSolidCube(render::PAUSE_CUBE_SIZE);
    glTranslatef(render::PAUSE_CUBE_ONE_TRANSLATE_X, render::PAUSE_CUBE_TWO_TRANSLATE_Y, render::PAUSE_CUBE_TWO_TRANSLATE_Z);
    glutSolidCube(render::PAUSE_CUBE_SIZE);
    glPopMatrix();
}