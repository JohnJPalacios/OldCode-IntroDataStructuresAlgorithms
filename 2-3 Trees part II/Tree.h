/***********************************************************************************/
/* File: Tree.h. Header file for the Tree Class. Author: John Palacios. This       */
/*                                                                                 */
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
	Node* getLeftSib(Node*);
	Node* getRightSib(Node*);
	void rotateRight(Node*);
	void rotateLeft(Node*);
	void fuse(Node*, Node*);
	void merge(Node*);
	string getMinKey(Node*);
	Node* getRigtmostChild(Node*);
	string getParentKeyLeftOfChild(Node*, Node*);
	string getPArentKeyRightOfChild(Node*, Node*);
	void addKeyAndChild(Node*, string, Node*);
	void setParentKeyLeftOfChild(Node*, Node*, string);
	void setParentKeyRightOfChild(Node*, Node*, string);
	Node* nextNode(Node*, string);
	bool keySwap(Node*, string, string);
	Node* findSuccessor(Node*, string);
	void printInOrder(Node* node);
	void printPreOrder(Node* node);
	void printPostOrder(Node* node);
	/*void splitLeaf(Node* node, string small, string medium, string large);*/
	/*void splitInternal(Node* node, Node* middle1, Node* middle2, string small, string medium, string large);*/
	void DeleteNode(Node* node);
};

#endif // !TREE_H