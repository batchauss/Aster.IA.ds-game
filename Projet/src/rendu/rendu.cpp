#include "rendu.h"
#include<iostream>

void renduAsteroide(Asteroide * a){
     glPushMatrix();
   {
    glColor3f(0.5,0.5,0.5);
    glTranslatef(a->posX(),a->posY(),-a->posZ());    
    glutSolidSphere(a->getRad(),a->getSli(),a->getSta());
   }
   glPopMatrix();
}

void renduVaisseau(Vaisseau * vaisseau){
    glPushMatrix();
    {
        glColor3f(1, 1, 1);
        glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
        glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
        glutSolidCone(1, 5, 30, 30);
    }
    glPopMatrix();
}

void renduCamera(Vaisseau * vaisseau){
    gluLookAt(vaisseau->camera->posx(), vaisseau->camera->posy(), vaisseau->camera->posz(), vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}

void renduTir( Tir * t){
     glPushMatrix();
       {  
        glColor3f(1, 1, 0);
        glTranslatef(t->posX(), t->posY(), t->posZ() );
        glRotatef(t->getAngle(),0.0,1.0,0.0);
        glScalef(0.1,0.1,1);
        glutSolidCube(1);    
       }
    glPopMatrix();
}


