#ifndef __INIT
#define __INIT

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include<iostream>


GLvoid Redimensionne(GLsizei width, GLsizei height);
int notre_init(int argc, char** argv, void (*Modelisation)());

void initialise();
void reinitialise();

float Rand(float a, float b);
void remplissageTableauR();
void creationAsteroides();

#endif