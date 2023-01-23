/***********************************************************************************/
/* File: Tree.cpp. Implementation file for Tree.h. Author: John Palacios with help */
/* from: Ethan White                                                               */
/***********************************************************************************/

#include "Tree.h"

Tree::Tree() {
	root = new Node;
}

Tree::~Tree() {
	DeleteNode(root);
}

void Tree::DeleteNode(Node* node) {
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

void Tree::printInOrder(Node* node) {
	if (node == nullptr) { return; }
	/*if (!node->B.empty()) { node = split(node); }*/

	printInOrder(node->left);
	cout << ", " << node->A << ", ";
	printInOrder(node->middle1);
	cout << ", " << node->B << ", ";

	if (node->right != nullptr) { printInOrder(node->right); }
}

void Tree::printPreOrder(Node* node) {
	if (node == nullptr) { return; }
	/*if (!node->B.empty()) { node = split(node); }*/

	cout << node->A << ", ";
	printPreOrder(node->left);

	cout << ", " << node->B << ", ";
	printPreOrder(node->middle1);

	if (node->right != nullptr) { printPreOrder(node->right); }
}

void Tree::printPostOrder(Node* node) {
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

Node* Tree::getLeftSib(Node* node) {
	if (node->parent == nullptr) { return nullptr; }
	return node == node->parent->right ? node->parent->middle1 : node->parent->left;
}

Node* Tree::getRightSib(Node* node) {
	if (node->parent == nullptr) { return nullptr; }
	return node == node->parent->left ? node->parent->middle1 : node->parent->right;
}

string Tree::getParentKeyLeftOfChild(Node* parent, Node* child) {
	if (parent == nullptr) { return ""; }
	return child == parent->right ? parent->B : parent->A;
}

string Tree::getPArentKeyRightOfChild(Node* parent, Node* child) {
	if (parent == nullptr) { return ""; }
	return child == parent->left ? parent->A : parent->B;
}

void Tree::addKeyAndChild(Node* sib, string key, Node* child) {
	if (!sib->B.empty()) { 
		/*Node* parent = split(sib, key);
		if (getKeyIndex(parent, key)) {

		}*/
	}
	else {
		if (key < sib->A || sib->A.empty()) {
			sib->B = sib->A;
			sib->A = key;
			sib->right = sib->middle1;
			sib->middle1 = sib->left;
			sib->left = child;
		}
		else {
			sib->B = key;
			sib->right = child;
		}
	}
}

void Tree::setParentKeyLeftOfChild(Node* parent, Node* child, string key) {
	child == parent->right ? parent->B = key : parent->A = key;
}

void Tree::setParentKeyRightOfChild(Node* parent, Node* child, string key) {
	child == parent->left ? parent->A = key : parent->B = key;
}

void Tree::rotateLeft(Node* node) {
	Node* leftSib = getLeftSib(node);
	string keyForLeftSib = getParentKeyLeftOfChild(node->parent, node);				
	addKeyAndChild(leftSib, keyForLeftSib, node->left);							/* <-Picking up right here */
	setParentKeyLeftOfChild(node->parent, node, node->A);
	removeKey(node, 0);
}

void Tree::rotateRight(Node* node) {
	Node* rightSib = getRightSib(node);
	string keyForRightSib = getPArentKeyRightOfChild(node->parent, node);
	addKeyAndChild(rightSib, keyForRightSib, node->right);
	setParentKeyRightOfChild(node->parent, node, node->B);
	removeKey(node, 1);
}

Node* Tree::findSuccessor(Node* node, string key) {
	Node* temp = node->A == key ? node->middle1 : node->right;
	if (temp == nullptr) { return nullptr; }
	while (temp->left != nullptr) { temp = temp->left; }
	return temp;
}


int Tree::getKeyIndex(Node* node, string key) {
	if (node == nullptr) { return -1; }
	/*if (!node->B.empty()) { node = split(node); }*/

	return node->A == key ? 0 : 1;
}

string Tree::getMinKey(Node* node) {
	Node* temp = node;
	while (temp->left != nullptr) { temp = temp->left; }
	return temp->A;
}

Node* Tree::getRigtmostChild(Node* node) {
	if (node->right != nullptr) { return node->right; }
	else if (node->middle1 != nullptr) { return node->middle1; }
	else { return node->left; }
}

Node* Tree::nextNode(Node* node, string key) {
	if (key < node->A) { return node->left; }
	else if (node->B.empty || key < node->B) { return node->middle1; }
	else { return node->right; }
}

bool Tree::keySwap(Node* node, string existing, string replacement) {
	if (node == nullptr) { return false; }
	int keyIndex = getKeyIndex(node, existing);
	if (keyIndex == -1) {
		Node* next = nextNode(node, existing);
		return keySwap(next, existing, replacement);
	}

	if (keyIndex == 0) { node->A = replacement; }
	else { node->B = replacement; }
	return true;
}

void Tree::merge(Node* node) {
	Node* leftSib = getLeftSib(node);
	Node* rightSib = getRightSib(node);

	if (leftSib != nullptr && !leftSib->B.empty()) { rotateRight(leftSib); }
	else if (rightSib != nullptr && !rightSib->B.empty()) { rotateLeft(rightSib); }
	else {
		if (leftSib == nullptr) { fuse(node, rightSib); }
		else { fuse(leftSib, node); }
	}
}

void Tree::remove(string key) {
	Node* targetNode = search(root, key);
	if (targetNode->left == nullptr) {
		int index = getKeyIndex(targetNode, key);
		removeKey(targetNode, index);
	}
	else {
		Node* succsessor = findSuccessor(targetNode, key);
		string succsessorKey = succsessor->A;

		keySwap(succsessor, succsessorKey, key);
		keySwap(targetNode, key, succsessorKey);
		removeKey(succsessor, 0);
		if (succsessor->A.empty()) {
			Node* leftSib = getLeftSib(succsessor);
			Node* rightSib = getRightSib(succsessor);
			if (leftSib->B.empty()) {
				leftSib->B = targetNode->A;
				targetNode->A = targetNode->B;
				targetNode->B = "";
				delete targetNode->middle1;
				targetNode->middle1 = targetNode->right;
			}
			else {
				//Rotate right. Function already written.
			}
		}
	}
}

void Tree::removeKey(Node* node, int index) {
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

Node* Tree::search(Node* node, string key) {
	/*if (!node->C.empty()) { node = split(node); }*/
	if (node != nullptr) {
		if (node->keyInNode(key)) { return node; }
		if (key < node->A) { return search(node->left, key); }
		if (key < node->B) { return search(node->middle1, key); }
		else { return search(node->right, key); }
	}
	return nullptr;
}

Node* Tree::insert(Node* node, string key) {
	/*if (node == nullptr) {
		node = new Node(key, nullptr, nullptr);
		Node* NodeParent = node->parent;
		node->parent = NodeParent;
		return node;
	}*/
	if (node->keyInNode(key)) { return nullptr; }
	if (!node->isLeaf()) {
		if (key < node->A) { return insert(node->left, key); }
		else if (node->B.empty() || key < node->B) { return insert(node->middle1, key); }
		else { return insert(node->right, key); }
	}
	else {
		/*if (!node->B.empty()) { 
		node = split(node, key);
		return node;
		}*/
		insertIntoLeaf(node, key);
		return node;
	}
}

Node* Tree::split(Node* node, string key) {
	string small = key < node->A ? key : node->A;
	string large = key > node->B ? key : node->B;
	string medium = large == node->B ? (small == key ? node->A : key) : node->B;	/*Parenths for readability*/
	Node* nodeParent = node->parent;
	Node* splitLeft = new Node(small, node->left, nullptr);
	Node* splitRight = new Node(large, node->middle1, node->right);
	/*if (node->B.empty()) { return nullptr; }*/

	if (nodeParent != nullptr) { insertKeyWithChildren(nodeParent, medium, splitLeft, splitRight); }
	else {
		nodeParent = new Node(medium, splitLeft, splitRight);
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
	return nodeParent;
}

void Tree::insertKeyWithChildren(Node* parent, string key, Node* leftChild, Node* righChild) {
	if (!parent->B.empty()) { /*parent =*/ 
		split(parent, key);
		return;
	}
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

void Tree::insertIntoLeaf(Node* node, string key) {
	if (!node->B.empty()) {
		/*node =*/ split(node, key);
		return;
	}
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