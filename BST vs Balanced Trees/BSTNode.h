




#ifndef SNODE_H
#define SNODE_H

#include <string>
using namespace std;

class SNode
{
public:
	SNode();
	SNode(string data);
	~SNode();
	SNode* getLeft() const { return left; }
	SNode* getRight() const { return right; }
	void setLeft(SNode* ptr) { left = ptr; }
	void setRight(SNode* ptr) { right = ptr; }
	string getData() { return data; }
	void setData(string data) { this->data = data; }
	void incCount() { count++; }
	void countZero() { count = 0; }
	int getCount() { return count; }
private:
	SNode* left = nullptr;
	SNode* right = nullptr;
	string data;
	int count = 0;
};
#endif // !NODE_H
