#include "../objets/vaisseau.h"
#include "../objets/camera.h"
#include "../objets/asteroide.h"
#include "../objets/tir.h"
#include "../fonctions/obj.h"


void renduAsteroide(struct objmtl as,const Asteroide &  a);
void renduCamera(Vaisseau * v);
void renduTir(Tir *t);
void renduObjVaisseau(struct objmtl u, Vaisseau *v);