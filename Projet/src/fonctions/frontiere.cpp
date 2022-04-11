#include "frontiere.h"

extern GLuint texture[];

GLvoid frontieres(){ //  un grand cube qui va représenter l'univers fermé du jeu

/*
    glFrontFace(GL_CW);
    glColor3f(1.0,1.0,1.0);
    glutSolidCube(100);

    */

   
   //glColor3f(0.0,1.0,0.0);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);

   glPushMatrix();
   {
     glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex3f(-50, -50, -50);

      glTexCoord2f(1, 0);
      glVertex3f(50,-50,-50);

      glTexCoord2f(1, 1);
      glVertex3f(50,50,-50);

      glTexCoord2f(0, 1);    
      glVertex3f(-50, 50, -50);
     glEnd();
  }
  glPopMatrix();

  

    glDisable(GL_TEXTURE_2D);
}
