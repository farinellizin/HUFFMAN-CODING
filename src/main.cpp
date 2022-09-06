#include "arithmetics.hpp"
#include "HuffTree.hpp"
#include "extraFunctions.hpp"
using namespace std;

int main () {
    unordered_map <string, float> content;
    vector <HuffTree*> treeValues;
    float maxRP, minRP;

    fillMap(&content, "text.txt");

    maxRP = getMaxRP(&content);
    minRP = getMinRP(&content);

    normalizeAccounting(maxRP, minRP, content);
    mapToVector(treeValues, content);
    insertionSort(treeValues);
    joinNodes(treeValues);
}