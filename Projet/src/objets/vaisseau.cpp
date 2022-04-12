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

void Vaisseau::setAngle(GLfloat angle){ 
    this->angle += angle;    // Modification de l'angle du vaisseau

    // Rotation de la caméra
    GLfloat xCam = camera->posx() - posx();
    GLfloat zCam = camera->posz() - posz();
    camera->setPos(
        xCam * cos(angle * 3.14 / 180) + zCam * sin(angle * 3.14 / 180) + posx(), 
        camera->posy(),
        -xCam * sin(angle * 3.14 / 180) + zCam * cos(angle * 3.14 / 180) + posz()
    );

    tirs->setAngle(tirs->getAngle() + angle);
}

void Vaisseau::moveForward(){
    GLfloat calculRotationTranslatex = -vitesse * sin(getAngle() * 3.14 / 180);
    GLfloat calculRotationTranslatez =  -vitesse * cos(getAngle() * 3.14 / 180);
    this->move(calculRotationTranslatex, 0, calculRotationTranslatez);
    camera->move(calculRotationTranslatex, 0, calculRotationTranslatez);
    tirs->move(calculRotationTranslatex, 0, calculRotationTranslatez);
}

void Vaisseau::decreaseSpeed(){
    if(vitesse > 0) vitesse *= 0.96;
}


GLvoid Vaisseau::tirer(){ // tire une balle quand on appuie sur ESPACE (non terminé)

     GLfloat calculRotationTranslatex = -tirs->getSpeed() * sin(getAngle() * 3.14 / 180);
     GLfloat calculRotationTranslatez =  -tirs->getSpeed() * cos(getAngle() * 3.14 / 180);
     tirs->move(calculRotationTranslatex, 0, calculRotationTranslatez);
     std::cout<<tirs->posZ() << " ";

    if ( (tirs->posZ()- this->posz()) <  -20 ){
        tirs->setSpeed(0);
        tirs->setPos(this->posx(),this->posy(),this->posz());
    } 
} 