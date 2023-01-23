

#include "BSTree.h"
#include "AVLTree.h"
#include "B2_3Tree.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;

string produceRandomWord();

int main() {
	ofstream results;
	BSTree BSSorted;
	BSTree BSUnsorted;
	AVLTree AVLSorted;
	AVLTree AVLUnsorted;
	Tree BTreeSorted;
	Tree BTreeUnsorted;
	vector<string> sortededWords;
	vector<string> anorchicWords;
	static int DATA_SET_SIZE = 400000;
	clock_t clock1;
	clock_t clock2;
	clock_t clock3;
	clock_t clock4;
	clock_t clock5;
	clock_t clock6;
	clock_t clock7;
	clock_t clock8;
	clock_t clock9;
	clock_t clock10;
	clock_t clock11;
	clock_t clock12;
	clock_t clock13;
	clock_t clock14;
	clock_t clock15;
	clock_t clock16;
	clock_t clock17;
	clock_t clock18;
	clock_t clock19;
	clock_t clock20;
	clock_t clock21;
	clock_t clock22;
	clock_t clock23;
	clock_t clock24;

	results.open("Results4.txt");
	results << "/******************************BEGIN_REPORT***************************/\n"
		<< "DATA_SET_SIZE = " << DATA_SET_SIZE << " seven character words using string class\n";
	results << "Binary Search Tree\n";
	/*tree1.insert("bananna");
	tree1.insert("cucumber");
	tree1.insert("apple");

	tree1.inOrder();*/

	/*cout << produceRandomWord();*/

	for (int i = 0; i < DATA_SET_SIZE; i++) { anorchicWords.push_back(produceRandomWord()); }
	sortededWords = anorchicWords;
	sort(sortededWords.begin(), sortededWords.end());

	clock1 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BSSorted.insert(sortededWords.at(i));
	}
	clock2 = clock();

	results << "Insert sorted words: " << (float)(clock2 - clock1)/CLOCKS_PER_SEC << " seconds" << endl;

	clock3 = clock();

	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BSSorted.search(sortededWords.at(i));		/* Searching for words same order inserted? */
	}
	clock4 = clock();

	results << "Search sorted words: " << (float)(clock4 - clock3) / CLOCKS_PER_SEC << " seconds" << endl;

	clock5 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BSUnsorted.insert(anorchicWords.at(i));
	}
	clock6 = clock();

	results << "Insert unsorted words: " << (float)(clock6 - clock5) / CLOCKS_PER_SEC << " seconds" << endl;

	clock7 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BSUnsorted.search(anorchicWords.at(i));
	}
	clock8 = clock();

	results << "Search unsorted words: " << (float)(clock8 - clock7) / CLOCKS_PER_SEC << " seconds" << endl;

	clock9 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		AVLSorted.insert(sortededWords.at(i));
	}
	clock10 = clock();

	results << "AVL Tree\n";
	results << "Insert sorted words: " << (float)(clock10 - clock9) / CLOCKS_PER_SEC << " seconds" << endl;

	clock11 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		AVLSorted.search(sortededWords.at(i));		/* Searching for words same order inserted? */
	}
	clock12 = clock();

	results << "Search sorted words: " << (float)(clock12 - clock11) / CLOCKS_PER_SEC << " seconds" << endl;

	clock13 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		AVLUnsorted.insert(anorchicWords.at(i));
	}
	clock14 = clock();

	results << "Insert unsorted words: " << (float)(clock14 - clock13) / CLOCKS_PER_SEC << " seconds" << endl;

	clock15 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		AVLUnsorted.search(anorchicWords.at(i));
	}
	clock16 = clock();

	results << "Search unsorted words: " << (float)(clock16 - clock15) / CLOCKS_PER_SEC << " seconds" << endl;

	results << "2-3 Tree\n";

	clock17 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BTreeSorted.insert(sortededWords.at(i));
	}
	clock18 = clock();

	results << "Insert sorted words: " << (float)(clock18 - clock17) / CLOCKS_PER_SEC << " seconds" << endl;

	clock19 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BTreeSorted.search(sortededWords.at(i));		/* Searching for words same order inserted? */
	}
	clock20 = clock();

	results << "Search sorted words: " << (float)(clock20 - clock19) / CLOCKS_PER_SEC << " seconds" << endl;

	clock21 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BTreeUnsorted.insert(anorchicWords.at(i));
	}
	clock22 = clock();

	results << "Insert unsorted words: " << (float)(clock22 - clock21) / CLOCKS_PER_SEC << " seconds" << endl;

	clock23 = clock();
	for (int i = 0; i < DATA_SET_SIZE; i++) {
		BTreeUnsorted.search(anorchicWords.at(i));
	}
	clock24 = clock();

	results << "Search unsorted words: " << (float)(clock24 - clock23) / CLOCKS_PER_SEC << " seconds" << endl;

	results << "*******************END_OF_REPORT**********************";
	results.close();

	return 0;
}

string produceRandomWord() {
	//Produce a random 7 character word.
	string word = "";

	default_random_engine generator;
	uniform_int_distribution<int> distribution(65, 90);

	for (int i = 0; i < 7; i++) { word += distribution(generator); }
	return word;
}