#pragma once

#include <string>

enum class configKey { PATH_TO_ASSETS };

std::string config( configKey k );
