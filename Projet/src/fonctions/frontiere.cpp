#include "frontiere.h"

extern GLuint texture[]; // tableau contenant les differentes textures

GLvoid cube_frontiere(){  //un cube entouré de textures 

 glBindTexture(GL_TEXTURE_2D, texture[0]);
 glEnable(GL_TEXTURE_2D);
  
   GLfloat d = 2000;      //dimensions de la texture 
   GLfloat nb_text =15;  //nombre de fois ou la texture est répétée dans l'affichage d'un coté
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


GLvoid frontieres(){  // 3 cubes de sens differents pour ne pas voir les coins

  cube_frontiere();
  glPushMatrix();
  {
   glRotatef(45,1.0,0.0,0.0);
   glRotatef(45,0.0,1.0,0.0);
   cube_frontiere();   
  }
  glPopMatrix();

  glPushMatrix();
  {
   glRotatef(-45,1.0,0.0,0.0);
   glRotatef(-45,0.0,1.0,0.0);
   cube_frontiere();
  }
  glPopMatrix();
}
