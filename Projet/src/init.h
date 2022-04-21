#ifndef __INIT
#define __INIT

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 

#include "objets/asteroide.h"
#include "fonctions/ppm.h"

int notre_init(int argc, char** argv, void (*Modelisation)());
GLvoid Redimensionne(GLsizei width, GLsizei height);
GLvoid spawn_asteroid();

#endif