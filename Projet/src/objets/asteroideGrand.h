#include"asteroide.h"

class AsteroideGrand : public Asteroide {
    
     public :
        AsteroideGrand(int i);
        ~AsteroideGrand() = default;

        void split() override;
        GLvoid asteroideTouche() override;

};