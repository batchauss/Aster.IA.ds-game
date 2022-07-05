#include "../../includes/constant.h"

#include "decor.h"

GLvoid decorPlanetes()
{
	glNewList(9, GL_COMPILE_AND_EXECUTE);

	// planete avec anneau
	glPushMatrix();
	glTranslatef(background::P1_TRANSLATE_X, background::P1_TRANSLATE_Y, background::P1_TRANSLATE_Z);
	glScalef(background::P1_SCALE_X, background::P1_SCALE_Y, background::P1_SCALE_Z);
	// planete
	glColor3f(background::P1_RED, background::P1_GREEN, background::P1_BLUE);
	glutSolidSphere(background::P1_SPHERE_RADIUS, background::P1_SPHERE_SLICES, background::P1_SPHERE_STACKS);
	// anneau
	glRotatef(background::P1_RING_ROTATE_ANGLE, background::P1_RING_ROTATE_X, background::P1_RING_ROTATE_Y, background::P1_RING_ROTATE_Z);
	glScalef(background::P1_RING_SCALE_X, background::P1_RING_SCALE_Y, background::P1_RING_SCALE_Z);
	glColor3f(background::P1_RING_RED, background::P1_RING_GREEN, background::P1_RING_BLUE);
	glutSolidTorus(background::P1_RING_INNER_RADIUS, background::P1_RING_OUTER_RADIUS, background::P1_RING_NSIDES, background::P1_RING_RINGS);
	glPopMatrix();

	// planete anneau bleu
	glPushMatrix();
	glTranslatef(background::P2_TRANSLATE_X, background::P2_TRANSLATE_Y, background::P2_TRANSLATE_Z);
	glScalef(background::P2_SCALE_X, background::P2_SCALE_Y, background::P2_SCALE_Z);
	// planete
	glColor3f(background::P2_RED, background::P2_GREEN, background::P2_BLUE);
	glutSolidSphere(background::P2_SPHERE_RADIUS, background::P2_SPHERE_SLICES, background::P2_SPHERE_STACKS);
	// anneau
	glRotatef(background::P2_RING_ROTATE_ANGLE, background::P2_RING_ROTATE_X, background::P2_RING_ROTATE_Y, background::P2_RING_ROTATE_Z);
	glScalef(background::P2_RING_SCALE_X, background::P2_RING_SCALE_Y, background::P2_RING_SCALE_Z);
	glColor3f(background::P2_RING_RED, background::P2_RING_GREEN, background::P2_RING_BLUE);
	glutSolidTorus(background::P2_RING_INNER_RADIUS, background::P2_RING_OUTER_RADIUS, background::P2_RING_NSIDES, background::P2_RING_RINGS);
	glPopMatrix();

	glEndList();
}