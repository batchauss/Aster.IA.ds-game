#include "camera.h"

#include <cmath>
#include <GL/glu.h>

void Camera::posCamFromObj(Vect playerPosition,Vect rotDeg) {

	// Degree to Rad
	Vect rotRad = rotDeg * 3.14 / 180;

	//
	Vect playerDirection(
	     -1 * sin(rotRad.getYaw()) * cos(rotRad.getPitch()) ,
	          sin(rotRad.getPitch()) ,
 	 	-1 * cos(rotRad.getYaw()) * cos(rotRad.getPitch())
	);

	Vect cameraPosition = playerPosition - (playerDirection * 25);

	float tempPitch = abs((int) rotDeg.getPitch() ) % 360;

	Vect upDirection = Vect(
		0,
		( (tempPitch > 90) && (tempPitch < 270) ) ? -1 : 1,
		0
	);

	// Setup camera
	gluLookAt(
		cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		playerPosition.getX(), playerPosition.getY(), playerPosition.getZ(),
		upDirection.getX(), upDirection.getY(), upDirection.getZ()
	);
}
Camera::Camera(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] = x;
    this->pos[1] = y;
    this->pos[2] = z;
}
Camera::~Camera(){}

void Camera::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
}
