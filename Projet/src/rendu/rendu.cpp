#include "rendu.h"

void renduAsteroide(Asteroide * a){
     glPushMatrix();
   {
    glColor3f(0.5,0.5,0.5);
    glTranslatef(a->posX(),a->posY(),-a->posZ());    
    glutSolidSphere(a->getRad(),a->getSli(),a->getSta());
   }
   glPopMatrix();
}

void renduCamera(Vaisseau * vaisseau){
    gluLookAt(vaisseau->camera->posx(), vaisseau->camera->posy(), vaisseau->camera->posz(), vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}

void renduTir(Tir * t){
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

void renduObjVaisseau(struct obj v, Vaisseau * vaisseau){
    glPushMatrix();
    {
        glColor3f(1, 1, 1);
        glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
        glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);     // rotation pour déplacement gauche/droite 
        glRotatef(- vaisseau->getAngle2(), 1, 0, 0);  // rotation pour deplacement haut/bas 
        glScalef(0.3, 0.3, 0.3);
        for(const auto& face : v.faces){
            glBegin(GL_POLYGON);
            for(const auto& vertex : face) {
                glVertex3f(v.v.at(vertex.at(0) - 1).at(0), v.v.at(vertex.at(0) - 1).at(1), v.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd(); 
        }
    }
    glPopMatrix();
}


