#include "obj.h"

struct objmtl loadObj(std::string const & path){
    mtls materiaux;
    materiaux = loadMtl(path);

    std::ifstream f(path+".obj");
    if(!f){
        std::cout << "Le parser n'a pas réussi à ouvrir le fichier obj " + path << std::endl;
        return {};
    }

    std::vector<std::vector<GLfloat>> v;
    std::vector<std::vector<GLfloat>> vt;
    std::vector<std::vector<GLfloat>> vn;
    std::vector<std::vector<std::vector<int>>> faces;

    std::string ligne;
    std::vector<std::string> ligneSplit;

    int comptMatActuel;

    while(std::getline(f, ligne)){
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
        else if(ligneSplit.at(0) == "usemtl"){
            comptMatActuel = std::stoi(ligneSplit.at(1).substr(ligneSplit.at(1).size()-1));
        }
        else if(ligneSplit.at(0) == "f"){
            if(ligneSplit.size() == 5) faces.push_back({splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(2), "/"), splitDelimit(ligneSplit.at(3), "/"), splitDelimit(ligneSplit.at(4), "/"), {comptMatActuel}});
            else if(ligneSplit.size() == 4) faces.push_back({splitDelimit(ligneSplit.at(1), "/"), splitDelimit(ligneSplit.at(2), "/"), splitDelimit(ligneSplit.at(3), "/"), {comptMatActuel}});
        }
    }
    struct obj o = {v, vt, vn, faces};
    struct objmtl om = {o, materiaux};

    std::cout << "Obj chargé : " << path << std::endl;
    std::cout << o.v.size() << " v, " <<  o.vt.size() << " vt, " <<  o.vn.size() << " vn, " <<  o.faces.size() << " faces." << std::endl;
    return om;
}

mtls loadMtl(std::string const & path){

    std::ifstream f(path+".mtl");
    if(!f){
        std::cout << "Le parser n'a pas réussi à ouvrir le fichier mtl " + path << std::endl;
        return {};
    }

    mtls materiaux;

    std::string ligne;
    std::vector<std::string> ligneSplit;

    while(std::getline(f, ligne)){

        ligneSplit = split(ligne);

        if(ligneSplit.size() > 0 && ligneSplit.at(0) == "newmtl"){
            mtl mat;
            mat.nom = ligneSplit.at(1);

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Ns = std::stof(ligneSplit.at(1));

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Ka = {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))};

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Kd = {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))};

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Ks = {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))};

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Ke = {std::stof(ligneSplit.at(1)), std::stof(ligneSplit.at(2)), std::stof(ligneSplit.at(3))};

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.Ni = std::stof(ligneSplit.at(1));

            std::getline(f, ligne);
            ligneSplit = split(ligne);
            mat.d = std::stof(ligneSplit.at(1));

            materiaux.push_back(mat);
        }
    }
    std::cout << "Mtl chargé : " << path << std::endl;
    for(auto &a : materiaux){
        std::cout << a.nom << " ";
    }std::cout << std::endl;
    return materiaux;
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
    std::string sub2;

    while((pos = sub.find(d)) != std::string::npos){
        sub2 = sub.substr(0, pos);
        if(sub2 != "") num.push_back(stoi(sub2));
        else num.push_back(0);
        sub = sub.substr(pos+1);
    }
    num.push_back(stoi(sub));
    return num;
}