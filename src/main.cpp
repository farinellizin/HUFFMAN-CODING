#include "arithmetics.hpp"
using namespace std;

int main () {
    unordered_map <string, float> content;
    float maxRP, minRP;

    fillMap(&content, "text.txt");

    maxRP = getMaxRP(&content);
    minRP = getMinRP(&content);

    // normalizeAccounting(maxRP, minRP, &content);
    // normalizeAccounting in main: 
    for (auto item: content) {
        content[item.first] = ((item.second) / (maxRP - minRP));
    }
    //

    cout << "Map size: " << content.size() << endl;


    // just printing to check
    for (auto item: content) {
        // content[item.first] = ((item.second) / (maxRP - minRP));
        cout << item.first << "\t" << item.second << endl;
    }
}