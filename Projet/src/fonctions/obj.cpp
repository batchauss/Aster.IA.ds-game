#include "obj.h"

std::vector<cube> loadObj(std::string const & path){

    std::vector<cube> cubes;

    FILE * f = fopen(path.c_str(), "r");
    if(f == NULL){
        std::cout << "Le parser n'a pas réussi à ouvrir le fichier obj " + path << std::endl;
        return cubes;
    }

    char * l = new char();

    fgets(l, 80, f);
    std::string ligne = l;
    std::vector<std::string> ligneSplit = split(ligne);


    while(ligneSplit.at(0) != "o"){
        fgets(l, 80, f);
        ligne = l;
        ligneSplit = split(ligne);
    }

    while(ligneSplit.at(0) == "o"){

        std::vector<std::vector<GLfloat>> v;
        std::vector<std::vector<GLfloat>> vt;
        std::vector<std::vector<GLfloat>> vn;
        std::vector<std::vector<std::vector<int>>> faces;

        fgets(l, 80, f);
        ligne = l;
        ligneSplit = split(ligne);

        while(ligneSplit.at(0) == "v" || ligneSplit.at(0) == "vt" || ligneSplit.at(0) == "vn"){

            if(ligneSplit.at(0) == "v"){
                std::vector<GLfloat> vTemp {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))}; 
                v.push_back(vTemp);
            }
            else if(ligneSplit.at(0) == "vt"){
                std::vector<GLfloat> vtTemp {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2))}; 
                vt.push_back(vtTemp);
            }
            else if(ligneSplit.at(0) == "vn"){
                std::vector<GLfloat> vnTemp {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))}; 
                vn.push_back(vnTemp);
            }
        fgets(l, 80, f);
        ligne = l;
        ligneSplit = split(ligne);
        }

        fgets(l, 80, f);
        fgets(l, 80, f);
        ligne = l;
        ligneSplit = split(ligne);

        while(ligneSplit.at(0) == "f"){
            std::vector<std::vector<int>> faceTemp {splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(1), "/")};
            faces.push_back(faceTemp);

            if(fgets(l, 80, f) == NULL) break;
            ligne = l;
            ligneSplit = split(ligne);
        }

        struct cube c = {v, vt, vn, faces};
        cubes.push_back(c);
    }
    return cubes;
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