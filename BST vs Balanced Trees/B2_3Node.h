/***********************************************************************************/
/* File: Node.h. Header file for the BNode class. Author: John Palacios.            */
/*                                                                                 */
/***********************************************************************************/

#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>
using namespace std;

class BNode
{
public:
	BNode();
	BNode(string a, BNode* childLeft, BNode* childMiddle1);
	bool keyInNode(string key);
	bool isLeaf() { return left == nullptr; }
	~BNode();
	string A = "";
	string B = "";
	/*string C = "";*/
	BNode* left = nullptr;
	BNode* middle1 = nullptr;
	/*BNode* middle2 = nullptr;*/
	BNode* right = nullptr;
	BNode* parent = nullptr;
};

#endif // !NODE_H
