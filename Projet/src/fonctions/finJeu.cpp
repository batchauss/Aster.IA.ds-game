#include "finJeu.h"

extern bool finActivated;
extern GLfloat tempsDef;

bool writeOnce = false;

GLvoid finJeu(GLfloat score, std::string pseudo){
    if(!writeOnce){
        writeScore(pseudo, score);
        writeOnce = true;
    }
    tempsDef = 0;
    renduFin();
}