#include "vaisseau.h"
#include "../rendu/rendu.h"
#include <iostream>

Vaisseau::Vaisseau(){
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;
    this->angle = 0;
    camera = new Camera(posx(), posy() + 10, posz() + 30);
    
    for (int i =0 ; i<5;++i){
       Tir *t = new Tir(posx(), posy() , posz() );
       t->setTirActif(false);
       tirs.push_back(t); 
    }       
    vitesse = 0;
}
Vaisseau::~Vaisseau(){}

void Vaisseau::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
  

    /*  Si le vaisseau dépasse les limites, il réaparrait de l'autre côté et la caméra aussi*/

    if(posx() > 100){
        this->pos[0] += -200;
        camera->setPos(camera->posx() - 200, camera->posy(), camera->posz());
    }
    else if(posx() < -100){
        this->pos[0] += 200;
        camera->setPos(camera->posx() + 200, camera->posy(), camera->posz());
    }
    if(posz() > 100){
        this->pos[2] += -200;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() - 200);
    }
    else if(posz() < -100){
        this->pos[2] += 200;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() + 200);
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
     for (unsigned int i = 0; i< tirs.size();++i){ // les munitions se déplacent avec le vaisseau (angle)
        if(!tirs.at(i)->getTirActif()) tirs.at(i)->setAngle(tirs.at(i)->getAngle() + angle);
     }
}

void Vaisseau::moveForward(){
    GLfloat calculRotationTranslatex = -vitesse * sin(getAngle() * 3.14 / 180);
    GLfloat calculRotationTranslatez =  -vitesse * cos(getAngle() * 3.14 / 180);
    this->move(calculRotationTranslatex, 0, calculRotationTranslatez);
    camera->move(calculRotationTranslatex, 0, calculRotationTranslatez);
  
   for (unsigned int i = 0; i< tirs.size();++i){  // les munitions se déplacent avec le vaisseau (position)
        if(!tirs.at(i)->getTirActif()) tirs.at(i)->move(calculRotationTranslatex, 0, calculRotationTranslatez);
   }
}

void Vaisseau::decreaseSpeed(){
    if(vitesse > 0) vitesse *= 0.96;
}


GLvoid Vaisseau::tirer(){ // tire une balle 
  for (unsigned int i = 0; i< tirs.size();++i){
        GLfloat longueur = sqrt( (tirs.at(i)->posX()-posx())*(tirs.at(i)->posX()-posx()) 
                             +(tirs.at(i)->posY()-posy())*(tirs.at(i)->posY()-posy())
                             +(tirs.at(i)->posZ()-posz())*(tirs.at(i)->posZ()-posz())  );
    
        GLfloat calculRotationTranslatexTir = -tirs.at(i)->getSpeed() * sin(tirs.at(i)->getAngle() * 3.14 / 180);
        GLfloat calculRotationTranslatezTir = -tirs.at(i)->getSpeed() * cos(tirs.at(i)->getAngle() * 3.14 / 180);
        tirs.at(i)->move(calculRotationTranslatexTir, 0, calculRotationTranslatezTir);

    //on remet la balle a sa place si il atteint la portée grace au calcul de la longueur
    if ( longueur > 20 ){        
        //tirs.insert(tirs.begin(),tirs.at(i)); 
        tirs.at(i)->setSpeed(0);   
        tirs.at(i)->setPos(this->posx(),this->posy(),this->posz());
        tirs.at(i)->setTirActif(false);
        tirs.at(i)->setAngle(getAngle()); 
        
        //tirs.pop_back();     
    }
  }

} 