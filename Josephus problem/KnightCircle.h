/************************************************************************/
/* Abstract Data Structure to be used in solving the "Josephus problem" */
/* File: KnightCircle.h, Author: John Palacios with modified old code	*/
/* (mine)																*/
/************************************************************************/
/* This class takes a file name at construction, opens it, reads in		*/
/* the list (newline seperated) words, creates a circularly linked      */
/* list. The begin_elemination() method simulates the the knights       */
/* eliminating eachother. Each knight eliminates the knight below on    */
/* the list until one knight remains. Print the list to reveal the      */
/* survivor.                                                            */
/************************************************************************/

#ifndef KNIGHTCIRCLE_H
#define KNIGHTCIRCLE_H

#include "KnightList.h"
#include <fstream>
using namespace std;

class KnightCircle : public KnightList {
public:
	KnightCircle() {}
	KnightCircle(string);
	void begin_elemination();
	~KnightCircle();
private:
};

#endif // !KNIGHTCIRCLE_H