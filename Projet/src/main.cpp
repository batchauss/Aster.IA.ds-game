#include"init.h"
#include "vaisseau.h"
#include"frames.h"

extern GLvoid VM_init();

Vaisseau * vaisseau = new Vaisseau();


GLvoid Modelisation()
{  
  VM_init();
  spawn_asteroid();      
   
  vaisseau->modelisation(); 
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
