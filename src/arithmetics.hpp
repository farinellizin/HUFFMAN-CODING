#ifndef ARITHMETICS_HPP
#define ARITHMETICS_HPP
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

bool stopLetters(string content); // verify if it's a single letter
string stringTreatment(string content); // turns all the string into lower
void fillMap(unordered_map <string, float> *content, string docName); // fill unordered map with words as keys and how many times it appears
float getMaxRP(unordered_map <string, float> *content); // gets highest absolute value
float getMinRP(unordered_map <string, float> *content); // gets lowest absolute value
void normalizeAccounting(float maxRP, float minRP, unordered_map <string, float> &content);

#endif