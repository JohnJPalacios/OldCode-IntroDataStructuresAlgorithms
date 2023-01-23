/************************************************************************/
/* File: KnightCircle.cpp. This is the implementation file for			*/
/* the KnightCircle class. Author: John Palacios with recycled old code	*/
/************************************************************************/

#include "KnightCircle.h"

KnightCircle::KnightCircle(string filename) {
	ifstream knightsFile;
	string name;
	int count = 0;											// Good book next to Mona Lisa Overdrive and Pattern Recongnition.

	// Create list from file
	knightsFile.open(filename.c_str());

	if (!knightsFile.is_open()) {
		cout << "Error oppening file " << filename << endl;
		exit(1);
	}

	while (knightsFile >> name) {
		count++;
		push_back(name, count);
	}

	// close file
	knightsFile.close();

	// Make the linked list circular
	tail->next = head;
}

void KnightCircle::begin_elemination() {
	KnightNode* temp = head;

	while (get_cardinality() > 1) {
		remove_next(temp);
		temp = temp->next;
	}
	temp = nullptr;
}

KnightCircle::~KnightCircle() {
	while (get_cardinality() > 0) { pop_front(); }

	head = nullptr;											//Ground tail
	tail = nullptr;											//Ground tail
}