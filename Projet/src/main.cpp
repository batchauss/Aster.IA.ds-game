#include "init.h"
#include "fonctions/frontiere.h"
#include "fonctions/frames.h"
#include "fonctions/obj.h"

extern GLvoid VM_init();
extern GLuint texture[5];

GLvoid Modelisation()
{  
  VM_init();

  frontieres(texture[0]);

  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
