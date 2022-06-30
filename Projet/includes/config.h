#pragma once

#include <string>

// Décommenter la ligne ci-dessous pour passer en mode dév
#define ENV_DEV


enum class configKey { PATH_TO_ASSETS };

std::string config( configKey k );