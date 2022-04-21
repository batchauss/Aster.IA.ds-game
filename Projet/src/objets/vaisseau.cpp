#include "vaisseau.h"
#include "../rendu/rendu.h"
#include <iostream>

Vaisseau::Vaisseau(){
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;
    this->angle = 0;
    camera = new Camera(posx(), posy() + 10, posz() + 30);
    tirs = new Tir(posx(), posy() , posz() );
    tirActif = false;
    vitesse = 0;
}
Vaisseau::~Vaisseau(){}

void Vaisseau::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
  

    /*  Si le vaisseau dépasse les limites, il réaparrait de l'autre côté et la caméra aussi*/

    if(posx() > 50){
        this->pos[0] += -100;
        camera->setPos(camera->posx() - 100, camera->posy(), camera->posz());
    }
    else if(posx() < -50){
        this->pos[0] += 100;
        camera->setPos(camera->posx() + 100, camera->posy(), camera->posz());
    }
    if(posz() > 50){
        this->pos[2] += -100;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() - 100);
    }
    else if(posz() < -50){
        this->pos[2] += 100;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() + 100);
    }
}

void Vaisseau::setAngle(GLfloat a){
    this->angle += a;

    a *= 3.14 / 180;

    // Rotation de la caméra
    GLfloat xCam = camera->posx() - posx();
    //GLfloat yCam = camera->posy() - posy();
    GLfloat zCam = camera->posz() - posz();

    camera->setPos(
        xCam * cos(a) + zCam * sin(a) + posx(), 
        camera->posy(),
        -xCam * sin(a) + zCam * cos(a) + posz()
    );

    /*camera->setPos(
        xCam * (cos(angleX)*cos(a) - cos(a)*sin(a)*sin(a)) + yCam * (- cos(a)*sin(a) - cos(a)*cos(a)*sin(a)) + zCam * sin(a)*sin(a) + posx(),
        xCam * (sin(a)*cos(a) + cos(a)*sin(a)*cos(a)) + yCam * (-sin(a)*sin(a) + cos(a)*cos(a)*cos(a)) + zCam * -cos(a)*sin(a) + posy(),
        xCam * sin(a)*sin(a) + yCam * (sin(a)*cos(a)) + zCam * cos(a) + posz()
    );*/

    if(!tirActif) tirs->setAngle(angle);
}

void Vaisseau::moveForward(){
    GLfloat calculRotationTranslatex = -vitesse * sin(getAngle() * 3.14 / 180);
    //GLfloat calculRotationTranslatey = vitesse * sin(getAngle() * 3.14 / 180);
    GLfloat calculRotationTranslatez =  -vitesse * cos(getAngle() * 3.14 / 180);
    this->move(calculRotationTranslatex, 0, calculRotationTranslatez);
    camera->move(calculRotationTranslatex, 0, calculRotationTranslatez);
    if(!tirActif) tirs->move(calculRotationTranslatex, 0, calculRotationTranslatez);
}

void Vaisseau::decreaseSpeed(){
    if(vitesse > 0) vitesse *= 0.96;
}

GLvoid Vaisseau::tirer(){ // tire une balle 
     GLfloat longueur = sqrt( (tirs->posX()-posx())*(tirs->posX()-posx()) 
                             +(tirs->posY()-posy())*(tirs->posY()-posy())
                             +(tirs->posZ()-posz())*(tirs->posZ()-posz())  );

     GLfloat calculRotationTranslatexTir = -tirs->getSpeed() * sin(tirs->getAngle() * 3.14 / 180);
     GLfloat calculRotationTranslatezTir =  -tirs->getSpeed() * cos(tirs->getAngle() * 3.14 / 180);
     tirs->move(calculRotationTranslatexTir, 0, calculRotationTranslatezTir);

    //on remet la balle a sa place si il atteint la portée
    if ( longueur > 20 ){
        tirs->setSpeed(0);   
        tirs->setPos(this->posx(),this->posy(),this->posz());
        tirActif = false;
        //tirs->setAngle(getAngle());
    }
} 