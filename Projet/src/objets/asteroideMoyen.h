#include"asteroide.h"



class AsteroideMoyen: public Asteroide {

     public :
        AsteroideMoyen(int i);
        ~AsteroideMoyen() = default;

        void split() override;
        GLvoid asteroideTouche() override;
};
