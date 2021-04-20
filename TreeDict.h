#pragma once
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "EditDist.h"

using namespace std;

class TreeDict {
	struct Node {
		char letter;
		map<char, Node*> children;

		Node(char l) { letter = l; }
	};

private:
	Node* root = new Node('\x02');
	int size = 0;

	void addWord(string word);
	void unpack(Node* root, vector<string>& words, string word);
	vector<string> findCandidates(string word);
public:
	TreeDict(string filename);
	void find(string word, bool display = true);
	int getSize() { return size; }
};


void TreeDict::addWord(string word) {
	Node* aux = root;

	for (unsigned int i = 0; i < word.length(); i++) {
		// For readability
		char letter = word[i];

		auto found = aux->children.find(letter);

		// If it does not find the letter in the node's children, creates it and moves the temp pointer to the created child
		if (found == aux->children.end()) {
			aux->children.emplace(letter, new Node(letter));
		}

		aux = aux->children[letter];
	}

	// End of word at the end
	aux->children.emplace('\x03', new Node('\x03'));
	size++;
}

TreeDict::TreeDict(string filename) {
	ifstream file(filename);

	while (!file.eof())
	{
		string word;
		getline(file, word);
		addWord(word);
	}
}

void TreeDict::unpack(Node* root, vector<string>& pool, string word) {
	for (auto itr = root->children.begin(); itr != root->children.end(); itr++) {

		if (itr->first == '\x03') {
			pool.push_back(word);
			continue;
		}

		unpack(itr->second, pool, word + itr->first);
	}
}

vector<string> TreeDict::findCandidates(string word) {
	vector<string> words, pool;
	Node* aux = root->children[word[0]];
	string temp = "";
	temp += word[0];
	unpack(aux, words, temp);

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

	return pool;
}

void TreeDict::find(string word, bool display) {
	Node* aux = root;

	for (unsigned int i = 0; i < word.length(); i++) {
		// For readability
		char letter = word[i];

		auto found = aux->children.find(letter);

		// If it does not find the letter in the node's children, returns
		if (found == aux->children.end()) {
			if (display)
				cout << word << " is not in the dictionary, did you mean: ";

			vector<string> pool = findCandidates(word);

			if (!display)
				return;

			for (unsigned int i = 0; i < pool.size(); i++) {
				cout << pool[i] << "? ";
			}
			cout << "\n";
			return;
		}

		aux = aux->children[letter];
	}
	if (display)
		cout << word << " is in the dictionary" << endl;
}
