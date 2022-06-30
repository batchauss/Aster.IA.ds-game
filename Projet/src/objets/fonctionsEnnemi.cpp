#include "../../includes/constant.h"

#include "fonctionsEnnemi.h"
#include "vaisseau.h"

extern Vaisseau *ennemi;
extern Vaisseau *vaisseau;
extern GLfloat score;

void deplacementEnnemi()
{
    ennemi->moveForward();
    ennemi->tirer();
    ennemi->setSpeed(gameconf::ENEMY_SPEED);
    ennemi->setAngle2(gameconf::ENEMY_PITCH);
    ennemi->setAngle(gameconf::ENEMY_YAW);
    ennemi->setHitbox(gameconf::ENEMY_HITBOX, gameconf::ENEMY_HITBOX, gameconf::ENEMY_HITBOX);
    glTranslatef(ennemi->posx(), ennemi->posy(), ennemi->posz());
    glRotatef(gameconf::ENEMY_ROTATE + ennemi->getAngle(), 0, 1, 0);

    glCallList(5);
}

void ennemiTouche()
{ // notre vaisseau touche la soucoupe
    for (unsigned int i = 0; i < vaisseau->tirs.size(); ++i)
    {
        if (abs(ennemi->posx() - vaisseau->tirs.at(i)->posX()) < ennemi->getLargeur() && vaisseau->tirs.at(i)->getTirActif())
        {
            if (abs(ennemi->posy() - vaisseau->tirs.at(i)->posY()) < ennemi->getHauteur() && vaisseau->tirs.at(i)->getTirActif())
            {
                if (abs(ennemi->posz() - vaisseau->tirs.at(i)->posZ()) < ennemi->getLongueur() && vaisseau->tirs.at(i)->getTirActif())
                {
                    vaisseau->tirs.at(i)->release(vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), vaisseau->getAngle(), vaisseau->getAngle2());
                    ennemi->setVie(ennemi->getVie() - gameconf::ENEMY_LIFE_LOST);
                }
            }
        }
    }
    if (ennemi->getVie() <= gameconf::ENEMY_MIN_LIFE)
    {
        score += 300;
        // delete ennemi;
    }
}

void tirEnnemi()
{ // la soucoupe touche le joueur
    for (unsigned int i = 0; i < ennemi->tirs.size(); ++i)
    {
        if (abs(vaisseau->posx() - ennemi->tirs.at(i)->posX()) < vaisseau->getLargeur())
        {
            if (abs(vaisseau->posy() - ennemi->tirs.at(i)->posY()) < vaisseau->getHauteur())
            {
                if (abs(vaisseau->posz() - ennemi->tirs.at(i)->posZ()) < vaisseau->getLongueur())
                {
                    ennemi->tirs.at(i)->release(ennemi->posx(), ennemi->posy(), ennemi->posz(), ennemi->getAngle(), ennemi->getAngle2());
                    vaisseau->setVie(vaisseau->getVie() - gameconf::ENEMY_DAMAGE);
                }
            }
        }
    }
}