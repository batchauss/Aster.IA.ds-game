#ifndef __INIT
#define __INIT

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include<iostream>
#include <QMainWindow>

GLvoid Redimensionne();
int notre_init(int argc, char** argv, void (*Modelisation)(), QMainWindow * mw);

void initialise();

int Rand(int a, int b);
void remplissageTableauR();
void creationAsteroides();

#endif