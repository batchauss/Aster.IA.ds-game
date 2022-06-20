#include "../init.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct obj {
    std::vector<std::vector<GLfloat>> v;
    std::vector<std::vector<GLfloat>> vt;
    std::vector<std::vector<GLfloat>> vn;
    std::vector<std::vector<std::vector<int>>> faces;
};

struct mtl {
    std::string nom;
    GLfloat Ns, Ni, d;
    std::vector<GLfloat> Ka, Kd, Ks, Ke;
};
using mtls = std::vector<mtl>;

struct objmtl {
    struct obj obj;
    mtls materiaux;
};

struct objmtl loadObj(std::string file);
mtls loadMtl(std::string const & file);
std::vector<std::string> split(const std::string& s);
std::vector<int> splitDelimit(const std::string& s, std::string d);