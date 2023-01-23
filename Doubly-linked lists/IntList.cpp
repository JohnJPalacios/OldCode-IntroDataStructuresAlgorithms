//
//

#include "IntList.h"
using namespace std;

IntList::IntList() {
	dummyHead = new IntNode(-1);
	dummyTail = new IntNode(-1);

	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
}

IntList::IntList(const IntList &cpy) {
	IntNode *temp = nullptr;								//Holds address of next node
	if (this->dummyHead != nullptr) {						//Need to delete current nodes, then while currNode != nullptr,
		while (!this->empty()) {							//Loop through list deleting items until end is reached
			this->pop_front();
		}
	}

	/*this->IntList::IntList();								Apparently zyBooks doesn't like this							*/
	/*	Setting up dummy variables as in default constructor																*/	
	dummyHead = new IntNode(-1);
	dummyTail = new IntNode(-1);

	dummyHead->next = dummyTail;
	dummyTail->prev = dummyHead;
	temp = cpy.dummyHead->next;
	while (temp != cpy.dummyTail) {							//Push each of cpy's values onto the list
		this->push_back(temp->data);
		temp = temp->next;
	}
}

IntList::~IntList() {
	IntNode* run = dummyHead;
	while (run != nullptr) {
		run = run->next;
		delete dummyHead;
		dummyHead = run;
	}
}

void IntList::push_front(int value) {
	IntNode* temp = new IntNode(value);
	temp->next = dummyHead->next;
	temp->prev = dummyHead;
	dummyHead->next->prev = temp;
	dummyHead->next = temp;
}

void IntList::pop_front() {
	IntNode* temp = dummyHead->next;

	if (temp != dummyTail) {
		dummyHead->next = temp->next;
		temp->next->prev = dummyHead;
		delete temp;
		temp = nullptr;
	}
}

void IntList::push_back(int value) {
	IntNode* temp = new IntNode(value);
	temp->next = dummyTail;
	temp->prev = dummyTail->prev;
	dummyTail->prev->next = temp;
	dummyTail->prev = temp;
}

void IntList::pop_back() {
	IntNode* temp = dummyTail->prev;

	if (temp != dummyHead) {
		dummyTail->prev = temp->prev;
		temp->prev->next = dummyTail;
		delete temp;
		temp = nullptr;
	}
}

ostream & operator<<(ostream &out, const IntList &rhs) {
	IntList copy(rhs);										//Duplicate of rhs

	while (!copy.empty()) {									//insert rhs values into out stream
		out << copy.dummyHead->next->data;
		copy.pop_front();
		if (!copy.empty()) { out << " "; }					//Add space only if copy is not empty
	}
	return out;
}

void IntList::printReverse() const {
	IntNode* temp = dummyTail->prev;

	while (temp != dummyHead) {
		cout << temp->data;
		temp = temp->prev;
		if (temp != dummyHead) { cout << " "; }					//Add space only if copy is not empty
	}
}