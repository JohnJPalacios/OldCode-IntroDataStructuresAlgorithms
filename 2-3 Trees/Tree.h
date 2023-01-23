/***********************************************************************************/
/* File: Tree.h. Header file for the Tree Class. Author: John Palacios. This       */
/* solution does not quite work yet, but after spending more than 10 hrs, it's done*/
/***********************************************************************************/

#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>
using namespace std;

class Tree {
private:
	Node* root = nullptr;
public:
	Tree();
	~Tree();
	void insert(string key) { insert(root, key); }
	bool search(string key) { return !(search(root, key) == nullptr); }
	void remove(string key);
	void inOrder() { printInOrder(root); }
	void preOrder() { printPreOrder(root); }
	void postOrder() { printPostOrder(root); }

private:
	Node* split(Node* node, string key);
	void insertKeyWithChildren(Node* parent, string key, Node* leftChild, Node* righChild);
	void insertIntoLeaf(Node* node, string key);
	Node* insert(Node* node, string key);
	Node* search(Node* node, string key);
	int getKeyIndex(Node* node, string key);
	void removeKey(Node* node, int index);
	void printInOrder(Node* node);
	void printPreOrder(Node* node);
	void printPostOrder(Node* node);
	/*void splitLeaf(Node* node, string small, string medium, string large);*/
	/*void splitInternal(Node* node, Node* middle1, Node* middle2, string small, string medium, string large);*/
	void DeleteNode(Node* node);
};

#endif // !TREE_H