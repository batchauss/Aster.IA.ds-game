#include "init.h"
#include "vaisseau.h"
#include "frontiere.h"
#include "camera.h"
#include"frames.h"

extern GLvoid VM_init();

Vaisseau * vaisseau = new Vaisseau();


GLvoid Modelisation()
{  
  VM_init();

  spawn_asteroid();      
  vaisseau->modelisation(); 

  frontieres();
  
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
