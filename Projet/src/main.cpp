#include "init.h"
#include "fonctions/frontiere.h"
#include "fonctions/frames.h"
#include "fonctions/obj.h"

extern GLvoid VM_init();

GLvoid Modelisation()
{  
  VM_init();
  spawn_asteroid();
  frontieres();
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
