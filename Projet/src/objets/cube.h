#ifndef CUBE_H
#define CUBE_H

#include "../init.h"

class Cube {
  public : 
    Cube();
    void rendu_cube();

  protected :
    GLfloat sommets[8][3];
    int faces[6][4];

    void calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z, struct normale * normale);
};

#endif 