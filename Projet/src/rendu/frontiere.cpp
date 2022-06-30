#include "../../includes/constant.h"

#include "frontiere.h"

GLfloat sizeFrontiere = gamearea::AREA_SIZE;

GLvoid cube_frontiere(GLuint texture)
{ // un cube entouré de textures

  glBindTexture(GL_TEXTURE_2D, texture);
  glEnable(GL_TEXTURE_2D);

  GLfloat d = gamearea::TEXTURE_SIZE;                       // dimensions de la texture
  GLfloat nb_text = gamearea::NUMBER_OF_TEXTURE_REPETITION; // nombre de fois ou la texture est répétée dans l'affichage d'un coté
  glPushMatrix();
  {
    // textures sur les 4 cotés du cube
    for (int i = 0; i < 4; ++i)
    {
      glRotatef(gamearea::CUBE_ROTATION_ANGLE, gamearea::CUBE_ROTATION_X, gamearea::CUBE_ROTATION_Y, gamearea::CUBE_ROTATION_Z);
      glBegin(GL_QUADS);
      glTexCoord2f(gamearea::CUBE_ORIGIN, gamearea::CUBE_ORIGIN);
      glVertex3f(-d, -d, -d);

      glTexCoord2f(nb_text, gamearea::CUBE_ORIGIN);
      glVertex3f(d, -d, -d);

      glTexCoord2f(nb_text, nb_text);
      glVertex3f(d, d, -d);

      glTexCoord2f(gamearea::CUBE_ORIGIN, nb_text);
      glVertex3f(-d, d, -d);
      glEnd();
    }
  }
  glPopMatrix();

  // textures sur le bas  du cube
  glRotatef(gamearea::BOTTOM_ROTATION_ANGLE, gamearea::BOTTOM_ROTATION_X, gamearea::BOTTOM_ROTATION_Y, gamearea::BOTTOM_ROTATION_Z);
  glBegin(GL_QUADS);
  glTexCoord2f(gamearea::CUBE_ORIGIN, gamearea::CUBE_ORIGIN);
  glVertex3f(-d, -d, -d);

  glTexCoord2f(nb_text, gamearea::CUBE_ORIGIN);
  glVertex3f(d, -d, -d);

  glTexCoord2f(nb_text, nb_text);
  glVertex3f(d, d, -d);

  glTexCoord2f(0, nb_text);
  glVertex3f(-d, d, -d);
  glEnd();

  // textures sur le haut  du cube
  glRotatef(gamearea::TOP_ROTATION_ANGLE, gamearea::TOP_ROTATION_X, gamearea::TOP_ROTATION_Y, gamearea::TOP_ROTATION_Z);
  glBegin(GL_QUADS);
  glTexCoord2f(gamearea::CUBE_ORIGIN, gamearea::CUBE_ORIGIN);
  glVertex3f(-d, -d, -d);

  glTexCoord2f(nb_text, gamearea::CUBE_ORIGIN);
  glVertex3f(d, -d, -d);

  glTexCoord2f(nb_text, nb_text);
  glVertex3f(d, d, -d);

  glTexCoord2f(gamearea::CUBE_ORIGIN, nb_text);
  glVertex3f(-d, d, -d);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

GLvoid frontieres(GLuint texture)
{ // 3 cubes de sens differents pour ne pas voir les coins

  cube_frontiere(texture);
  glPushMatrix();
  {
    glRotatef(gamearea::LIMIT_ROTATION_ANGLE, gamearea::LIMIT_FIRST_ROTATION_X, gamearea::LIMIT_FIRST_ROTATION_Y, gamearea::LIMIT_FIRST_ROTATION_Z);
    glRotatef(gamearea::LIMIT_ROTATION_ANGLE, gamearea::LIMIT_SECOND_ROTATION_X, gamearea::LIMIT_SECOND_ROTATION_Y, gamearea::LIMIT_SECOND_ROTATION_Z);
    cube_frontiere(texture);
  }
  glPopMatrix();

  glPushMatrix();
  {
    glRotatef(gamearea::LIMIT_NEGATIVE_ROTATION_ANGLE, gamearea::LIMIT_THIRD_ROTATION_X, gamearea::LIMIT_THIRD_ROTATION_Y, gamearea::LIMIT_THIRD_ROTATION_Z);
    glRotatef(gamearea::LIMIT_NEGATIVE_ROTATION_ANGLE, gamearea::LIMIT_FOURTH_ROTATION_X, gamearea::LIMIT_FOURTH_ROTATION_Y, gamearea::LIMIT_FOURTH_ROTATION_Z);
    cube_frontiere(texture);
  }
  glPopMatrix();
}

GLvoid grille(GLfloat r, GLfloat g, GLfloat b)
{ /// quadrillage de frontière
  glPushMatrix();
  {
    glEnable(GL_LINE_SMOOTH);

    glLineWidth(gamearea::GRID_WIDTH);
    glColor3f(r, g, b);

    for (int i = 0; i <= 10; ++i)
    {
      glBegin(GL_LINE_LOOP);
      {
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere); // 1
        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere);  // 2

        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere);  // 3
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere); // 4
      }
      glEnd();
    }

    glRotatef(gamearea::GRID_ROTATE_ANGLE, gamearea::GRID_FIRST_ROTATION_X, gamearea::GRID_FIRST_ROTATION_Y, gamearea::GRID_FIRST_ROTATION_Z);
    for (int i = 0; i <= 10; ++i)
    {
      glBegin(GL_LINE_LOOP);
      {
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere); // 1
        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere);  // 2

        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere);  // 3
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere); // 4
      }
      glEnd();
    }

    glRotatef(gamearea::GRID_ROTATE_ANGLE, gamearea::GRID_SECOND_ROTATION_X, gamearea::GRID_SECOND_ROTATION_Y, gamearea::GRID_SECOND_ROTATION_Z);
    for (int i = 0; i <= 10; ++i)
    {
      glBegin(GL_LINE_LOOP);
      {
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere); // 1
        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), sizeFrontiere);  // 2

        glVertex3f(sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere);  // 3
        glVertex3f(-sizeFrontiere, -sizeFrontiere + (gamearea::GRID_COEFFICIENT_LINES * i), -sizeFrontiere); // 4
      }
      glEnd();
    }
  }
  glPopMatrix();

  glDisable(GL_LINE_SMOOTH);
}
