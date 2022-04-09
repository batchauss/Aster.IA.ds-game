#ifndef CAMERA_H
#define CAMERA_H

#include "init.h"
#include "vaisseau.h"

class Camera {
  public : 
    Camera(Vaisseau * v);
    ~Camera();

    GLfloat posx(){ return pos[0]; }
    GLfloat posy(){ return pos[1]; }
    GLfloat posz(){ return pos[2]; }

    void setPos(GLfloat x, GLfloat y, GLfloat z) { pos[0] = x; pos[1] = y; pos[2] = z; }
    void move(GLfloat x, GLfloat y, GLfloat z);
    void rotation(GLfloat angle);
    void lookAt();

  private :
    GLfloat pos[3];
    Vaisseau * vaisseau;
};

#endif