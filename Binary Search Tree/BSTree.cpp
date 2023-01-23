



#include "BSTree.h"


BSTree::BSTree()
{
}

BSTree::~BSTree()
{
}

void BSTree::insert(const string & val) {
	Node* cur = nullptr;
	Node* temp = getNode(val);

	if (temp != nullptr) {
		temp->incCount();
		return;
	}
	temp = nullptr;

	if (root == nullptr) {
		root = new Node(val);
	}
	else {
		cur = root;
		while (cur != nullptr) {
			if (val < cur->getData()) {
				if (cur->getLeft() == nullptr) {
					temp = new Node(val);
					cur->setLeft(temp);
					cur = nullptr;
					temp = nullptr;
				}
				else {
					cur = cur->getLeft();
				}
			}
			else {
				if (cur->getRight() == nullptr) {
					temp = new Node(val);
					cur->setRight(temp);
					cur = nullptr;
					temp = nullptr;
				}
				else {
					cur = cur->getRight();
				}
			}
		}
	}
}

Node* BSTree::getNode(const string &key) {
	Node* cur = root;

	while (cur != nullptr) {
		if (key == cur->getData()) { return cur; }
		key < cur->getData() ? cur = cur->getLeft() : cur = cur->getRight();
	}

	return nullptr;
}

bool BSTree::search(const string &key) {
	Node* cur = root;

	while (cur != nullptr) {
		if (key == cur->getData()) { return true; }
		key < cur->getData() ? cur = cur->getLeft() : cur = cur->getRight();
	}

	return false;
}

string BSTree::largest() const {
	Node* cur = root;
	string largest = "";

	if (cur == nullptr) {
		return largest;
	}

	while (cur != nullptr) {
		largest = cur->getData();
		cur = cur->getRight();
	}
	
	return largest;
}

string BSTree::smallest() const {
	Node* cur = root;
	string smallest = "";

	if (cur == nullptr) {
		return smallest;
	}

	while (cur != nullptr) {
		smallest = cur->getData();
		cur = cur->getLeft();
	}

	return smallest;
}

int BSTree::getHeight(Node* node, int count) {
	if (node == nullptr) { return count; }

	int left = getHeight(node->getLeft(), count + 1);
	int right = getHeight(node->getRight(), count + 1);
	return (left < right ? right : left);
}

int BSTree::height(const string &key) {
	Node* cur = getNode(key);

	if (cur == nullptr) { return -1; }
	return getHeight(cur, 0);
}

void BSTree::remove(const string &key) {
	Node* par = nullptr;
	Node* cur = root;
	Node* nullNode = nullptr;

	while (cur != nullptr) {// Search for node
		if (cur->getData() == key) {// Node found 
			if (!cur->getLeft() && !cur->getRight()) {         // Remove leaf
				if (!par) { // Node is root
					delete root;
					root = nullptr;
				}
				else if (par->getLeft() == cur) { par->getLeft()->~Node(); }
				else { par->getRight()->~Node(); }
			}
			else if (cur->getLeft() && !cur->getRight()) {    // Remove node with only left child
				if (!par) { // Node is root
					root->setData(root->getLeft()->getData());				//TODO: Fix the remaining code and perform necessary deletes.
					root->getLeft()->~Node();
				}
				else if (par->getLeft() == cur) {
					par->setLeft(cur->getLeft());
					cur->~Node();
				}
				else {
					par->setRight(cur->getLeft());
					cur->~Node();
				}
			}
			else if (!cur->getLeft() && cur->getRight()) {     // Remove node with only right child
				if (!par) { // Node is root
					root->setData(root->getRight()->getData());
					root->getRight()->~Node();
				}
				else if (par->getLeft() == cur) {
					par->setLeft(cur->getRight());
					cur->~Node();
				}
				else
					par->right = cur->right
			}
			else                                   // Remove node with two children
			   // Find successor (leftmost child of right subtree)
				suc = cur->right
				while (suc->left is not null)
					suc = suc->left
					cur = Copy suc                       // Copy successor to current node
					BSTRemove(cur->right, suc->key)     // Remove successor from right subtree
					return // Node found and removed
	}
			else if (cur->key < key) // Search right
				par = cur
				cur = cur->right
			else                     // Search left
				par = cur
				cur = cur->left
				return // Node not found
}
}