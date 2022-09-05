#ifndef HUFFTREE_HPP
#define HUFFTREE_HPP
#include "arithmetics.hpp"
typedef struct Data Data;
typedef struct HuffTree HuffTree;
using namespace std;

struct Data {
    float normalizedValue;
    string word;
};

struct HuffTree {
    Data item;
    HuffTree *leftSon, *rightSon;
};

void huffTreeInit(HuffTree **hf);
void huffTreeInsert(HuffTree **ht, Data content);

#endif