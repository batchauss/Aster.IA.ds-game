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
    std::sort(v.begin(), v.end(), std::greater<int>());

    for(auto const & a : v) std::cout << a << " ";
    std::cout << std::endl;
    
    return v;
}

std::vector<int> biggerScores(){
    std::vector<int> scores = getScores();
}
