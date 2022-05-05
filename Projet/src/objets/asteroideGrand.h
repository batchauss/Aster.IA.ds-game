#include"asteroide.h"

class AsteroideGrand : public Asteroide {
    
     public :
        AsteroideGrand(int i);
        ~AsteroideGrand() ;

        void split() override;
        GLvoid asteroideTouche() override;

};