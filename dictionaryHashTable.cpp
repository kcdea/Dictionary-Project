#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "EditDist.h"
using namespace std;
class dictionaryHashTable{
    unordered_set<string> words;
public:
    dictionaryHashTable(ifstream &file)
    {
        while(!file.eof())
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
    bool found(string &word)
    {
        if (words.count(word)) return true;
        else return false;
    }
   
};

int main()
{
    ifstream file("engmix.txt");
    dictionaryHashTable dictionary(file);
    unordered_set<string> words = dictionary.getWords();
    for (auto & word:words)
        cout << word << endl;
    return 0;
}
