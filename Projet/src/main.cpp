#include "init.h"
#include "vaisseau.h"
#include "frames.h"
#include "frontiere.h"

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
