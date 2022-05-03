#include "../objets/vaisseau.h"
#include "../objets/camera.h"
#include "../objets/asteroidePetit.h"
#include "../objets/asteroideMoyen.h"
#include "../objets/asteroideGrand.h"
#include "../objets/tir.h"
#include "../fonctions/obj.h"

void renduAsteroide( int taille,struct objmtl as);
void renduCamera(Vaisseau * v);
void renduTir(Tir *t);
void renduVaisseau(struct objmtl v);