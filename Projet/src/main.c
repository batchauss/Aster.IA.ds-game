#include "init.h"
extern GLvoid VM_init();

GLvoid Modelisation()
{
  VM_init();
  
 glutSolidCone(1,10,100,1);

  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
