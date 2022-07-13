#include "config.h"

#include <stdexcept>

// Décommenter la ligne ci-dessous pour passer en mode dév
// #define ENV_DEV

std::string config( configKey k ) {

    #ifdef ENV_DEV
    switch( k ) {
        case configKey::PATH_TO_ASSETS: return "./";
    }
    #endif


    #ifndef ENV_DEV
    switch( k ) {
        case configKey::PATH_TO_ASSETS: return "/usr/share/Aster.ia.ds/";
    }
    #endif

	throw std::range_error("config error");
}
