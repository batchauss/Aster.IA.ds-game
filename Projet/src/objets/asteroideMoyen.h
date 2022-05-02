#include"asteroide.h"



class AsteroideMoyen: public Asteroide {
    
     public :
        AsteroideMoyen(int i);
        ~AsteroideMoyen();

        void split() override;
};