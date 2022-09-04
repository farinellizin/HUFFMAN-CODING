#include "arithmetics.hpp"

bool stopLetters(string content) {
    if (content.size() == 1) {
        return false;
    }

    return true;
}

string stringTreatment(string content) {
    string aux;

    for (long unsigned int i = 0; i < content.size(); i++) {
        if (content[i] != '.' && content[i] != ',' && content[i] != '/' && content[i] != ';' && content[i] != ':' && content[i] != '!' && 
        content[i] != '"' && content[i] != '\'' && content[i] != '[' && content[i] != ']' && content[i] != '{' && content[i] != '}' && 
        content[i] != '(' && content[i] != ')' && content[i] != '/' && content[i] != '|' && content[i] != '\\' && 
        content[i] != '*' && content[i] != '-' && content[i] != '+' && content[i] != '?' && content[i] != '.' && content[i] != '\n') {
            content[i] = tolower(content[i]);
            aux += content[i];
        }
    }

    cout << "Conteúdo: " << aux << endl;

    return aux;
}

void fillMap(unordered_map <string, float> *content, string docName) {
    string word;
    
    ifstream myfile;
    myfile.open(docName);
    if (myfile.is_open()) {
        while(!myfile.eof()) {
            getline(myfile, word, ' ');
            
            if (stopLetters(word)) {
                word = stringTreatment(word);

                auto item = content -> find(word);
                if (item != content -> end()) {
                    item -> second++;
                } else {
                    content -> emplace(word, 1);
                }
            }
        }
    }
}


float getMaxRP(unordered_map <string, float> *content) {
    float max = 0;
    string aux;

    for (auto item: *content) {
        if (item.second > max) {
            max = item.second;
            aux = item.first;
        }
    }

    return max;
}

float getMinRP(unordered_map <string, float> *content) {
    float min = 20000;
    string aux;

    for (auto item: *content) {
        if (item.second < min) {
            min = item.second;
            aux = item.first;
        }
    }

    return min;
}

// void normalizeAccounting(float maxRP, float minRP, unordered_map <string, float> *content) {
//     for (auto item: *content) {
//         content[item.first] = ((item.second) / (maxRP - minRP));
//         cout << item.first << "\t" << item.second << endl;
//     }

//     cout << endl << endl << endl;
// }