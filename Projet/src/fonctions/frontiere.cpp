#include "frontiere.h"

extern GLuint texture[];



GLvoid frontieres(){ //  un grand cube qui va représenter l'univers fermé du jeu

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);

   glPushMatrix();
   {
    //textures sur les 4 cotés de l'univers
     for (int i=0;i<4;++i){
       glRotatef(90,0.0,1.0,0.0);
        glBegin(GL_QUADS);
         glTexCoord2f(0, 0);
         glVertex3f(-50, -50, -50);

         glTexCoord2f(10, 0);
         glVertex3f(50,-50,-50);

         glTexCoord2f(10, 10);
         glVertex3f(50,50,-50);

         glTexCoord2f(0, 10);    
         glVertex3f(-50, 50, -50);
        glEnd();
     }
    }
  glPopMatrix(); 



     //textures sur le haut  de l'univers
     
       glRotatef(-90.0,1.0,0.0,0.0);
        glBegin(GL_QUADS);
         glTexCoord2f(0, 0);
         glVertex3f(-50, -50, -50);

         glTexCoord2f(10, 0);
         glVertex3f(50,-50,-50);

         glTexCoord2f(10, 10);
         glVertex3f(50,50,-50);

         glTexCoord2f(0, 10);    
         glVertex3f(-50, 50, -50);
        glEnd();
    
  

  

    glDisable(GL_TEXTURE_2D);
}
