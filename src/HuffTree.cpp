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
    vector <bool> auxVec;
    
    while (treeValues.size() != 1) {
        leftSon = treeValues[treeValues.size() - 1]; // recebe left son
        rightSon = treeValues[treeValues.size() - 2]; // recebe right son

        treeValues.pop_back(); // tira ultimo valor
        treeValues.pop_back(); // tira ultimo valor

        aux = new HuffTree; // cria novo nó
        aux -> item.normalizedValue = (leftSon -> item.normalizedValue + rightSon -> item.normalizedValue); // valor do nó (sem palavra)
        aux -> leftSon = leftSon; // define filho esquerdo
        aux -> leftSon -> dad = aux; // define o pai para o filho esquerdo
        aux -> rightSon = rightSon; // define filho direito
        aux -> rightSon -> dad = aux; // define o pai para o filho direito

        treeValues.push_back(aux);
        insertionSort(treeValues);
    }

    treeValues[0] -> dad = NULL; // raiz está recebendo NULL!
    treeValues[0] -> item.binaryCodification = auxVec;
}