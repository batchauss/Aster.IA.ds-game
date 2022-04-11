#include "camera.h"

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