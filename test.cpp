#include<iostream>
#include<fstream>
#include<sstream>
#include<cctype>
#include<ctime>

using namespace std;

void stripText(string &input, string path){
    ofstream out(path);
    
    string justWords = "";

    bool inSpace = false;
    bool skipWord = false;
    for(char c: input){
        if(inSpace && isupper(c)){
            inSpace = false;
            skipWord = true;
        }
        else if(isalpha(c) && !skipWord){
            inSpace = false;
            justWords = justWords + (char)tolower(c);
        }
        else if(skipWord && (isspace(c) || c == '-') && !inSpace){
            inSpace = true;
            skipWord = false;
        }
        else if((isspace(c) || c == '-') && !inSpace){
            inSpace = true;
            justWords = justWords + " ";
            skipWord = false;
        }
    }
    out << justWords;
    out.close();
}

void jumbleText(string & input, string path){
    ofstream out(path);
    
    string jumbledWords = "";
    string currentWord = "";

    srand((unsigned) time(0));
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    bool inSpace = false;
    bool skipWord = false;
    for(char c: input){
        if(inSpace && isupper(c)){
            inSpace = false;
            skipWord = true;
        }
        else if(isalpha(c) && !skipWord){
            inSpace = false;
            currentWord = currentWord + (char)tolower(c);
        }
        else if(skipWord && (isspace(c) || c == '-') && !inSpace){
            inSpace = true;
            skipWord = false;
        }
        else if((isspace(c) || c == '-') && !inSpace){

            int option = rand() % 3;
            int toAlter = rand() % currentWord.size();

            switch(option){
                case 0: //Remove to alter
                    currentWord.erase(toAlter, 1);
                    break;
                case 1: //Change to alter
                    currentWord[toAlter] = letters[rand() % 26];
                    break;
                case 2: //Add at toAlter
                    string randChar (1, letters[rand() % 26]);
                    currentWord.insert(toAlter, randChar);
                    break;
            }

            inSpace = true;
            jumbledWords = jumbledWords + currentWord + " ";
            currentWord = "";
            skipWord = false;
        }
    }
    out << jumbledWords;
    out.close();
}

void randomWords(string path){
    ofstream out(path);
    
    string randWords = "";
    srand((unsigned) time(0));
    char letters[] = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < 45000; i++){
        int length = rand() % 12;

        string currentWord = "";
        for(int j = 0; j < length; j++){
            char c = letters[rand() % 26];
            currentWord = currentWord + c;
        }
        randWords = randWords + currentWord + " ";
    }

    out << randWords;
    out.close();
}

int main(){
    ifstream sourceFile("C:/Users/kccal/OneDrive/Desktop/VS Code/full book.txt");
    if(sourceFile.is_open()){
        string input((istreambuf_iterator<char>(sourceFile)), istreambuf_iterator<char>());
        stripText(input, "C:/Users/kccal/OneDrive/Desktop/VS Code/correct words.txt");
        jumbleText(input, "C:/Users/kccal/OneDrive/Desktop/VS Code/slightly misspelled.txt");
        randomWords("C:/Users/kccal/OneDrive/Desktop/VS Code/random.txt");
    }
}
