/************************************************************************/
/* Abstract Data Structure to be used in solving the "Josephus problem" */
/* File: KnightList.h, Author: John Palacios with modified old code		*/
/* (mine)																*/
/************************************************************************/
/* This class has some added functionality that I wound up not using,   */
/* But that was merely due to time constraints and poor planning on     */
/* my part. I left them in because I already started this over once.    */
/************************************************************************/

#ifndef KNIGHTLIST_H
#define KNIGHTLIST_H
#include <iostream>
#include <string>
using namespace std;

//KnightNode data structure
struct KnightNode {
	string name;
	int pos;
	KnightNode* next;
	KnightNode(string name, int pos) : name(name), pos(pos) {}
};

//KnightList class declaration
class KnightList {

public:
	KnightList() {}
	KnightList(const KnightList &rhs);
	~KnightList();
	void print_list() const;
	friend ostream & operator<<(ostream &out, const KnightList &rhs);
	void push_front(string, int);
	void push_back(string, int);
	void pop_front();
	void remove_next(KnightNode* node);
	bool not_empty() const { return cardinality; }
	int get_cardinality() const { return cardinality; }
	const string & front() const { return head->name; }
	const string & back() const { return tail->name; }

protected:
	KnightNode* head = nullptr;
	KnightNode* tail = nullptr;
private:
	int cardinality = 0;
};

#endif // !KNIGHTLIST_H
