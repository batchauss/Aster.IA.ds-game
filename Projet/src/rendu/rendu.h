#include "../objets/vaisseau.h"
#include "../objets/camera.h"
#include "../objets/asteroide.h"
#include "../objets/tir.h"
#include "../fonctions/obj.h"

void constrObj(struct objmtl o);

void renduAsteroide(Asteroide * a);
void renduCamera(Vaisseau * v);
void renduTir(Tir *t);
void renduVaisseau(struct objmtl u, Vaisseau *v);