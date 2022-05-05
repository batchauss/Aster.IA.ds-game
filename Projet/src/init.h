#ifndef __INIT
#define __INIT

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>


GLvoid Redimensionne(GLsizei width, GLsizei height);
int notre_init(int argc, char** argv, void (*Modelisation)());

void initialise();

int Rand(int a, int b);
void remplissageTableauR();
void creationAsteroides();

#endif