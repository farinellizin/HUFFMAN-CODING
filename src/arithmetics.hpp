#ifndef ARITHMETICS_HPP
#define ARITHMETICS_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

bool stopLetters(string content);
string stringTreatment(string content);
void fillMap(unordered_map <string, float> *content, string docName, vector <string> *text);
float getMaxRP(unordered_map <string, float> *content); 
float getMinRP(unordered_map <string, float> *content); 
void normalizeAccounting(float maxRP, float minRP, unordered_map <string, float> &content);

#endif