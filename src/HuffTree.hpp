#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP
#include "arithmetics.hpp"
typedef struct Data Data;
typedef struct HuffTree HuffTree;
using namespace std;

struct Data {
    float normalizedValue;
    string word;
    bool binaryCodification;
};

struct HuffTree {
    Data item;
    HuffTree *leftSon, *rightSon, *dad;
};

void insertionSort(vector <HuffTree*> &treeValues);
void joinNodes(vector <HuffTree*> &treeValues);

#endif