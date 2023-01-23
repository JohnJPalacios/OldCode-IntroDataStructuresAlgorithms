#ifndef AVLNODE_H
#define AVLNODE_H

#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(string key) : key(key) {}
	~Node();
	int height = 0;
	int balFac = 0;
	string key = "";
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
};

#endif // !AVLNODE_H