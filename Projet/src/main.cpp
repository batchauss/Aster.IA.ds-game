#include "init.h"
#include "asteroide.h"
#include "vaisseau.h"

extern GLvoid VM_init();

extern GLfloat r[50][3]; // tableau de coordonnées aléatoires des astéroides
extern GLfloat angle[50];  // tableau d'angle pour la rotation aléatoire des astéroides avant déplacement

Vaisseau * vaisseau = new Vaisseau();

//variables pour les déplacements des astéroides
int temps;
int frames=0,fps=0,temps_suivant=0;
int temps_depuis_prec_calcul =0;
int frequence_de_calcul_fps=100;

float vitesse_reelle=0.0;


GLvoid spawn_asteroid(){ // première apparition des astéroides

 for(int i=0;i<50;++i){
  
       Asteroide  *a = new Asteroide(r[i][1],r[i][2],r[i][3],1,10,10);
      
       r[i][0] += 0.2  * sin(angle[i] *3.14 /180);  
       r[i][1] += 0.2  * sin(angle[i] *3.14 /180);  
       r[i][2]  += -0.2  * cos(angle[i] *3.14 /180 );


    // si la frontiere est franchie, l'asteroide réapparait à l'opposé de la map
       if (r[i][0] >=50) r[i][0] -= 100;
       else if (r[i][1] >=50) r[i][1] -= 100;
       else if (r[i][2] >=50) r[i][2] -= 100;

       else if (r[i][0] <=-50) r[i][0] += 100;
       else if (r[i][1] <=-50) r[i][1] += 100;
       else if (r[i][2] <=-50) r[i][2] += 100;

       a->renduAsteroide();
       delete  a;
 }
}

GLvoid Modelisation()
{
  
  VM_init();

 /////// test déplacement des astéroides //////////
  frames+=1;
  temps_suivant = glutGet(GLUT_ELAPSED_TIME);
  int temps_entre_2 = temps_suivant-temps;
  temps_depuis_prec_calcul+=temps_entre_2;

  if(temps_depuis_prec_calcul>=frequence_de_calcul_fps){
      temps_depuis_prec_calcul=0;
      fps=frames*100/frequence_de_calcul_fps;
      frames=0;
      vitesse_reelle=10/((float)fps);
  }
  temps=temps_suivant;
  //////////////////////////////////////////////////

  
  glFrontFace(GL_CW);
         
  spawn_asteroid();
  glScalef(1, 1, 1);
    
  vaisseau->modelisation();
  
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}
