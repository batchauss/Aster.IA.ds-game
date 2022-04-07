#include "init.h"
#include "cube.h"
#include "vaisseau.h"
extern GLvoid VM_init();

Vaisseau * vaisseau = new Vaisseau();

GLvoid Modelisation()
{
  VM_init();

    vaisseau->modelisation();
  
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
