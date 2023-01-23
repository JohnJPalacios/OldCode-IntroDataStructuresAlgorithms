/***********************************************************************************/
/* File: Tree.cpp. Implementation file for Tree.h. Author: John Palacios with help */
/* from: Ethan White                                                               */
/***********************************************************************************/

#include "B2_3Tree.h"

Tree::Tree() {
	root = new BNode;
}

Tree::~Tree() {
	DeleteNode(root);
}

void Tree::DeleteNode(BNode* node) {
	if (node == nullptr) { return; }

	DeleteNode(node->left);
	DeleteNode(node->middle1);
	DeleteNode(node->right);
	node->parent = nullptr;
	node->left = nullptr;
	node->middle1 = nullptr;
	node->right = nullptr;

	delete node;
}

void Tree::printInOrder(BNode* node) {
	if (node == nullptr) { return; }
	/*if (!node->B.empty()) { node = split(node); }*/

	printInOrder(node->left);
	cout << ", " << node->A << ", ";
	printInOrder(node->middle1);
	cout << ", " << node->B << ", ";

	if (node->right != nullptr) { printInOrder(node->right); }
}

void Tree::printPreOrder(BNode* node) {
	if (node == nullptr) { return; }
	/*if (!node->B.empty()) { node = split(node); }*/

	cout << node->A << ", ";
	printPreOrder(node->left);

	cout << ", " << node->B << ", ";
	printPreOrder(node->middle1);

	if (node->right != nullptr) { printPreOrder(node->right); }
}

void Tree::printPostOrder(BNode* node) {
	if (node == nullptr) { return; }
	/*if (!node->B.empty()) { node = split(node); }*/

	printPreOrder(node->left);
	cout << ", ";
	printPreOrder(node->middle1);
	cout << ", ";
	if (node->right != nullptr) { printPreOrder(node->right); }

	cout << ", " << node->A;
	cout << ", " << node->B;
}

int Tree::getKeyIndex(BNode* node, string key) {
	if (node == nullptr) { return -1; }
	/*if (!node->B.empty()) { node = split(node); }*/

	return node->A == key ? 0 : 1;
}

void Tree::remove(string key) {
	BNode* targetNode = search(root, key);
	int index = getKeyIndex(targetNode, key);
	removeKey(targetNode, index);
}

void Tree::removeKey(BNode* node, int index) {
	/*if (!node->B.empty()) { node = split(node); }*/
	if (index == 0) {
		node->A = node->B;
		node->B = "";
		node->left = node->middle1;
		node->middle1 = node->right;
		node->right = nullptr;
	}
	else if (index == 1) {
		node->B = "";
		node->middle1 = node->right;
		node->right = nullptr;
	}
}

BNode* Tree::search(BNode* node, string key) {
	/*if (!node->C.empty()) { node = split(node); }*/
	if (node != nullptr) {
		if (node->keyInNode(key)) { return node; }
		if (key < node->A) { return search(node->left, key); }
		if (key < node->B) { return search(node->middle1, key); }
		else { return search(node->right, key); }
	}
	return nullptr;
}

BNode* Tree::insert(BNode* node, string key) {
	if (node == nullptr) {
		BNode* NodeParent = node->parent;
		node = new BNode(key, nullptr, nullptr);
		node->parent = NodeParent;
		return node;
	}
	if (node->keyInNode(key)) { return nullptr; }

	if (!node->isLeaf()) {
		if (key < node->A) { return insert(node->left, key); }
		else if (node->B.empty() || key < node->B) { return insert(node->middle1, key); }
		else { return insert(node->right, key); }
	}
	else {
		if (!node->B.empty()) {
			node = split(node, key);
			return node;
		}
		insertIntoLeaf(node, key);
		return node;
	}
}

BNode* Tree::split(BNode* node, string key) {
	string small = key < node->A ? key : node->A;
	string large = key > node->B ? key : node->B;
	string medium = large == node->B ? (small == key ? node->A : key) : node->B;	/*Parenths for readability*/
	BNode* nodeParent = node->parent;
	BNode* splitLeft = new BNode(small, node->left, nullptr);
	BNode* splitRight = new BNode(large, node->middle1, node->right);
	/*if (node->B.empty()) { return nullptr; }*/

	if (nodeParent != nullptr) { insertKeyWithChildren(nodeParent, medium, splitLeft, splitRight); }
	else {
		nodeParent = new BNode(medium, splitLeft, splitRight);
		/*if (root != nullptr) {
			root->left = nullptr;
			root->middle1 = nullptr;			Must Find clever way to prevent these memory leaks.
			root->right = nullptr;
			delete root;
		}*/
		root = nodeParent;
		splitLeft->parent = root;
		splitRight->parent = root;
		return nodeParent;
	}
	return node;			/*Do I want to do this here?*/
}

void Tree::insertKeyWithChildren(BNode* parent, string key, BNode* leftChild, BNode* righChild) {
	if (!parent->B.empty()) { parent = split(parent, key); }
	if (key < parent->A) {
		parent->B = parent->A;
		parent->A = key;
		parent->right = parent->middle1;
		parent->middle1 = righChild;
		parent->left = leftChild;
	}
	else {
		parent->B = key;
		parent->right = righChild;
		parent->middle1 = leftChild;
	}
}

void Tree::insertIntoLeaf(BNode* node, string key) {
	/*if (!node->B.empty()) {
		node = split(node, key);
	}*/
	/*if (node->keyInNode(key)) { return; }*/
	if (node->A.empty() || key < node->A && node->B.empty()) {
		node->B = node->A;
		node->A = key;
	}
	else { node->B = key; }
}

//void Tree::splitLeaf(Node* node, string small, string medium, string large) {
//	Node* splitRight;
//	Node* splitLeft;
//	string pSmall;
//	string pMedium;
//	string pLarge;
//	if (node->parent == nullptr) {
//		node->A = medium;
//		node->left = new Node(small, nullptr, nullptr);
//		node->middle1 = new Node(large, nullptr, nullptr);
//	}
//	else {
//		if (!node->parent->B.empty()) {
//			splitLeft = new Node(small, nullptr, nullptr);
//			splitRight = new Node(large, nullptr, nullptr);
//			pSmall = medium < node->A ? medium : node->A;
//			pLarge = medium > node->B ? medium : node->B;
//			pMedium = large == node->B ? medium : node->B;
//
//			node->parent = nullptr;
//			delete node;
//		}
//	}
//
//}

//void Tree::splitInternal(Node* node, string small, string medium, string large) {
//	Node* splitRight;
//	Node* splitLeft;
//	string pSmall = medium < node->A ? medium : node->A;
//	string pLarge = medium > node->B ? medium : node->B;
//	string pMedium = large == node->B ? medium : node->B;
//
//	if (node->parent == nullptr) {
//		splitLeft = new Node(small, nullptr, nullptr);
//		node->parent = new Node(); /**/
//	}
//}