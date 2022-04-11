#ifndef __ACTIONS
#define __ACTIONS

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "touches.h"
#include "math.h"
#include "objets/camera.h"
#include "objets/vaisseau.h"

void touche(unsigned char key, int x, int y);
void releaseTouche(unsigned char key, int x, int y);
void touche_speciale(int key, int x, int y);

#endif