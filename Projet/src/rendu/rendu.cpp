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

void renduObjVaisseau(struct objmtl v, Vaisseau * vaisseau){
    glPushMatrix();
    {
        glTranslatef(vaisseau->posx(), vaisseau->posy(), vaisseau->posz());
        glRotatef(180 + vaisseau->getAngle(), 0, 1, 0);
        glScalef(0.3, 0.3, 0.3);
        for(const auto& face : v.obj.faces){
            glBegin(GL_POLYGON);

            int indexMat = face.at(face.size() - 1).at(0);
            GLfloat shin = v.materiaux.at(indexMat-1).Ns;
            glMaterialfv(GL_FRONT, GL_SHININESS, &shin);

            glNormal3f(v.obj.vn.at(face.at(0).at(2)-1).at(0), v.obj.vn.at(face.at(0).at(2)-1).at(1), v.obj.vn.at(face.at(0).at(2)-1).at(2));
            glColor3f(v.materiaux.at(indexMat-1).Kd.at(0), v.materiaux.at(indexMat-1).Kd.at(1), v.materiaux.at(indexMat-1).Kd.at(2));
            for(const auto& vertex : face) {
                glVertex3f(v.obj.v.at(vertex.at(0) - 1).at(0), v.obj.v.at(vertex.at(0) - 1).at(1), v.obj.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd();
        }
    }
    glPopMatrix();
}


