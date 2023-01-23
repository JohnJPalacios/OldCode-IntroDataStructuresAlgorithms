/***********************************************************************************/
/* File: Node.h. Header file for the Node class. Author: John Palacios.            */
/*                                                                                 */
/***********************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(string a, Node* childLeft, Node* childMiddle1);
	bool keyInNode(string key);
	bool isLeaf() { return left == nullptr; }
	~Node();
	string A = "";
	string B = "";
	/*string C = "";*/
	Node* left = nullptr;
	Node* middle1 = nullptr;
	/*Node* middle2 = nullptr;*/
	Node* right = nullptr;
	Node* parent = nullptr;
};

#endif // !NODE_H
