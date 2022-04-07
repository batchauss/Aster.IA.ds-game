#include "init.h"
extern void build_cube();
extern GLvoid VM_init();

GLvoid Modelisation()
{
  VM_init();

  glPushMatrix();
    glFrontFace(GL_CW);
    //glScalef(100, 100, 100);
    //build_cube();
  glPopMatrix();
  
 //glutSolidCone(1,10,100,1);

  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
