#include "arithmetics.hpp"
#include "HuffTree.hpp"
using namespace std;

void insertionSort(vector <int> &v) {
    int aux;
    int j;

    for (long unsigned int i = 1; i < v.size(); i++) {
        aux = v[i];
        j = i - 1;

        while (j >= 0 && aux < v[j]) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;
    }
}

void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content) {
    HuffTree *aux;
    aux = NULL;

    for (auto search: content) {
        aux->item.word = search.first;
        aux->item.normalizedValue = search.second;
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


    // for (long unsigned int i = 0; i < treeValues.size(); i++) {
    //     cout << "Valor: " << treeValues[i]->item.normalizedValue << "\t Palavra: " << treeValues[i] -> item.word << endl;
    // }

    // // just printing to check
    // for (auto item: content) {
    //     cout << item.first << "\t" << item.second << endl;
    // }    
}