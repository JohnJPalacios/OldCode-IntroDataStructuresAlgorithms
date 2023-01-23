

#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(string key) : data(key) {}
	~Node();
	string data = "";
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int color;							//color == 1 => red, 0 => black
private:
};

Node::Node()
{
}

Node::~Node()
{
}
#endif // !NODE_H
