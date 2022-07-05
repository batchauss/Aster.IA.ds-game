#pragma once

#include "../init.h"
#include "../math/vect.h"
class Camera {
  public :
    Camera(GLfloat x, GLfloat y, GLfloat z);
    ~Camera();

    GLfloat posx(){ return pos[0]; }
    GLfloat posy(){ return pos[1]; }
    GLfloat posz(){ return pos[2]; }

    void setPos(GLfloat x, GLfloat y, GLfloat z) { pos[0] = x; pos[1] = y; pos[2] = z; }
    void move(GLfloat x, GLfloat y, GLfloat z);

public:
	static void posCamFromObj(Vect pos,Vect rot); // Degree unit expected

  private :
    GLfloat pos[3];
};
