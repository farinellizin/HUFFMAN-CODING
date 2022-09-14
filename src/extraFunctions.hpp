#ifndef EXTRAFUNCTIONS_HPP
#define EXTRAFUNCTIONS_HPP
#include "arithmetics.hpp"
#include "HuffTree.hpp"

void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content);
void writeInFile(vector <bool> &mainVector);

#endif