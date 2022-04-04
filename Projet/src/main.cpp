#include "init.h"
extern GLvoid VM_init();

GLvoid Modelisation()
{
  VM_init();
  
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
