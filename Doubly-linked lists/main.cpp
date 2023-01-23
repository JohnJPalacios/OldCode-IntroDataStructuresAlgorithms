/****************************************************/
/* File: main.cpp; this is a test harness for the	*/
/* Intlist class									*/
/* Author: John Palacios							*/
/****************************************************/

#include"IntList.h"
using namespace std;

int main() {
	/****************************************************/
	/* Testing the Default constructor of the IntList	*/
	/* class											*/
	/****************************************************/
	IntList list1;

	/****************************************************/
	/* Testing the push_front function of the IntList	*/
	/* class. list1 = {1, 2, 3}	after test.				*/
	/****************************************************/
	list1.push_front(3);
	list1.push_front(2);
	list1.push_front(1);

	/****************************************************/
	/* Testing the pop_front function of the IntList	*/
	/* class. list1 = {}	after test.					*/
	/****************************************************/
	list1.pop_front();
	list1.pop_front();
	list1.pop_front();

	/****************************************************/
	/* Testing the push_back function of the IntList	*/
	/* class. list1 = {3, 2, 1}	after test.				*/
	/****************************************************/
	list1.push_back(3);
	list1.push_back(2);
	list1.push_back(1);

	/****************************************************/
	/* Testing the pop_back function of the IntList		*/
	/* class. list1 = {}	after test.					*/
	/****************************************************/
	list1.pop_back();
	list1.pop_back();
	list1.pop_back();

	/****************************************************/
	/* Testing ostream insertion operator overload with	*/
	/* IntList class. console should read 1 2 3			*/
	/****************************************************/
	list1.push_front(3);
	list1.push_front(2);
	list1.push_front(1);
	cout << list1;

	/****************************************************/
	/* Testing the printReverse function of the IntList	*/
	/* class. console should read 3 2 1					*/
	/****************************************************/
	cout << endl;
	list1.printReverse();
	return 0;
}