

#include "AVLTree.h"
#include <fstream>
#include <iostream>
using namespace std;


AVLTree::AVLTree()
{
}

AVLTree::~AVLTree() {
	deleteNode(root);
}

void AVLTree::visualizeTree(const string &outputFilename) {
	ofstream outFS(outputFilename.c_str());
	if (!outFS.is_open()) {
		cout << "Error" << endl;
		return;
	}
	outFS << "digraph G {" << endl;
	visualizeTree(outFS, root);
	outFS << "}";
	outFS.close();
	string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
	string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
	system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n) {
	if (n) {
		if (n->left) {
			visualizeTree(outFS, n->left);
			outFS << n->key << " -> " << n->left->key << ";" << endl;
		}

		if (n->right) {
			visualizeTree(outFS, n->right);
			outFS << n->key << " -> " << n->right->key << ";" << endl;
		}
	}
}

Node* AVLTree::search(Node* node, const string &key) {
	if (node == nullptr) { return node; }

	if (key == node->key) { return node; }

	return key < node->key ? search(node->left, key) : search(node->right, key);
}

bool AVLTree::setChild(Node* parent, string withChild, Node* child) {
	if (withChild != "left" && withChild != "right") { return false; }

	if (withChild == "left") { parent->left = child; }
	else { parent->right = child; }
	if (child != nullptr) { child->parent = parent; }

	updateHeight(parent);
	return true;
}

bool AVLTree::replaceChild(Node* parent, Node* currentChild, Node* newChild) {
	if (parent->left == currentChild) { return setChild(parent, "left", newChild); }
	else if (parent->right == currentChild) { return setChild(parent, "right", newChild); }
	return false;
}

int AVLTree::getBalance(Node* node) {
	int leftHeight = -1;
	int rightHeight = -1;
	if (node == nullptr) { return -1; }
	if (node->left != nullptr) { leftHeight = node->left->height; }
	if (node->right != nullptr) { rightHeight = node->right->height; }

	node->balFac = leftHeight - rightHeight;
	return node->balFac;
}

void AVLTree::updateHeight(Node* node) {
	int leftHeight = -1;
	int rightHeight = -1;
	if (node->left != nullptr) { leftHeight = node->left->height; }
	if (node->right != nullptr) { rightHeight = node->right->height; }

	node->height = leftHeight < rightHeight ? rightHeight : leftHeight;
	node->height += 1;
}

Node* AVLTree::rotateRight(Node* node) {
	if (node->left == nullptr) { return nullptr; }
	Node* leftRigthChild = node->left->right;

	if (node->parent != nullptr) { replaceChild(node->parent, node, node->left); }
	else {
		root = node->left;
		root->parent = nullptr;
	}

	setChild(node->left, "right", node);
	setChild(node, "left", leftRigthChild);
	return node;
}

Node* AVLTree::rotateLeft(Node* node) {
	if (node->right == nullptr) { return nullptr; }
	Node* rightLeftChild = node->right->left;

	if (node->parent != nullptr) { replaceChild(node->parent, node, node->right); }
	else {
		root = node->right;
		root->parent = nullptr;
	}

	setChild(node->right, "left", node);
	setChild(node, "right", rightLeftChild);
	return node;
}

Node* AVLTree::rebalance(Node* node) {
	updateHeight(node);
	if (getBalance(node) == -2) {
		if (getBalance(node->right) == 1) { rotateRight(node->right); }
		return rotateLeft(node);
	}
	else if (getBalance(node) == 2) {
		if (getBalance(node->left) == -1) { rotateLeft(node->left); }
		return rotateRight(node);
	}

	return node;
}

Node* AVLTree::findUnbalancedNode(Node* node) {
	if (node == nullptr) { return nullptr; }

	if (node->balFac > 1 || node->balFac < -1) { return node; }
	else { return findUnbalancedNode(node->parent); }
}

void AVLTree::printBalanceFactors(Node* node) {
	if (node == nullptr) { return; }

	printBalanceFactors(node->left);
	node->balFac = getBalance(node);
	cout << node->key << "(" << node->balFac << "), ";
	printBalanceFactors(node->right);
}

void AVLTree::insertNode(Node* node) {
	Node* cur = nullptr;
	if (root == nullptr) {
		root = node;
		node->parent = nullptr;
		return;
	}

	cur = root;
	while (cur != nullptr) {
		if (node->key < cur->key) {
			if (cur->left == nullptr) {
				cur->left = node;
				node->parent = cur;
				cur = nullptr;
			}
			else { cur = cur->left; }
		}
		else {
			if (cur->right == nullptr) {
				cur->right = node;
				node->parent = cur;
				cur = nullptr;
			}
			else { cur = cur->right; }
		}
	}

	cur = node->parent;
	while (cur != nullptr) {
		rebalance(cur);
		cur = cur->parent;
	}
}

bool AVLTree::removeNode(Node* node) {
	Node* succNode = nullptr;
	Node* parent = node->parent;
	Node* temp = nullptr;

	if (node == nullptr) { return false; }

	if (node->left != nullptr && node->right != nullptr) {
		succNode = node->right;
		while (succNode->left != nullptr) { succNode = succNode->left; }
		node->key = succNode->key;
		removeNode(succNode);

		return true;
	}

	else if (node == root) {
		if (node->left != nullptr) { root = node->left; }
		else { root = node->right; }
		if (root) { root->parent = nullptr; }


		return true;
	}

	else if (node->left != nullptr) { replaceChild(parent, node, node->right); }

	else { replaceChild(parent, node, node->right); }

	temp = parent;
	while (temp != nullptr) {
		rebalance(temp);
		temp = temp->parent;
	}

	return true;
}

void AVLTree::insert(const string &key) {
	Node* temp = nullptr;
	if (search(key) == nullptr) {
		temp = new Node(key);
		insertNode(temp);
	}
}

void AVLTree::deleteNode(Node* node) {
	if (node == nullptr) { return; }

	deleteNode(node->left);
	deleteNode(node->right);
	node->parent = nullptr;
	node->left = nullptr;
	node->right = nullptr;
	delete node;
}