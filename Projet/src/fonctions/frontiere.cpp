#include "frontiere.h"

GLvoid cube_frontiere(GLuint texture){  //un cube entouré de textures 

 glBindTexture(GL_TEXTURE_2D, texture);
 glEnable(GL_TEXTURE_2D);
  
   GLfloat d = 2000;      //dimensions de la texture 
   GLfloat nb_text =10;  //nombre de fois ou la texture est répétée dans l'affichage d'un coté
   glPushMatrix();
   {
    //textures sur les 4 cotés du cube
     for (int i=0;i<4;++i){
       glRotatef(90,0.0,1.0,0.0);
        glBegin(GL_QUADS);
         glTexCoord2f(0, 0);
         glVertex3f(-d,-d,-d);

         glTexCoord2f(nb_text, 0);
         glVertex3f(d,-d,-d);

         glTexCoord2f(nb_text, nb_text);
         glVertex3f(d,d,-d);

         glTexCoord2f(0, nb_text);    
         glVertex3f(-d, d,-d);
        glEnd();
     }
    }
  glPopMatrix(); 

  //textures sur le bas  du cube    
    glRotatef(-90.0,1.0,0.0,0.0);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex3f(-d, -d, -d);

      glTexCoord2f(nb_text, 0);
      glVertex3f(d,-d,-d);

      glTexCoord2f(nb_text, nb_text);
      glVertex3f(d,d,-d);

      glTexCoord2f(0, nb_text);    
      glVertex3f(-d, d, -d);
    glEnd();

  //textures sur le haut  du cube
    glRotatef(180,1.0,0.0,0.0);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex3f(-d, -d, -d);

      glTexCoord2f(nb_text, 0);
      glVertex3f(d,-d,-d);

      glTexCoord2f(nb_text, nb_text);
      glVertex3f(d,d,-d);

      glTexCoord2f(0, nb_text);    
      glVertex3f(-d, d, -d);
    glEnd();  
    glDisable(GL_TEXTURE_2D); 
}


GLvoid frontieres(GLuint texture){  // 3 cubes de sens differents pour ne pas voir les coins

  cube_frontiere(texture);
  glPushMatrix();
  {
   glRotatef(45,1.0,0.0,0.0);
   glRotatef(45,0.0,1.0,0.0);
   cube_frontiere(texture);   
  }
  glPopMatrix();

  glPushMatrix();
  {
   glRotatef(-45,1.0,0.0,0.0);
   glRotatef(-45,0.0,1.0,0.0);
   cube_frontiere(texture);
  }
  glPopMatrix();
}
