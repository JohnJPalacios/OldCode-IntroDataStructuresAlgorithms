
#ifndef RBTREE_H
#define RBTREE_H
#include "Node.h"

class RBTree
{
private:
	Node* root = nullptr;
public:
	RBTree();
	~RBTree();
	void insert(string key);
	bool search(string key) { return !(BSTreeSearch(root, key) == nullptr); }
	void remove(string key);

private:
	bool RBTreeSetChild(Node*, string, Node*);
	bool RBTreeReplaceChild(Node*, Node*, Node*);
	void RBTreeRotateLeft(Node*);
	void RBTreeRotateRight(Node*);
	Node* RBTreeGetGrandparent(Node*);
	Node* RBTreeGetUncle(Node*);
	void RBTreeBalance(Node*);
	Node* BSTreeInsert(Node*, string);
	Node* BSTreeSearch(Node*, string);
	void RBTreeRemoveNode(Node*);
	Node* RBTreeGetPredecessor(Node*);
	Node* RBTreeGetSibling(Node*);
	bool RBTreeIsNonNullAndRed(Node* node) { return node == nullptr ? false : node->color == 1; }
	bool RBTreeIsNullOrBlack(Node* node) { return node == nullptr ? true : node->color == 0; }
	bool RBTreeAreBothChildrenBlack(Node*);
	bool RBTreeTryCase1(Node*);
	bool RBTreeTryCase2(Node*, Node*);
	bool RBTreeTryCase3(Node*, Node*);
	bool RBTreeTryCase4(Node*, Node*);
	bool RBTreeTryCase5(Node*, Node*);
	bool RBTreeTryCase6(Node*, Node*);
	void RBTreePrepareForRemoval(Node*);
	void BSTreeRemove(string);
};

RBTree::RBTree()
{
}

RBTree::~RBTree()
{
}

#endif // !RBTREE_H
