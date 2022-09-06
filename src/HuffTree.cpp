#include "HuffTree.hpp"

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

void joinNodes(vector <HuffTree*> &treeValues) {
    HuffTree *leftSon;
    HuffTree *rightSon;
    HuffTree *aux;
    
    while (treeValues.size() != 1) {
        leftSon = treeValues[treeValues.size() - 1];
        rightSon = treeValues[treeValues.size() - 2];

        treeValues.pop_back();
        treeValues.pop_back();

        aux = new HuffTree;
        aux -> item.normalizedValue = (leftSon -> item.normalizedValue + rightSon -> item.normalizedValue);
        aux -> leftSon = leftSon;
        aux -> rightSon = rightSon;

        treeValues.push_back(aux);
        insertionSort(treeValues);
    }

    // cout << "expected result: "; 
    // cout << treeValues[0]->item.normalizedValue << endl << endl;
}



// acessar ultima posicao >> treeValues.size() - 1;
// acessar penultima posicao >> treeValues.size() - 2;
// valor final = 26!!