#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <cmath>
#include "EditDist.h"

using namespace std;
class dictionaryHashTable {
    unordered_set<string> words;
public:
    dictionaryHashTable(ifstream& file)
    {
        while (!file.eof())
        {
            string word;
            getline(file, word);
            words.insert(word);
        }
    }
    unordered_set<string> getWords()
    {
        return words;
    }
    void found(string& word, bool display = true)
    {
        if (words.count(word)) {
            if (display)
                cout << word << " is in the dictionary" << endl;
        }

        else {
            if (display)
                cout << word << " is not in the dictionary, did you mean: ";

            vector<string> pool;
            float minDist = INFINITY;

            for (auto itr = words.begin(); itr != words.end(); itr++) {
                float dist = editDistance(*itr, word, 1, 1, 2);
                if (dist < minDist) {
                    minDist = dist;
                    pool.clear();
                    pool.push_back(*itr);
                }
                else if (dist == minDist)
                    pool.push_back(*itr);
            }

            if (!display)
                return;

            for (unsigned int i = 0; i < pool.size(); i++) {
                cout << pool[i] << "? ";
            }
            cout << "\n";
        }
    }

};


