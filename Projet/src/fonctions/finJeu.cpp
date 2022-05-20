#include "finJeu.h"

GLvoid finJeu(GLfloat score, std::string pseudo){
    writeScore(pseudo, score);
    renduFin();
}