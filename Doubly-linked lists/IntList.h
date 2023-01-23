//Class interface file for struct IntNode and class IntList, doubly linked list 
//abstract data type implementations. File: IntList.h
//Author: John Palacios

#ifndef INTLIST_H
#define INTLIST_H

#include<iostream>
using namespace std;

/**********************************/
/*Description goes here my friend */
/*Description goes here my friend */
/**********************************/
struct IntNode {
	int data;
	IntNode *prev;
	IntNode *next;
	IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {
public:
	IntList ();
	IntList(const IntList &cpy);
	void push_front(int value);
	void pop_front();
	void push_back(int value);
	void pop_back();
	bool empty() const { return (dummyHead->next == dummyTail); }
	friend ostream & operator<<(ostream &out, const IntList &rhs);
	void printReverse() const;
	~IntList ();

private:
	IntNode* dummyHead;
	IntNode* dummyTail;
};

#endif // !INTLIST_H
