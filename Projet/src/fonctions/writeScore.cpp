#include "writeScore.h"

extern std::vector<std::string> split(const std::string& s);

void writeScore(std::string pseudo, int score){

    std::fstream file("scores/scores.txt", std::ios_base::in | std::ios_base::out | std::ios_base::ate);
    if (!file) {
        std::cout << "failed to open ";
    } else {
        file << pseudo << score << std::endl;
        file.close();
    }
}

std::vector<int> getScores(){
    std::vector<int> v;
    std::fstream file("scores/scores.txt", std::ios_base::in);
    if (!file) {
        std::cout << "failed to open";
    }
    else {
        std::string ligne;
        std::vector<std::string> ligneSplit;

        while(std::getline(file, ligne)){
            ligneSplit = split(ligne);
            if(std::find(v.begin(), v.end(), std::stoi(ligneSplit[1])) == v.end()){
                v.push_back(std::stoi(ligneSplit[1]));
            }
        }
    }
    return v;
}

std::vector<std::string> getScoresPs(){
    std::vector<std::string> v;

    std::fstream file("scores/scores.txt", std::ios_base::in);
    if (!file) {
        std::cout << "failed to open";
    }
    else {
        std::string ligne;
        while(std::getline(file, ligne)){
            if(std::find(v.begin(), v.end(), ligne) == v.end()){
                v.push_back(ligne);
            }
        }
    }
    triScores(v);
    return v;
}

void triScores(std::vector<std::string> &scores){
    std::vector<std::string> v1;
    std::vector<std::string> v2;
    std::string temp;

    for(unsigned int i=0; i<scores.size(); i++){
        for(unsigned int j=0; j<scores.size()-1; j++){
            v1 = split(scores.at(j));
            v2 = split(scores.at(j+1));

            if(std::stoi(v1.at(0)) < std::stoi(v2.at(0))){
                temp = scores.at(j);
                scores.at(j) = scores.at(j+1);
                scores.at(j+1) = temp;
            }
        }
    }
}

std::vector<std::string> bestScores(){
    std::vector<std::string> allScores = getScoresPs();
    std::vector<std::string> scores;
    if(scores.size() >= 10){
        for(unsigned int i = 0; i < 10; i++) scores.push_back(allScores.at(i));
    }
    else {
        for(unsigned int i = 0; i < scores.size(); i++) scores.push_back(allScores.at(i));
    }
    return scores;
}