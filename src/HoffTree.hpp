#ifndef HOFFTREE_HPP
#define HOFFTREE_HPP
#include "arithmetics.hpp"
typedef struct Data Data;
typedef struct HuffTree HuffTree;
using namespace std;

struct Data {
    float value;
    int level;
};

struct HuffTree {
    Data item;
    HuffTree *leftSon, *rightSon;
};

void huffTreeInit(HuffTree **hf);
void huffTreeInsert(HuffTree **ht, Data content, float *leftSonValue, float *rightSonValue);






#endif