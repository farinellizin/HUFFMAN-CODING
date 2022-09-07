#include "extraFunctions.hpp"

// void insertionSort(vector <HuffTree*> &treeValues) {
//     HuffTree *aux;
//     int j;

//     for (long unsigned int i = 1; i < treeValues.size(); i++) {
//         aux = treeValues[i];
//         j = i - 1;

//         while (j >= 0 && aux-> item.normalizedValue > treeValues[j]->item.normalizedValue) {
//             treeValues[j + 1] = treeValues[j];
//             j = j - 1;
//         }

//         treeValues[j + 1] = aux;
//     }
// }

void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content) {
    HuffTree *aux;

    for (auto search: content) {
        aux = new HuffTree;
        aux -> item.word = search.first;
        aux -> item.normalizedValue = search.second;
        treeValues.push_back(aux);
    }

    aux = new HuffTree;
    aux -> item.word = "xxxx";
    aux -> item.normalizedValue = 30;
    treeValues.push_back(aux);
}