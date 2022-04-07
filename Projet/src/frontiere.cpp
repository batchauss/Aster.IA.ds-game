#include "frontiere.h"

GLvoid frontieres(){ //  un grand cube qui va représenter l'univers fermé du jeu


    glFrontFace(GL_CW);
    glColor3f(1.0,1.0,1.0);
    glutSolidCube(100);

    //on mettra une texture a chaque face du cube (pour l'instant cube blanc)
}
