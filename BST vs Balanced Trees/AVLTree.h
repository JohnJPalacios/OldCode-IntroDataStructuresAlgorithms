


#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"

class AVLTree
{
private:
	Node* root = nullptr;
public:
	AVLTree();
	~AVLTree();
	void insert(const string &);								/*Insert an item to the binary search tree and perform rotation if necessary*/
	Node* search(const string &key) { return search(root, key); }
	int balanceFactor(Node* node) { return node->balFac; }		/*Return the balance factor of a given node.*/
	void printBalanceFactors() { printBalanceFactors(root); }	/*Traverse and print the tree in inorder notation. Print the string followed*/
																/*by its balance factor in parentheses followed by a , and one space.*/
	void visualizeTree(const string &);							/*Generate dotty file and visualize the tree using dotty program. Call this*/
																/*function before and after rotation.*/
private:
	Node* findUnbalancedNode(Node*);							/*Find and return the closest unbalanced node (with balance factor of 2 or -2)*/
																/*to the inserted node.*/
	Node* rebalance(Node*);
	void updateHeight(Node*);
	bool setChild(Node*, string, Node*);
	bool replaceChild(Node*, Node*, Node*);
	int getBalance(Node*);
	Node* search(Node*, const string &);
	bool removeNode(Node*);
	void rotate(Node* node) { rebalance(node->parent); }		/*Implement four possible imbalance cases and update the parent of the given node.*/
	Node* rotateLeft(Node*);									/*Rotate the subtree to left at the given node and returns the new subroot.*/
	Node* rotateRight(Node*);									/*Rotate the subtree to right at the given node and returns the new subroot.*/
	void insertNode(Node*);
	void printBalanceFactors(Node *);
	void visualizeTree(ofstream &, Node *);
	void deleteNode(Node*);
};

#endif // !AVLTREE_H