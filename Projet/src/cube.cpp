#include "cube.h"
#include "math.h"

struct normale {
    float x;
    float y;
    float z;
};

Cube::Cube(){
    GLfloat s[8][3] = {{-0.5, -0.5, 0.5},{0.5, -0.5, 0.5},{0.5, 0.5, 0.5},{-0.5, 0.5, 0.5},{0.5, -0.5, -0.5},{-0.5, -0.5, -0.5},{-0.5, 0.5, -0.5},{0.5, 0.5, -0.5}};
    GLfloat f[6][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}};
    
    for(int i=0; i<8; i++){
        for(int j=0; j<3; j++) this->sommets[i][j] = s[i][j];
    }
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++) this->faces[i][j] = f[i][j];
    }
}

void Cube::calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z, struct normale * normale) {
    float v0x = s2x - s1x;
    float v0y = s2y - s1y;
    float v0z = s2z - s1z;
    float v1x = s0x - s1x;
    float v1y = s0y - s1y;
    float v1z = s0z - s1z;
    normale->x = (v0y * v1z) - (v0z *v1y);
    normale->y = (v0z * v1x) - (v0x *v1z);
    normale->z = (v0x * v1y) - (v0y *v1x);
    float norme = sqrtf(normale->x * normale->x + normale->y * normale->y + normale->z * normale->z);
    normale->x = normale->x / norme;
    normale->y = normale->y / norme;
    normale->z = normale->z / norme;
}

void Cube::rendu_cube(){

  struct normale v1;

  for(int i=0; i<=5; i++){
    switch(i) {
      case 1 : calcul_normale(this->sommets[0][0], this->sommets[0][1], this->sommets[0][2], this->sommets[1][0], this->sommets[1][1], this->sommets[1][2], this->sommets[2][0], this->sommets[2][1], this->sommets[2][2], &v1);
      case 2 : calcul_normale(this->sommets[4][0], this->sommets[4][1], this->sommets[4][2], this->sommets[5][0], this->sommets[5][1], this->sommets[5][2], this->sommets[6][0], this->sommets[6][1], this->sommets[6][2], &v1);
      case 3 : calcul_normale(this->sommets[1][0], this->sommets[1][1], this->sommets[1][2], this->sommets[4][0], this->sommets[4][1], this->sommets[4][2], this->sommets[7][0], this->sommets[7][1], this->sommets[7][2], &v1);
      case 4 : calcul_normale(this->sommets[0][0], this->sommets[0][1], this->sommets[0][2], this->sommets[3][0], this->sommets[3][1], this->sommets[3][2], this->sommets[6][0], this->sommets[6][1], this->sommets[6][2], &v1);
      case 5 : calcul_normale(this->sommets[2][0], this->sommets[2][1], this->sommets[2][2], this->sommets[7][0], this->sommets[7][1], this->sommets[7][2], this->sommets[6][0], this->sommets[6][1], this->sommets[6][2], &v1);
      case 6 : calcul_normale(this->sommets[1][0], this->sommets[1][1], this->sommets[1][2], this->sommets[0][0], this->sommets[0][1], this->sommets[0][2], this->sommets[5][0], this->sommets[5][1], this->sommets[5][2], &v1);
    }
    glBegin(GL_QUADS);
    glNormal3f(v1.x, v1.y, v1.z);
    for(int j=0; j<=3; j++){
      glVertex3f(this->sommets[this->faces[i][j]][0] , this->sommets[this->faces[i][j]][1], this->sommets[this->faces[i][j]][2]);
    }
    glEnd();
  }
}