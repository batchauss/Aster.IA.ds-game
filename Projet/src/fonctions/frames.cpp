#include"frames.h"


int temps;
int temps_depuis_le_precedent_calcul = 0;

GLfloat acceleration = 0;
GLfloat vitesse_reelle = 0;
int frames = 0, fps = 0;

GLfloat temps_acceleration_reelle(GLfloat vitesse){
  frames += 1;
  temps_depuis_le_precedent_calcul += glutGet(GLUT_ELAPSED_TIME) - temps;
  if(temps_depuis_le_precedent_calcul >= 50){
    temps_depuis_le_precedent_calcul = 0;
    fps = frames * 10;
    frames = 0;
    vitesse_reelle = vitesse / 2 / ((GLfloat) fps);
  }
  temps = glutGet(GLUT_ELAPSED_TIME);
  acceleration += vitesse_reelle;
  return acceleration;
}

