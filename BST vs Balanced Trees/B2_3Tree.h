/***********************************************************************************/
/* File: Tree.h. Header file for the 2-3 Tree Class. Author: John Palacios. This   */
/* solution does not quite work yet, but after spending more than 10 hrs, it's done*/
/***********************************************************************************/

#ifndef TREE_H
#define TREE_H

#include "B2_3Node.h"
#include <iostream>
using namespace std;

class Tree {
private:
	BNode* root = nullptr;
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
	BNode* split(BNode* node, string key);
	void insertKeyWithChildren(BNode* parent, string key, BNode* leftChild, BNode* righChild);
	void insertIntoLeaf(BNode* node, string key);
	BNode* insert(BNode* node, string key);
	BNode* search(BNode* node, string key);
	int getKeyIndex(BNode* node, string key);
	void removeKey(BNode* node, int index);
	void printInOrder(BNode* node);
	void printPreOrder(BNode* node);
	void printPostOrder(BNode* node);
	/*void splitLeaf(Node* node, string small, string medium, string large);*/
	/*void splitInternal(Node* node, Node* middle1, Node* middle2, string small, string medium, string large);*/
	void DeleteNode(BNode* node);
};

#endif // !TREE_H