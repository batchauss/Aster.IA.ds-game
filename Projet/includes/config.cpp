#include "config.h"

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

}