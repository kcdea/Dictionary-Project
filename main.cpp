#include "dictionaryHashTable.cpp"
#include "TreeDict.h"
#include <chrono>

void release() {

	string input = "";
	TreeDict dict("engmix.txt");
	cout << "Enter a word to check if it is in our dictionary. If it is not, we will suggest similar words.\n";
	cout << "Type EXIT to exit the program." << endl;
	while (true) {
		cout << "\nPlease enter a word (all lowercase): ";
		cin >> input;

		if (input.compare("EXIT") == 0) {
			break;
		}

		dict.find(input);

		input = "";
	}
}

void findwords(string filename, TreeDict tree) {

	ifstream words(filename);
	string aux;

	int min = INFINITY;
	int max = 0;
	int average;
	long count = 0;
	int total = 0;

	while (getline(words, aux, ' ')) {
		auto start = chrono::high_resolution_clock::now();
		tree.find(aux, false);
		auto stop = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

		if (duration.count() < min)
			min = duration.count();
		if (duration.count() > max)
			max = duration.count();

		total += duration.count();
		count++;
	}
	average = total / count;
	cout << "Tree implementation completed " << count << " items in " << total / 1000000 << " seconds." << endl;
	cout << "Average case timing: " << average << " microseconds (" << average / 1000 << " ms)" << endl;
	cout << "Best case timing: " << min << " microseconds (" << min / 1000 << " ms)" << endl;
	cout << "Worst case timing: " << max << " microseconds (" << max / 1000 << " ms)" << endl;
}

void findwords(string filename, dictionaryHashTable table) {

	ifstream words(filename);
	string aux;

	int min = INFINITY;
	int max = 0;
	int average;
	long count = 0;
	int total = 0;

	while (getline(words, aux, ' ')) {
		auto start = chrono::high_resolution_clock::now();
		table.found(aux, false);
		auto stop = chrono::high_resolution_clock::now();

		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

		if (duration.count() < min)
			min = duration.count();
		if (duration.count() > max)
			max = duration.count();

		total += duration.count();
		count++;
	}
	average = total / count;
	cout << "Table implementation completed " << count << " items in " << total / 1000000 << " seconds." << endl;
	cout << "Average case timing: " << average << " microseconds (" << average / 1000 << " ms)" << endl;
	cout << "Best case timing: " << min << " microseconds (" << min / 1000 << " ms)" << endl;
	cout << "Worst case timing: " << max << " microseconds (" << max / 1000 << " ms)" << endl;
}


void test() {
	cout << "Performing timing tests:\n" << endl;

	cout << "TEST 1: DICTIONARY CONSTRUCTION" << endl;

	auto start = chrono::high_resolution_clock::now();
	TreeDict tree("engmix.txt");
	auto stop = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << "Tree implementation completed in " << duration.count() << " microseconds (" << duration.count() / 1000 << " ms)" << endl;

	ifstream f("engmix.txt");

	start = chrono::high_resolution_clock::now();
	dictionaryHashTable table(f);
	stop = chrono::high_resolution_clock::now();

	duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "Table implementation completed in " << duration.count() << " microseconds (" << duration.count() / 1000 << " ms)\n" << endl;

	cout << "TEST 2: FINDING EXISTING WORDS\n" << endl;

	findwords("correct words.txt", tree);
	cout << endl;
	findwords("correct words.txt", table);

	cout << "TEST 3: FINDING NOISY WORDS\n" << endl;

	findwords("correct words.txt", tree);
	cout << endl;
	findwords("correct words.txt", table);

	cout << "TEST 4: FINDING RANDOM WORDS\n" << endl;

	findwords("slightly misspelled.txt", tree);
	cout << endl;
	findwords("random.txt", table);
}

int main() {
	cout << "Welcome to the spellchecking dictionary of The Lexicon Jedis.\nA project made by Jabir Hossian, Jose Cabrera and Kaceja Calder.\n" << endl;

	int mode;
	bool valid = false;

	cout << "Type 1 to enter RELEASE mode." << endl << "Type 2 to enter TEST mode." << endl;
	while (!valid) {
		try {
			cout << "\nPlease enter your input: ";
			cin >> mode;
			if (mode != 1 && mode != 2)
				throw(mode);
			else {
				valid = true;
			}
		}
		catch (...) {
			cout << "Invalid input. Please try again." << endl;
		}
	}

	switch (mode) {
		case 1:
			cout << "You have entered RELEASE mode.\n" << endl;
			release();
			break;
		case 2:
			cout << "You have entered TEST mode.\n" << endl;
			test();
			break;
	}


	return 0;
}