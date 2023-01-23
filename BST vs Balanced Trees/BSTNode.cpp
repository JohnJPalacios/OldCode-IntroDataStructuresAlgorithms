



#include "BSTNode.h"


SNode::SNode(string data) {
	this->data = data;
	count++;
}

SNode::~SNode() {
	if (left != nullptr) { delete left; }
	if (right != nullptr) { delete right; }
}