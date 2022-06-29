#include "../../includes/constant.h"

#include "rendu.h"

extern GLfloat rayon_x;
extern GLfloat rayon_z;
extern GLfloat rayon_x_2;
extern GLfloat rayon_y;

/* INDICATION APPEL DE LISTE D'AFFICHAGE

    1 : VAISSEAU
    2 : PETIT ASTERODIDE
    3 : MOYEN ASTEROIDE
    4 : GRAND ASTEROIDE
    5 : SOUCOUPE ENNEMI
    6 : VAISSEAU TOUCHÉ ( INVINCIBLE )
    7 : PLANETE DECOR 1
    8 : COEUR SOUCOUPE
*/

void renduAsteroide(int taille, struct objmtl as)
{
    if (taille == 1)
    {
        glNewList(2, GL_COMPILE_AND_EXECUTE);
        glScalef(render::LVL_ONE, render::LVL_ONE, render::LVL_ONE);
    }
    else if (taille == 2)
    {
        glNewList(3, GL_COMPILE_AND_EXECUTE);
        glScalef(render::LVL_TWO, render::LVL_TWO, render::LVL_TWO);
    }
    else if (taille == 3)
    {
        glNewList(4, GL_COMPILE_AND_EXECUTE);
        glScalef(render::LVL_THREE, render::LVL_THREE, render::LVL_THREE);
    }
    glPushMatrix();
    {
        for (const auto &face : as.obj.faces)
        {
            glBegin(GL_POLYGON);

            int indexMat = face.at(face.size() - 1).at(0);
            GLfloat shin = as.materiaux.at(indexMat - 1).Ns;
            glMaterialfv(GL_FRONT, GL_SHININESS, &shin);

            glNormal3f(as.obj.vn.at(face.at(0).at(2) - 1).at(0), as.obj.vn.at(face.at(0).at(2) - 1).at(1), as.obj.vn.at(face.at(0).at(2) - 1).at(2));
            glColor3f(as.materiaux.at(indexMat - 1).Kd.at(0), as.materiaux.at(indexMat - 1).Kd.at(1), as.materiaux.at(indexMat - 1).Kd.at(2));
            for (const auto &vertex : face)
            {
                glVertex3f(as.obj.v.at(vertex.at(0) - 1).at(0), as.obj.v.at(vertex.at(0) - 1).at(1), as.obj.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd();
        }
    }
    glPopMatrix();
    glEndList();
}

void renduCamera(Vaisseau *vaisseau)
{
    gluLookAt(vaisseau->camera->posx(), vaisseau->camera->posy(), vaisseau->camera->posz(), vaisseau->posx(), vaisseau->posy(), vaisseau->posz(), 0, 1, 0);
}

void renduTir(int etatVaisseau, Tir *t)
{
    glPushMatrix();
    {
        if (etatVaisseau == 1)
            glColor4f(render::BULLET_ONE, render::BULLET_ONE, render::BULLET_ZERO, render::BULLET_ONE);
        else if (etatVaisseau == 2)
            glColor4f(render::BULLET_ONE, render::BULLET_ONE, render::BULLET_ZERO, render::BULLET_ZERO);
        glTranslatef(t->posX(), t->posY(), t->posZ());
        glRotatef(t->getAngle(), render::BULLET_ROTATE_X, render::BULLET_ROTATE_Y, render::BULLET_ROTATE_Z);
        glScalef(render::BULLET_SCALE_X, render::BULLET_SCALE_Y, render::BULLET_SCALE_Z);
        glutSolidCube(render::BULLET_SIZE);
    }
    glPopMatrix();
}

void renduVaisseau(int etatVaisseau, struct objmtl v)
{

    if (etatVaisseau == 1)
        glNewList(1, GL_COMPILE_AND_EXECUTE);
    else if (etatVaisseau == 2)
        glNewList(6, GL_COMPILE_AND_EXECUTE);

    glPushMatrix();
    {
        glScalef(render::SHIP_SIZE, render::SHIP_SIZE, render::SHIP_SIZE);
        for (const auto &face : v.obj.faces)
        {
            glBegin(GL_POLYGON);

            int indexMat = face.at(face.size() - 1).at(0);
            GLfloat shin = v.materiaux.at(indexMat - 1).Ns;
            glMaterialfv(GL_FRONT, GL_SHININESS, &shin);
            glNormal3f(v.obj.vn.at(face.at(0).at(2) - 1).at(0), v.obj.vn.at(face.at(0).at(2) - 1).at(1), v.obj.vn.at(face.at(0).at(2) - 1).at(2));

            if (etatVaisseau == 1)
                glColor3f(v.materiaux.at(indexMat - 1).Kd.at(0), v.materiaux.at(indexMat - 1).Kd.at(1), v.materiaux.at(indexMat - 1).Kd.at(2));
            else if (etatVaisseau == 2)
                glColor4f(v.materiaux.at(indexMat - 1).Kd.at(0), v.materiaux.at(indexMat - 1).Kd.at(1), v.materiaux.at(indexMat - 1).Kd.at(2), 0.2);
            for (const auto &vertex : face)
            {
                glVertex3f(v.obj.v.at(vertex.at(0) - 1).at(0), v.obj.v.at(vertex.at(0) - 1).at(1), v.obj.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd();
        }
    }
    glPopMatrix();
    glEndList();
}

void renduEnnemi(struct objmtl e)
{
    glNewList(5, GL_COMPILE_AND_EXECUTE);
    glPushMatrix();
    {
        glScalef(render::ENEMY_SIZE, render::ENEMY_SIZE, render::ENEMY_SIZE);
        for (const auto &face : e.obj.faces)
        {
            glBegin(GL_POLYGON);

            int indexMat = face.at(face.size() - 1).at(0);
            GLfloat shin = e.materiaux.at(indexMat - 1).Ns;
            glMaterialfv(GL_FRONT, GL_SHININESS, &shin);
            glNormal3f(e.obj.vn.at(face.at(0).at(2) - 1).at(0), e.obj.vn.at(face.at(0).at(2) - 1).at(1), e.obj.vn.at(face.at(0).at(2) - 1).at(2));

            glColor3f(e.materiaux.at(indexMat - 1).Kd.at(0), e.materiaux.at(indexMat - 1).Kd.at(1), e.materiaux.at(indexMat - 1).Kd.at(2));
            for (const auto &vertex : face)
            {
                glVertex3f(e.obj.v.at(vertex.at(0) - 1).at(0), e.obj.v.at(vertex.at(0) - 1).at(1), e.obj.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd();
        }
    }
    glPopMatrix();
    glEndList();
}

void renduPlanete(struct objmtl planete)
{
    glNewList(7, GL_COMPILE_AND_EXECUTE);
    glPushMatrix();
    {
        glScalef(render::PLANET_SIZE, render::PLANET_SIZE, render::PLANET_SIZE);
        for (const auto &face : planete.obj.faces)
        {
            glBegin(GL_POLYGON);

            int indexMat = face.at(face.size() - 1).at(0);
            GLfloat shin = planete.materiaux.at(indexMat - 1).Ns;
            glMaterialfv(GL_FRONT, GL_SHININESS, &shin);
            glNormal3f(planete.obj.vn.at(face.at(0).at(2) - 1).at(0), planete.obj.vn.at(face.at(0).at(2) - 1).at(1), planete.obj.vn.at(face.at(0).at(2) - 1).at(2));

            glColor3f(planete.materiaux.at(indexMat - 1).Kd.at(0), planete.materiaux.at(indexMat - 1).Kd.at(1), planete.materiaux.at(indexMat - 1).Kd.at(2));
            for (const auto &vertex : face)
            {
                glVertex3f(planete.obj.v.at(vertex.at(0) - 1).at(0), planete.obj.v.at(vertex.at(0) - 1).at(1), planete.obj.v.at(vertex.at(0) - 1).at(2));
            }
            glEnd();
        }
    }
    glPopMatrix();
    glEndList();
}

void renduCoeur(struct objmtl coeur)
{
    glNewList(8, GL_COMPILE_AND_EXECUTE);
    glScalef(render::HEART_SIZE, render::HEART_SIZE_Y, render::HEART_SIZE);
    for (const auto &face : coeur.obj.faces)
    {
        glBegin(GL_POLYGON);

        int indexMat = face.at(face.size() - 1).at(0);
        GLfloat shin = coeur.materiaux.at(indexMat - 1).Ns;
        glMaterialfv(GL_FRONT, GL_SHININESS, &shin);
        glNormal3f(coeur.obj.vn.at(face.at(0).at(2) - 1).at(0), coeur.obj.vn.at(face.at(0).at(2) - 1).at(1), coeur.obj.vn.at(face.at(0).at(2) - 1).at(2));

        // glColor3f(coeur.materiaux.at(indexMat-1).Kd.at(0), coeur.materiaux.at(indexMat-1).Kd.at(1), coeur.materiaux.at(indexMat-1).Kd.at(2));
        glColor3f(200, 0, 0);
        for (const auto &vertex : face)
        {
            glVertex3f(coeur.obj.v.at(vertex.at(0) - 1).at(0), coeur.obj.v.at(vertex.at(0) - 1).at(1), coeur.obj.v.at(vertex.at(0) - 1).at(2));
        }
        glEnd();
    }
    glEndList();
}
