#include "../init.h"
#include "math.h"
#include"asteroide.h"

class AsteroidePetit : public Asteroide {
    
     public :
        AsteroidePetit(int i);
        ~AsteroidePetit();

        void split() override;
};
