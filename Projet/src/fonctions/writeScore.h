#ifndef TEXTURE_H
#define TEXTURE_X

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

void writeScore(std::string pseudo, int score);   // Ecris un score avec un pseudo sur le fichier scores.txt
std::vector<int> getScores();   // Retourne les scores dans un tableau


#endif