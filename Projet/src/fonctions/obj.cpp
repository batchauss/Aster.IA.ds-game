#include "obj.h"

struct obj loadObj(std::string const & path){

    FILE * f = fopen(path.c_str(), "r");
    if(f == NULL){
        std::cout << "Le parser n'a pas réussi à ouvrir le fichier obj " + path << std::endl;
        return {};
    }

    std::vector<std::vector<GLfloat>> v;
    std::vector<std::vector<GLfloat>> vt;
    std::vector<std::vector<GLfloat>> vn;
    std::vector<std::vector<std::vector<int>>> faces;

    std::string ligne;
    std::vector<std::string> ligneSplit;

    char * l = new char();
    while(fgets(l, 80, f) != NULL ){
        ligne = l;
        ligneSplit = split(ligne);

        if(ligneSplit.at(0) == "v"){
            v.push_back({std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))});
        }
        else if(ligneSplit.at(0) == "vt"){
            vt.push_back({std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2))});
        }
        else if(ligneSplit.at(0) == "vn"){
            vn.push_back({std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))});
        }
        else if(ligneSplit.at(0) == "f"){
            if(ligneSplit.size() == 5) faces.push_back({splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(2), "/"), splitDelimit(ligneSplit.at(3), "/"), splitDelimit(ligneSplit.at(4), "/")});
            else if(ligneSplit.size() == 4) faces.push_back({splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(2), "/"), splitDelimit(ligneSplit.at(3), "/")});
        }
    }

    struct obj o = {v, vt, vn, faces};

    std::cout << "Obj chargé : " +path << std::endl;
    std::cout << o.v.size() << " v, " <<  o.vt.size() << " vt, " <<  o.vn.size() << " vn, " <<  o.faces.size() << " faces." << std::endl;
    return o;
}

std::vector<std::string> split(const std::string& s)
{
    std::stringstream ss(s);
    std::vector<std::string> words;
    for (std::string w; ss>>w; ) words.push_back(w);
    return words;
}

std::vector<int> splitDelimit(const std::string& s, std::string d)
{
    std::vector<int> num;
    size_t pos;
    std::string sub = s;
    while((pos = sub.find(d)) != std::string::npos){
        num.push_back(stoi(sub.substr(0, pos)));
        sub = sub.substr(pos+1);
    }
    num.push_back(stoi(sub));
    return num;
}