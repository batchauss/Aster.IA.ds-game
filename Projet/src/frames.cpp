#include"frames.h"


int temps;
int frames=0,fps=0,temps_suivant=0;
int temps_depuis_prec_calcul =0;
int frequence_de_calcul_fps=100;

float vitesse_reelle=0.0;

void frequence(){

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
}

