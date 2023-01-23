/***********************************************************************************/
/* File: Node.cpp. Implementation file for Node class. Author: John Palacios       */
/*                                                                                 */
/***********************************************************************************/

#include "Node.h"

Node::Node()
{
}

Node::~Node() {
	cout << "Calling delete on node containing: "
		<< A << ", " << B /*<< C*/ << endl;
	parent = nullptr;
	delete left;
	delete middle1;
	/*delete middle2;*/
	delete right;
}

Node::Node(string a, Node* childLeft, Node* childMiddle1) {
	A = a;
	left = childLeft;
	middle1 = childMiddle1;
}

bool Node::keyInNode(string key) {
	if (key == A) { return true; }

	if (key == B) { return true; }

	/*if(key == C) {return true;}*/

	return false;
}