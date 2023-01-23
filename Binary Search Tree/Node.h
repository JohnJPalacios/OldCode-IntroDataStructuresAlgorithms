




#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(string data);
	~Node();
	Node* getLeft() const { return left; }
	Node* getRight() const { return right; }
	void setLeft(Node* ptr) { left = ptr; }
	void setRight(Node* ptr) { right = ptr; }
	string getData() { return data; }
	void setData(string data) { this->data = data; }
	void incCount() { count++; }
	void countZero() { count = 0; }
	int getCount() { return count; }
private:
	Node* left = nullptr;
	Node* right = nullptr;
	string data;
	int count = 0;
};

Node::Node() {

}

Node::~Node() {
	if (left != nullptr) { delete left; }
	if (right != nullptr) { delete right; }
}
#endif // !NODE_H
