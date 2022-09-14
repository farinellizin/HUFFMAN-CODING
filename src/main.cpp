#include "arithmetics.hpp"
#include "HuffTree.hpp"
#include "extraFunctions.hpp"
#include "queue.hpp"
using namespace std;

int main () {
    unordered_map <string, float> content;
    vector <HuffTree*> treeValues;
    vector <string> text;
    vector <bool> mainVector;
    float maxRP, minRP;

    fillMap(&content, "text.txt", &text);

    maxRP = getMaxRP(&content);
    minRP = getMinRP(&content);

    normalizeAccounting(maxRP, minRP, content);
    mapToVector(treeValues, content);
    insertionSort(treeValues);
    joinNodes(treeValues);
    generateCode(&treeValues[0]);
    widthPath(&treeValues[0]);
    translateToBinary(mainVector, text, &treeValues[0]);
    writeInFile(mainVector);
}