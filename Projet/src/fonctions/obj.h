#include "../init.h"
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>

struct cube {
    std::vector<std::vector<GLfloat>> v;
    std::vector<std::vector<GLfloat>> vt;
    std::vector<std::vector<GLfloat>> vn;
    std::vector<std::vector<std::vector<int>>> faces;
};

std::vector<cube> loadObj(std::string const & file);
std::vector<std::string> split(const std::string & s);
std::vector<int> splitDelimit(const std::string& s, std::string d);