#include "camera.h"

Camera::Camera(Vaisseau * v){
    this->pos[0] = v->posx();
    this->pos[1] = v->posy() + 10;
    this->pos[2] = v->posz() + 30;
    this->vaisseau = v;
}
Camera::~Camera(){}

void Camera::lookAt(){
    gluLookAt(this->posx(), this->posy(), this->posz(), vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}

void Camera::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;

    /*  Si la caméra dépasse les limites, il réaparrait de l'autre côté */

    if(posx() > 50) this->pos[0] = -50;
    else if(posx() < -50) this->pos[0] = 50;

    if(posz() > 50) this->pos[2] = -50;
    else if(posz() < -50) this->pos[2] = 50;
}

void Camera::rotation(GLfloat angle){
    GLfloat xCam = posx() - vaisseau->posx();
    GLfloat zCam = posz() - vaisseau->posz();
    setPos(
        xCam * cos(angle * 3.14 / 180) + zCam * sin(angle * 3.14 / 180) + vaisseau->posx(), 
        posy(),
        xCam * sin(angle * 3.14 / 180) + zCam * cos(angle * 3.14 / 180) + vaisseau->posz()
    );
}