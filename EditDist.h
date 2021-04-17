#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

float editDistance(string w1, string w2, float insCost, float delCost, float subCost);
float sub(char x, char y, float weight);