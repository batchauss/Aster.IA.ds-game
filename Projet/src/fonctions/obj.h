#include "../init.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

struct obj {
    std::vector<std::vector<GLfloat>> v;
    std::vector<std::vector<GLfloat>> vt;
    std::vector<std::vector<GLfloat>> vn;
    std::vector<std::vector<std::vector<int>>> faces;
};

struct obj loadObj(std::string const & file);
std::vector<std::string> split(const std::string & s);
std::vector<int> splitDelimit(const std::string& s, std::string d);