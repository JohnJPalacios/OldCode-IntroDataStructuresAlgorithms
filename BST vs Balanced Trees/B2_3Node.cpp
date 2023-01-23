/***********************************************************************************/
/* File: Node.cpp. Implementation file for Node class. Author: John Palacios       */
/*                                                                                 */
/***********************************************************************************/

#include "B2_3Node.h"

BNode::BNode()
{
}

BNode::~BNode() {
	parent = nullptr;
	delete left;
	delete middle1;
	/*delete middle2;*/
	delete right;
}

BNode::BNode(string a, BNode* childLeft, BNode* childMiddle1) {
	A = a;
	left = childLeft;
	middle1 = childMiddle1;
}

bool BNode::keyInNode(string key) {
	if (key == A) { return true; }

	if (key == B) { return true; }

	/*if(key == C) {return true;}*/

	return false;
}