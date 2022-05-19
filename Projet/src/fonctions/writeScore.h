#ifndef TEXTURE_H
#define TEXTURE_X

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

void writeScore(std::string pseudo, int score);  // Ecris un score avec un pseudo sur le fichier scores.txt
std::vector<std::string> getScoresPs();  // Retourne les scores dans un tableau
void triScores(std::vector<std::string> &scores);  // Tri décroissant des scores
std::vector<std::string> bestScores();  // Retourne les 10 meilleurs scores

#endif