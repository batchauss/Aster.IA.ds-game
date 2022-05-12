#include "vaisseau.h"
#include "../rendu/rendu.h"
#include <iostream>

GLfloat longueurTot[5] ={0,0,0,0,0}; //tableau annexe pour le calcul de la longueur du tir
extern std::vector<Asteroide *> asteroides;

Vaisseau::Vaisseau(int nbBalles){
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;
    this->angle[0] = 0;
    this->angle[1] = 0;
    this->vitesse = 0;
    this->longueur=3;  // longueur largeur hauteur pour la hitbox
    this->largeur=3;
    this->hauteur=3;
    this->vie=100;
    this->invincible=false;

    camera = new Camera(posx(), posy() + 10, posz() + 20);
    
    for (int i =0 ; i<nbBalles;++i){
       Tir *t = new Tir(posx(), posy() , posz() );
       t->setTirActif(false);
       tirs.push_back(t); 
    }       

}
Vaisseau::~Vaisseau(){}

void Vaisseau::move(GLfloat x, GLfloat y, GLfloat z){
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;
  

    /*  Si le vaisseau dépasse les limites, il réaparrait de l'autre côté et la caméra aussi*/

    if(posx() > 200){
        this->pos[0] += -400;
        camera->setPos(camera->posx() - 400, camera->posy(), camera->posz());
    }
    else if(posx() < -200){
        this->pos[0] += 400;
        camera->setPos(camera->posx() + 400, camera->posy(), camera->posz());
    }
    if(posy() > 200){
        this->pos[1] += -400;
        camera->setPos(camera->posx(), camera->posy()-400, camera->posz());
    }
    else if(posy() < -200){
        this->pos[1] += 400;
        camera->setPos(camera->posx(), camera->posy()+400, camera->posz());
    }
    if(posz() > 200){
        this->pos[2] += -400;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() - 400);
    }
    else if(posz() < -200){
        this->pos[2] += 400;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() + 400);
    }
}

void Vaisseau::setAngle(GLfloat a){  //angle x z
    this->angle[0] += a;
    a *= 3.14 / 180;

    //Rotation de la caméra
    GLfloat xCam = camera->posx() - posx();
   // GLfloat yCam = camera->posy() - posy();
    GLfloat zCam = camera->posz() - posz();

    camera->setPos(
        xCam * cos(a) + zCam * sin(a) + posx(),  ////faire avec setangle et setangle2 ???
        camera->posy(),
        -xCam * sin(a) + zCam * cos(a) + posz()
    );


     for (unsigned int i = 0; i< tirs.size();++i){ // les munitions se déplacent avec le vaisseau (angle)
        if(!tirs.at(i)->getTirActif()) tirs.at(i)->setAngle(this->angle[0]);
     }
}



void Vaisseau::setAngle2(GLfloat a){  //angle y z
    if((this->angle[1] + a) < 45 && (this->angle[1] + a) > -45){
    this->angle[1] += a;
    a *= 3.14 / 180;

    //GLfloat xCam = camera->posx() - posx();
    //GLfloat yCam = camera->posy() - posy();
    //GLfloat zCam = camera->posz() - posz();

   /* camera->setPos(
        camera->posx(),
        -zCam * sin(a) + yCam * cos(a) + posy(),  
        zCam *  cos(a) + yCam * sin(a) + posz()    
    );*/
    
    

     for (unsigned int i = 0; i< tirs.size();++i){ // les munitions se déplacent avec le vaisseau (angle)
        if(!tirs.at(i)->getTirActif()) tirs.at(i)->setAngle2(this->angle[1]);
     }
    }
}

void Vaisseau::moveForward(){
    GLfloat calculRotationTranslatex = -vitesse * sin(getAngle ()* 3.14 / 180);
    GLfloat calculRotationTranslatey = vitesse * sin(getAngle2() * 3.14 / 180);
    GLfloat calculRotationTranslatez =  -vitesse * cos((getAngle() - getAngle2()) * 3.14 / 180);
 
    if (cos((getAngle2()) * 3.14 / 180) >= 0){
        this->move(calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);    
        camera->move(calculRotationTranslatex,calculRotationTranslatey, calculRotationTranslatez);

        for (unsigned int i = 0; i< tirs.size();++i){  // les munitions se déplacent avec le vaisseau (position)
          if(!tirs.at(i)->getTirActif()){
               tirs.at(i)->move(calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
               tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
          }
        }
    }

    if (cos((getAngle2()) * 3.14 / 180) < 0){
        this->move(-calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);    
        camera->move(-calculRotationTranslatex,calculRotationTranslatey, calculRotationTranslatez);

        for (unsigned int i = 0; i< tirs.size();++i){  // les munitions se déplacent avec le vaisseau (position)
          if(!tirs.at(i)->getTirActif()){
               tirs.at(i)->move(-calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
               tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
          }
        }
    }
}

void Vaisseau::decreaseSpeed(){
    if(vitesse > 0) vitesse *= 0.96;
    else if(vitesse < 0) vitesse *= 0.90;
    
}

GLvoid Vaisseau::tirer(){ // tire une balle 
  for (unsigned int i = 0; i< tirs.size();++i){
    
        GLfloat longueur = longueurTot[i]+ sqrt( (tirs.at(i)->posX()-tirs.at(i)->posXmomentTir())*(tirs.at(i)->posX()-tirs.at(i)->posXmomentTir()) 
                                +(tirs.at(i)->posY()-tirs.at(i)->posYmomentTir())*(tirs.at(i)->posY()-tirs.at(i)->posYmomentTir())
                                +(tirs.at(i)->posZ()-tirs.at(i)->posZmomentTir())*(tirs.at(i)->posZ()-tirs.at(i)->posZmomentTir())  );
    
        GLfloat calculRotationTranslatexTir = -tirs.at(i)->getSpeed() * sin(tirs.at(i)->getAngle() * 3.14 / 180);
        GLfloat calculRotationTranslateyTir = tirs.at(i)->getSpeed() * sin(tirs.at(i)->getAngle2() * 3.14 / 180);
        GLfloat calculRotationTranslatezTir = -tirs.at(i)->getSpeed() * cos(tirs.at(i)->getAngle() * 3.14 / 180);
        tirs.at(i)->move(calculRotationTranslatexTir, calculRotationTranslateyTir, calculRotationTranslatezTir);


    //gestion du franchissage de frontière du tir
    if (tirs.at(i)->posX() > 200){ 
        longueurTot[i]=longueur;
        tirs.at(i)->setPos(tirs.at(i)->posX()-400,tirs.at(i)->posY(),tirs.at(i)->posZ());
        tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
    }
    
    else if (tirs.at(i)->posX() < -200){
        longueurTot[i]=longueur;
         tirs.at(i)->setPos(tirs.at(i)->posX()+400,tirs.at(i)->posY(),tirs.at(i)->posZ());
         tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
    }

    if (tirs.at(i)->posY() > 200){
        longueurTot[i]=longueur;
         tirs.at(i)->setPos(tirs.at(i)->posX(),tirs.at(i)->posY()-400,tirs.at(i)->posZ());
         tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());    
    }
    else if (tirs.at(i)->posY() < -200){
        longueurTot[i]=longueur;
         tirs.at(i)->setPos(tirs.at(i)->posX(),tirs.at(i)->posY()+400,tirs.at(i)->posZ());
         tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
    }

    if (tirs.at(i)->posZ() > 200){
        longueurTot[i]=longueur;
         tirs.at(i)->setPos(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ()-400);
         tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
    }

    else if (tirs.at(i)->posZ() < -200){
        longueurTot[i]=longueur;
         tirs.at(i)->setPos(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ()+400);
         tirs.at(i)->setposmomentTir(tirs.at(i)->posX(),tirs.at(i)->posY(),tirs.at(i)->posZ());
    }
    
    //on remet la balle a sa place si il atteint la portée grace au calcul de la longueur
    if ( longueur > 200 || longueur < -200 ){ 
        longueurTot[i]=0;       
        tirs.at(i)->release(this->posx(),this->posy(),this->posz(),this->getAngle(), this->getAngle2());
    }
  }
}


bool Vaisseau::collisionVaisseauAsteroide(Asteroide * a){
    if(!this->invincible)
    {
        float sphereXDistance = abs(a->posX() - this->posx());
        float sphereYDistance = abs(a->posY() - this->posy());
        float sphereZDistance = abs(a->posZ() - this->posz());

        if (sphereXDistance >= (this->largeur + a->getRayon())) { return false; }
        if (sphereYDistance >= (this->longueur + a->getRayon())) { return false; }
        if (sphereZDistance >= (this->hauteur + a->getRayon())) { return false; }

        if (sphereXDistance < (this->largeur)) { this->vie-=10; return true; } 
        if (sphereYDistance < (this->longueur)) { this->vie-=10; return true; }
        if (sphereZDistance < (this->hauteur)) { this->vie-=10; return true; }

        float cornerDistance_sq = ((sphereXDistance - this->largeur) * (sphereXDistance - this->largeur)) +
                                  ((sphereYDistance - this->longueur) * (sphereYDistance - this->longueur) +
                                  ((sphereYDistance - this->hauteur) * (sphereYDistance - this->hauteur)));

        if (cornerDistance_sq < (a->getRayon() * a->getRayon())){
            this->vie-=10;
            return true;
        }
        else return false;
    }
}

bool Vaisseau::collisionVaisseauVaisseau( Vaisseau *v){
  if(!this->invincible)
  {     
    if(abs(this->posx() - v->posx()) < this->getLargeur() + v->getLargeur())
    {
      
      if(abs(this->posy() - v->posy()) < this->getHauteur() + v->getHauteur())
      {
          
          if(abs(this->posz() - v->posz()) < this->getLongueur() + v->getLongueur())
          {
             return true;
          }
      }
    }
   }

   return false;

}