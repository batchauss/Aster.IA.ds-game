#include "../../includes/constant.h"

#include "vaisseau.h"
#include "../rendu/rendu.h"
#include <iostream>

GLfloat longueurTot[5] = {0, 0, 0, 0, 0}; // tableau annexe pour le calcul de la longueur du tir
extern std::vector<Asteroide *> asteroides;

Vaisseau::Vaisseau(int nbBalles)
{
    this->pos[0] = gameconf::PLAYER_BASE_POSITION;
    this->pos[1] = gameconf::PLAYER_BASE_POSITION;
    this->pos[2] = gameconf::PLAYER_BASE_POSITION;
    this->angle[0] = gameconf::PLAYER_BASE_ROTATION;
    this->angle[1] = gameconf::PLAYER_BASE_ROTATION;
    this->vitesse = gameconf::PLAYER_BASE_SPEED;
    this->longueur = gameconf::PLAYER_LENGTH; // longueur largeur hauteur pour la hitbox
    this->largeur = gameconf::PLAYER_WIDTH;
    this->hauteur = gameconf::PLAYER_HEIGHT;
    this->vie = gameconf::PLAYER_BASE_LIFE;
    this->invincible = gameconf::PLAYER_SPAWNING_INVINCIBILITY;
    this->statut = "intact";

    camera = new Camera(posx(), posy() + gameconf::CAMERA_Y, posz() + gameconf::CAMERA_Z);

    for (int i = 0; i < nbBalles; ++i)
    {
        Tir *t = new Tir(posx(), posy(), posz());
        t->setTirActif(false);
        tirs.push_back(t);
    }
}

void Vaisseau::move(GLfloat x, GLfloat y, GLfloat z)
{
    this->pos[0] += x;
    this->pos[1] += y;
    this->pos[2] += z;

    /*  Si le vaisseau dépasse les limites, il réaparrait de l'autre côté et la caméra aussi*/

    if (posx() > gameconf::POSITIVE_AREA_SIZE)
    {
        this->pos[0] -= gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx() - gameconf::PLAYER_OUT_OF_ARENA_RELOCATION, camera->posy(), camera->posz());
    }
    else if (posx() < gameconf::NEGATIVE_AREA_SIZE)
    {
        this->pos[0] += gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx() + gameconf::PLAYER_OUT_OF_ARENA_RELOCATION, camera->posy(), camera->posz());
    }
    if (posy() > gameconf::POSITIVE_AREA_SIZE)
    {
        this->pos[1] -= gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx(), camera->posy() - gameconf::PLAYER_OUT_OF_ARENA_RELOCATION, camera->posz());
    }
    else if (posy() < gameconf::NEGATIVE_AREA_SIZE)
    {
        this->pos[1] += gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx(), camera->posy() + gameconf::PLAYER_OUT_OF_ARENA_RELOCATION, camera->posz());
    }
    if (posz() > gameconf::POSITIVE_AREA_SIZE)
    {
        this->pos[2] -= gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() - gameconf::PLAYER_OUT_OF_ARENA_RELOCATION);
    }
    else if (posz() < gameconf::NEGATIVE_AREA_SIZE)
    {
        this->pos[2] += gameconf::PLAYER_OUT_OF_ARENA_RELOCATION;
        camera->setPos(camera->posx(), camera->posy(), camera->posz() + gameconf::PLAYER_OUT_OF_ARENA_RELOCATION);
    }
}

void Vaisseau::setAngle(GLfloat a)
{ // angle x z
    this->angle[0] += a;
    a *= gameconf::DEG2RAD;

    // Rotation de la caméra
    GLfloat xCam = camera->posx() - posx();
    // GLfloat yCam = camera->posy() - posy();
    GLfloat zCam = camera->posz() - posz();

    camera->setPos(
        xCam * cos(a) + zCam * sin(a) + posx(), ////faire avec setangle et setangle2 ???
        camera->posy(),
        -xCam * sin(a) + zCam * cos(a) + posz());

    for (unsigned int i = 0; i < tirs.size(); ++i)
    { // les munitions se déplacent avec le vaisseau (angle)
        if (!tirs.at(i)->getTirActif())
            tirs.at(i)->setAngle(this->angle[0]);
    }
}

void Vaisseau::setAngle2(GLfloat a)
{ // angle y z
    if ((this->angle[1] + a) < gameconf::PLAYER_PITCH_LIMIT && (this->angle[1] + a) > -gameconf::PLAYER_PITCH_LIMIT)
    {
        this->angle[1] += a;
        a *= gameconf::DEG2RAD;

        /* GLfloat xCam = camera->posx() - posx();
         GLfloat yCam = camera->posy() - posy();
         GLfloat zCam = camera->posz() - posz();

         camera->setPos(
             camera->posx(),
             -zCam * sin(a) + yCam * cos(a) + posy(),
             zCam *  cos(a) + yCam * sin(a) + posz()
         );


     */
        for (unsigned int i = 0; i < tirs.size(); ++i)
        { // les munitions se déplacent avec le vaisseau (angle)
            if (!tirs.at(i)->getTirActif())
                tirs.at(i)->setAngle2(this->angle[1]);
        }
    }
}

void Vaisseau::moveForward()
{
    GLfloat calculRotationTranslatex = -vitesse * sin(getAngle() * gameconf::DEG2RAD);
    GLfloat calculRotationTranslatey = vitesse * sin(getAngle2() * gameconf::DEG2RAD);
    GLfloat calculRotationTranslatez = -vitesse * cos((getAngle()) * gameconf::DEG2RAD);

    if (cos((getAngle2()) * gameconf::DEG2RAD) >= 0)
    {
        this->move(calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
        camera->move(calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);

        for (unsigned int i = 0; i < tirs.size(); ++i)
        { // les munitions se déplacent avec le vaisseau (position)
            if (!tirs.at(i)->getTirActif())
            {
                tirs.at(i)->move(calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
                tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
            }
        }
    }

    if (cos((getAngle2()) * gameconf::DEG2RAD) < 0)
    {
        this->move(-calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
        camera->move(-calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);

        for (unsigned int i = 0; i < tirs.size(); ++i)
        { // les munitions se déplacent avec le vaisseau (position)
            if (!tirs.at(i)->getTirActif())
            {
                tirs.at(i)->move(-calculRotationTranslatex, calculRotationTranslatey, calculRotationTranslatez);
                tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
            }
        }
    }
}

void Vaisseau::decreaseSpeed()
{
    if (vitesse > 0)
        vitesse *= playercontrols::POSITIVE_SPEED_DECREASE;
    else if (vitesse < 0)
        vitesse *= playercontrols::NEGATIVE_SPEED_DECREASE;
}

GLvoid Vaisseau::tirer()
{ // tire une balle
    for (unsigned int i = 0; i < tirs.size(); ++i)
    {

        GLfloat longueur = longueurTot[i] + sqrt((tirs.at(i)->posX() - tirs.at(i)->posXmomentTir()) * (tirs.at(i)->posX() - tirs.at(i)->posXmomentTir()) + (tirs.at(i)->posY() - tirs.at(i)->posYmomentTir()) * (tirs.at(i)->posY() - tirs.at(i)->posYmomentTir()) + (tirs.at(i)->posZ() - tirs.at(i)->posZmomentTir()) * (tirs.at(i)->posZ() - tirs.at(i)->posZmomentTir()));

        GLfloat calculRotationTranslatexTir = -tirs.at(i)->getSpeed() * sin(tirs.at(i)->getAngle() * gameconf::DEG2RAD);
        GLfloat calculRotationTranslateyTir = tirs.at(i)->getSpeed() * sin(tirs.at(i)->getAngle2() * gameconf::DEG2RAD);
        GLfloat calculRotationTranslatezTir = -tirs.at(i)->getSpeed() * cos(tirs.at(i)->getAngle() * gameconf::DEG2RAD);
        tirs.at(i)->move(calculRotationTranslatexTir, calculRotationTranslateyTir, calculRotationTranslatezTir);

        // gestion du franchissage de frontière du tir
        if (tirs.at(i)->posX() > gameconf::POSITIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX() - gameconf::BULLET_OUT_OF_ARENA_RELOCATION, tirs.at(i)->posY(), tirs.at(i)->posZ());
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }

        else if (tirs.at(i)->posX() < gameconf::NEGATIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX() + gameconf::BULLET_OUT_OF_ARENA_RELOCATION, tirs.at(i)->posY(), tirs.at(i)->posZ());
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }

        if (tirs.at(i)->posY() > gameconf::POSITIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX(), tirs.at(i)->posY() - gameconf::BULLET_OUT_OF_ARENA_RELOCATION, tirs.at(i)->posZ());
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }
        else if (tirs.at(i)->posY() < gameconf::NEGATIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX(), tirs.at(i)->posY() + gameconf::BULLET_OUT_OF_ARENA_RELOCATION, tirs.at(i)->posZ());
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }

        if (tirs.at(i)->posZ() > gameconf::POSITIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ() - gameconf::BULLET_OUT_OF_ARENA_RELOCATION);
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }

        else if (tirs.at(i)->posZ() < gameconf::NEGATIVE_AREA_SIZE)
        {
            longueurTot[i] = longueur;
            tirs.at(i)->setPos(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ() + gameconf::BULLET_OUT_OF_ARENA_RELOCATION);
            tirs.at(i)->setposmomentTir(tirs.at(i)->posX(), tirs.at(i)->posY(), tirs.at(i)->posZ());
        }

        // on remet la balle a sa place si il atteint la portée grace au calcul de la longueur
        if (longueur > gameconf::POSITIVE_AREA_SIZE || longueur < gameconf::NEGATIVE_AREA_SIZE)
        {
            longueurTot[i] = 0;
            tirs.at(i)->release(this->posx(), this->posy(), this->posz(), this->getAngle(), this->getAngle2());
        }
    }
}

bool Vaisseau::collisionVaisseauAsteroide(Asteroide *a)
{
    if (!this->invincible)
    {
        float sphereXDistance = abs(a->posX() - this->posx());
        float sphereYDistance = abs(a->posY() - this->posy());
        float sphereZDistance = abs(a->posZ() - this->posz());

        if (sphereXDistance >= (this->largeur + a->getRayon()))
        {
            return false;
        }
        if (sphereYDistance >= (this->longueur + a->getRayon()))
        {
            return false;
        }
        if (sphereZDistance >= (this->hauteur + a->getRayon()))
        {
            return false;
        }

        if (sphereXDistance < (this->largeur))
        {
            this->vie -= gameconf::ASTEROID_CONTACT_DAMAGE;
            return true;
        }
        if (sphereYDistance < (this->longueur))
        {
            this->vie -= gameconf::ASTEROID_CONTACT_DAMAGE;
            return true;
        }
        if (sphereZDistance < (this->hauteur))
        {
            this->vie -= gameconf::ASTEROID_CONTACT_DAMAGE;
            return true;
        }

        float cornerDistance_sq = ((sphereXDistance - this->largeur) * (sphereXDistance - this->largeur)) +
                                  ((sphereYDistance - this->longueur) * (sphereYDistance - this->longueur) +
                                   ((sphereYDistance - this->hauteur) * (sphereYDistance - this->hauteur)));

        if (cornerDistance_sq < (a->getRayon() * a->getRayon()))
        {
            this->vie -= gameconf::ASTEROID_CONTACT_DAMAGE;
            return true;
        }
    }
    return false;
}

bool Vaisseau::collisionVaisseauVaisseau(Vaisseau *v)
{
    if (!this->invincible && v->getVie() > gameconf::PLAYER_DEAD)
    {
        if (abs(this->posx() - v->posx()) < this->getLargeur() + v->getLargeur())
        {

            if (abs(this->posy() - v->posy()) < this->getHauteur() + v->getHauteur())
            {

                if (abs(this->posz() - v->posz()) < this->getLongueur() + v->getLongueur())
                {
                    return true;
                }
            }
        }
    }

    return false;
}
