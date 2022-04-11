#include "rendu.h"
#include "iostream"

void renduVaisseau(Vaisseau * vaisseau){
    glPushMatrix();
        glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
        glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
        glutSolidCone(1, 5, 30, 30);
    glPopMatrix();
}

void renduCamera(Vaisseau * vaisseau){
    gluLookAt(vaisseau->camera->posx(), vaisseau->camera->posy(), vaisseau->camera->posz(), vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}