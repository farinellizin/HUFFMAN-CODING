#include "extraFunctions.hpp"

void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content) {
    HuffTree *aux;

    for (auto search: content) {
        aux = new HuffTree;
        aux -> item.word = search.first;
        aux -> item.normalizedValue = search.second;
        aux -> leftSon = NULL;
        aux -> rightSon = NULL;
        treeValues.push_back(aux);
    }
}

void writeInFile(vector <bool> &mainVector) {
    FILE *myfile;
    myfile = fopen("text.dat", "wb");
    if (myfile != NULL) {
        fwrite(&mainVector, sizeof(bool), mainVector.size(), myfile);
    }
}