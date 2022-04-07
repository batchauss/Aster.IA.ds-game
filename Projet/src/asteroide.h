#include "init.h"
#include "math.h"

class Asteroide {
    
     public :
        Asteroide( GLfloat x, GLfloat y, GLfloat z, GLfloat rad, GLfloat sli, GLfloat sta);
        ~Asteroide();
        GLvoid renduAsteroide();

        GLfloat _angle;

    private:
        GLfloat _x;
        GLfloat _y;
        GLfloat _z;
        
        GLfloat _radius;
        GLfloat _slide;
        GLfloat _stack;
        

};