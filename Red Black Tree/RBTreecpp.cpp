/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/

#include "RBTree.h"

bool RBTree::RBTreeSetChild(Node* parent, string withChild, Node* child) {
	if (withChild != "left" || withChild != "right") { return false; }
	if (withChild == "left") { parent->left = child; }
	else { parent->right = child; }
	if (child != nullptr) { child->parent = parent; }
	return true;
}

bool RBTree::RBTreeReplaceChild(Node* parent, Node* currentChild, Node* newChild) {
	if (parent->left == currentChild) { return RBTreeSetChild(parent, "left", newChild); }
	else if (parent->right == currentChild) { return RBTreeSetChild(parent, "right", newChild); }
	return false;
}

void RBTree::RBTreeRotateLeft(Node* node) {
	Node* rightLeftChild = node->right->left;
	if (node->parent != nullptr) { RBTreeReplaceChild(node->parent, node, node->right); }
	else {
		root = node->right;
		root->parent = nullptr;
	}
	RBTreeSetChild(node->right, "left", node);
	RBTreeSetChild(node, "right", rightLeftChild);
}

void RBTree::RBTreeRotateRight(Node* node) {
	Node* leftRightChild = node->left->right;
	if (node->parent != nullptr) { RBTreeReplaceChild(node->parent, node, node->left); }
	else {
		root = node->left;
		root->parent = nullptr;
	}
	RBTreeSetChild(node->left, "right", node);
	RBTreeSetChild(node, "left", leftRightChild);
}

Node* RBTree::RBTreeGetGrandparent(Node* node) {
	if (node->parent == nullptr) { return nullptr; }
	return node->parent->parent;
}

Node* RBTree::RBTreeGetUncle(Node* node) {
	Node* grandparent = RBTreeGetGrandparent(node);
	if (grandparent == nullptr) { return nullptr; }
	if (grandparent->left == node->parent) { return grandparent->right; }
	else { return grandparent->left; }
}

void RBTree::RBTreeBalance(Node* node) {
	if (node->parent == nullptr) {
		node->color = 0;
		return;
	}
	if (node->parent->color == 0) { return; }

	Node* parent = node->parent;
	Node* grandparent = RBTreeGetGrandparent(node);
	Node* uncle = RBTreeGetUncle(node);

	if (uncle != nullptr && uncle->color == 1) {
		parent->color = uncle->color = 0;
		grandparent->color = 1;
		RBTreeBalance(grandparent);
	}
	if (node == parent->right && parent == grandparent->left) {
		RBTreeRotateLeft(parent);
		node = parent;
		parent = node->parent;
	}
	else if (node == parent->left && parent == grandparent->right) {
		RBTreeRotateRight(parent);
		node = parent;
		parent = node->parent;
	}
	parent->color = 0;
	grandparent->color = 1;
	if (node == parent->left) { RBTreeRotateRight(grandparent); }
	else { RBTreeRotateLeft(grandparent); }
}

Node* RBTree::BSTreeInsert(Node* node, string key) {
	if (node == nullptr) {
		Node* temp = new Node(key);
		root = temp;
		temp->parent = nullptr;
		return root;
	}

	if (key < node->data) {
		if (node->left == nullptr) {
			Node* temp = new Node(key);
			node->left = temp;
			temp->parent = node;
			return temp;
		}
		else { return BSTreeInsert(node->left, key); }
	}
	if (key > node->data) {
		if (node->right == nullptr) {
			Node* temp = new Node(key);
			node->right = temp;
			temp->parent = node;
			return temp;
		}
		else { return BSTreeInsert(node->right, key); }
	}
}

void RBTree::insert(string key) {
	if (!search(key)) { 
		Node* temp = BSTreeInsert(root, key);
		temp->color = 1;
		RBTreeBalance(temp);
	}
}

Node* RBTree::BSTreeSearch(Node* node, string key) {
	if (node == nullptr) { return nullptr; }
	if (node->data == key) { return node; }
	return key < node->data ? BSTreeSearch(node->left, key) : BSTreeSearch(node->right, key);
}

void RBTree::remove(string key) {
	Node* temp = BSTreeSearch(root, key);
	if (temp != nullptr) { RBTreeRemoveNode(temp); }
}

void RBTree::RBTreeRemoveNode(Node* node) {
	if (node->left != nullptr && node->right != nullptr) {
		Node* predecessor = RBTreeGetPredecessor(node);
		string predeccessorKey = predecessor->data;
		RBTreeRemoveNode(predecessor);
		node->data = predeccessorKey;
		return;
	}

	if (node->color == 0) { RBtrePrepareForRemoval(node); }
	BSTreeRemove(node->data);
}

Node* RBTree::RBTreeGetPredecessor(Node* node) {
	node = node->left;
	while (node->right != nullptr) { node = node->right; }
	return node;
}

Node* RBTree::RBTreeGetSibling(Node* node) {
	if (node->parent != nullptr) { return node == node->parent->left ? node->parent->right : node->parent->left; }
	return nullptr;
}

bool RBTree::RBTreeAreBothChildrenBlack(Node* node) {
	if (node->left != nullptr && node->left->color == 1) { return false; }
	if (node->right != nullptr && node->right->color == 1) { return false; }
	return true;
}

void RBTree::RBTreePrepareForRemoval(Node* node) {
	if (RBTreeTryCase1(node)) { return; }

	Node* sibling = RBTreeGetSibling(node);

	if (RBTreeTryCase2(node, sibling)) { sibling = RBTreeGetSibling(node); }
	if (RBTreeTryCase3(node, sibling)) { return; }
	if (RBTreeTryCase4(node, sibling)) { return; }
	if (RBTreeTryCase5(node, sibling)) { sibling = RBTreeGetSibling(node); }
	if (RBTreeTryCase6(node, sibling)) { sibling = RBTreeGetSibling(node); }

	sibling->color = node->parent->color;
	node->parent->color = 0;
	if (node == node->parent->left) {
		sibling->right->color = 0;
		RBTreeRotateLeft(node->parent);
	}
	else {
		sibling->left->color = 0;
		RBTreeRotateRight(node->parent);
	}
}

bool RBTree::RBTreeTryCase1(Node* node) {
	return node->color == 1 || node->parent == nullptr ? true : false;
}
bool RBTree::RBTreeTryCase2(Node* node, Node* sibling) {
	if (sibling->color == 1) {
		node->parent->color = 1;
		sibling->color = 0;
		if (node == node->parent->left) { RBTreeRotateLeft(node->parent); }
		else { RBTreeRotateRight(node->parent); }
		return true;
	}
	return false;
}

bool RBTree::RBTreeTryCase3(Node* node, Node* sibling) {
	if (node->parent->color == 0 && RBTreeAreBothChildrenBlack(sibling)) {
		sibling->color = 1;
		RBTreePrepareForRemoval(node->parent);
		return true;
	}
	return false;
}

bool RBTree::RBTreeTryCase4(Node* node, Node* sibling) {
	if (node->parent->color == 1 && RBTreeAreBothChildrenBlack(sibling)) {
		node->parent->color = 0;
		sibling->color = 1;
		return true;
	}
	return false;
}

bool RBTree::RBTreeTryCase5(Node* node, Node* sibling) {
	if (RBTreeIsNonNullAndRed(sibling->left) && RBTreeIsNullOrBlack(sibling->right)
		&& node == node->parent->left) {
		sibling->color = 1;
		sibling->left->color = 0;
		RBTreeRotateRight(sibling);
		return true;
	}
	return false;
}

bool RBTree::RBTreeTryCase6(Node* node, Node* sibling) {
	if (RBTreeIsNullOrBlack(sibling->left) && RBTreeIsNonNullAndRed(sibling->right)
		&& node == node->parent->right) {
		sibling->color = 1;
		sibling->right->color = 0;
		RBTreeRotateLeft(sibling);
		return true;
	}
	return false;
}