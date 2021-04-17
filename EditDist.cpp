#include "EditDist.h"


// Auxiliary function that compares if two characters are equal and returns the appropriate substitution cost depending on the case
float sub(char x, char y, float weight) {
	if (x == y)
		return 0;
	else
		return weight;
}

float editDistance(string w1, string w2, float insCost, float delCost, float subCost) {

	vector<vector<float>> matrix;
	matrix.resize(w1.size() + 1);
	// Initialize the matrix
	for (unsigned int i = 0; i <= w1.size(); i++) {
		for (unsigned int j = 0; j <= w2.size(); j++) {
			matrix[i].resize(w2.size() + 1, 0);
		}
	}

	for (unsigned int i = 0; i < matrix.size(); i++) {
		matrix[i][0] = float(i);
	}

	for (unsigned int i = 0; i < matrix[0].size(); i++) {
		matrix[0][i] = float(i);
	}


	for (unsigned int i = 1; i < matrix.size(); i++) {
		for (unsigned int j = 1; j < matrix[0].size(); j++) {
			// First, initialize the matrix with a delete cost
			matrix[i][j] = matrix[i - 1][j] + delCost;
			// If the insert cost is lower, replace it
			if (matrix[i][j - 1] + insCost < matrix[i][j])
				matrix[i][j] = matrix[i][j - 1] + insCost;
			// If the substitution cost is lower, replace it
			if (matrix[i - 1][j - 1] + sub(w1[i - 1], w2[j - 1], subCost) < matrix[i][j])
				matrix[i][j] = matrix[i - 1][j - 1] + sub(w1[i - 1], w2[j - 1], subCost);
		}
	}


	return matrix[w1.size()][w2.size()]; // The edit distance will always be the last entry of the matrix when looked from top to bottom
}