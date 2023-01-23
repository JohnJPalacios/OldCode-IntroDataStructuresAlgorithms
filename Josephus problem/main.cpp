/************************************************************************/
/* File: main.cpp. This is a test harness for the KnightCircle class	*/
/* Author: John Palacios												*/
/************************************************************************/

#include "KnightCircle.h"
using namespace std;

int main() {
	string file;
	/************************************************************************/
	/* This class takes a file name at construction, opens it, reads in		*/
	/* the list (newline seperated) words, creates a circularly linked      */
	/* list. The begin_elemination() method simulates the the knights       */
	/* eliminating eachother. Each knight eliminates the knight below on    */
	/* the list until one knight remains. Print the list to reveal the      */
	/* survivor.                                                            */
	/************************************************************************/
	
	/************************************************************************/
	/*	To test, comment out cout/in statemts and uncommment line beneath	*/
	/*	that.																*/
	/************************************************************************/
	cout << "Please enter name of file containing list of names\n";
	cin >> file;
	/*file = "Knights.txt";*/
	KnightCircle circle(file);
	
	circle.begin_elemination();
	circle.print_list();
	cout << " is the last knight standing\n";
	/************************************************************************/
	/* I could have added a lot more interactivity, but I had a lot of      */
	/* other obligations. I have written menues and such before, so that    */
	/* wouldn't really be learning anything new.                            */
	/************************************************************************/

	return 0;
}