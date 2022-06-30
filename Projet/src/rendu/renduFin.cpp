#include "../../includes/constant.h"

#include "renduFin.h"

GLvoid renduFin()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(render::PROJECTION_LEFT, render::PROJECTION_RIGHT, render::PROJECTION_BOTTOM, render::PROJECTION_TOP, render::PROJECTION_NEAR_VAL, render::PROJECTION_FAR_VAL);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_LIGHTING);

    //  Ecriture des scores
    glPushMatrix();
    vBitmapOutput(render::SCORE_X, render::SCORE_Y, render::SCORE_SCALE_X, render::SCORE_SCALE_Y, "HIGHSCORES", GLUT_STROKE_ROMAN, render::SCORE_LINE_WIDTH);
    std::vector<std::string> scores = bestScores();
    GLfloat espacementHauteur = render::HEIGHT_SPACE;
    for (unsigned int i = 0; i < scores.size(); i++)
    {
        vBitmapOutput(render::PLAYER_SCORE_X, espacementHauteur, render::PLAYER_SCORE_SCALE_X, render::PLAYER_SCORE_SCALE_Y, scores.at(i), GLUT_STROKE_ROMAN, render::PLAYER_SCORE_LINE_WIDTH);
        espacementHauteur -= render::HEIGHT_SPACE_DIFF;
    }
    glPopMatrix();

    //  Affichage "boutons"
    glColor3f(render::BUTTONS_COLOR, render::BUTTONS_COLOR, render::BUTTONS_COLOR);
    vBitmapOutput(render::END_REPLAY_BUTTONS_BITMAP_X, render::END_REPLAY_BUTTONS_BITMAP_Y, render::END_REPLAY_BUTTONS_BITMAP_SCALEX, render::END_REPLAY_BUTTONS_BITMAP_SCALEY, " Rejouer", GLUT_STROKE_ROMAN, render::END_REPLAY_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::END_LABEL_REPLAY_BUTTONS_BITMAP_X, render::END_LABEL_REPLAY_BUTTONS_BITMAP_Y, render::END_LABEL_REPLAY_BUTTONS_BITMAP_SCALEY, render::END_LABEL_REPLAY_BUTTONS_BITMAP_SCALEY, "Touche R", GLUT_STROKE_ROMAN, render::END_LABEL_REPLAY_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::END_QUIT_BUTTONS_BITMAP_X, render::END_QUIT_BUTTONS_BITMAP_Y, render::END_QUIT_BUTTONS_BITMAP_SCALEX, render::END_QUIT_BUTTONS_BITMAP_SCALEY, " Quitter", GLUT_STROKE_ROMAN, render::END_QUIT_BUTTONS_BITMAP_LINE_WIDTH);
    vBitmapOutput(render::END_LABEL_QUIT_BUTTONS_BITMAP_X, render::END_LABEL_QUIT_BUTTONS_BITMAP_Y, render::END_LABEL_QUIT_BUTTONS_BITMAP_SCALEX, render::END_LABEL_QUIT_BUTTONS_BITMAP_SCALEY, "Touche L", GLUT_STROKE_ROMAN, render::END_LABEL_QUIT_BUTTONS_BITMAP_LINE_WIDTH);

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