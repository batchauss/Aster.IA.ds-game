#include"texture.h"

extern GLuint texture[5];

GLvoid Parametres_texture(GLuint i, TEXTURE_STRUCT  * text){


   
  glGenTextures(i+1, &texture[i]);
  glBindTexture(GL_TEXTURE_2D, texture[i]);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, text->width, text->height, 0, GL_RGB, GL_UNSIGNED_BYTE, text->data);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


  
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);  
  glBindTexture(GL_TEXTURE_2D, 0);

  
}