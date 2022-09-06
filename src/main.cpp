#include "arithmetics.hpp"
#include "HuffTree.hpp"
using namespace std;

// void insertionSort(vector <HuffTree*> &treeValues) {
//     int aux;
//     int j;

//     for (long unsigned int i = 0; i < treeValues.size(); i++) {
//         aux = treeValues[i]->item.normalizedValue;
//         j = j - 1;

//         while (j >= 0 && aux < treeValues[j]->item.normalizedValue) {
//             treeValues[j + 1]->item.normalizedValue = treeValues[j]->item.normalizedValue;
//             j = j - 1;
//         }

//         treeValues[j+1]->item.normalizedValue = aux;
//     }
// }

void insertionSort(vector <HuffTree*> &treeValues) {
    HuffTree *aux;
    int j;

    for (long unsigned int i = 1; i < treeValues.size(); i++) {
        aux = treeValues[i];
        j = i - 1;

        while (j >= 0 && aux-> item.normalizedValue > treeValues[j]->item.normalizedValue) {
            treeValues[j + 1] = treeValues[j];
            j = j - 1;
        }

        treeValues[j + 1] = aux;
    }
}

void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content) {
    HuffTree *aux;

    for (auto search: content) {
        aux = new HuffTree;
        aux -> item.word = search.first;
        aux -> item.normalizedValue = search.second;
        treeValues.push_back(aux);
    }
}

int main () {
    unordered_map <string, float> content;
    vector <HuffTree*> treeValues;
    float maxRP, minRP;

    fillMap(&content, "text.txt");

    maxRP = getMaxRP(&content);
    minRP = getMinRP(&content);

    normalizeAccounting(maxRP, minRP, content);
    mapToVector(treeValues, content);

    cout << "printing before sorting: " << endl << endl;

    for (long unsigned int i = 0; i < treeValues.size(); i++) {
        cout << treeValues[i]->item.normalizedValue << " ";
    }

    insertionSort(treeValues);

    cout << endl << endl << "printing after sorting: " << endl << endl;

    for (long unsigned int i = 0; i < treeValues.size(); i++) {
        cout << treeValues[i]->item.normalizedValue << " ";
    } 
}