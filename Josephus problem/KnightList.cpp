/************************************************************************/
/* File: KnightList.cpp. This is the implementation file for			*/
/* the KnightList class. Author: John Palacios with recycled old code	*/
/************************************************************************/

#include "KnightList.h"

KnightList::KnightList(const KnightList &cpy) {
	KnightNode *temp = nullptr;								//Holds address of next node
	if (head != nullptr) {									//Need to delete current nodes, then while currNode != nullptr,
															//push cpy's node's value onto the list.
		while (head != nullptr) {							//Loop through list deleting items until end is reached
			temp = head->next;
			delete head;
			head = temp;
		}
	}

	temp = cpy.head;
	while (temp != nullptr) {								//Push each of cpy's values onto the list
		this->push_back(temp->name, temp->pos);
		temp = temp->next;
	}
}

void KnightList::print_list() const {
	KnightNode *temp = nullptr;								//Points to current element in linked list
	int count = get_cardinality();

	temp = head;											//Point current pointer to start of list
	while (count > 0) {										//print contents of non-null nodes 
		cout << temp->name;									//followed by space if not at end
		temp = temp->next;
		count--;
		if (count != 0) { cout << " "; }
	}
}

ostream & operator<<(ostream &out, const KnightList &rhs) {
	KnightList copy(rhs);										//Duplicate of rhs

	while (copy.not_empty()) {									//insert rhs values into out stream
		out << copy.front();
		copy.pop_front();
		if (copy.not_empty()) { out << " "; }					//Add space only if mirr is not empty
	}
	return out;
}

void KnightList::push_front(string name, int position) {
	KnightNode *temp = nullptr;								//Node to be pushed into the front of the linked list
	temp = new KnightNode(name, position);					//Alocate memory for IntNode to be pushed onto front of linked list

															//Push temp into front of linked list
	temp->next = head;
	head = temp;

	//Handle case when list was empty
	if (tail == nullptr) { tail = temp; }
	cardinality++;
}

void KnightList::push_back(string name, int position) {
	KnightNode *temp = nullptr;								//Node to be pushed into the front of the linked list
	temp = new KnightNode(name, position);					//Alocate memory for IntNode to be pushed onto front of linked list

	if (head != nullptr) {									//Push temp into tail end of linked list
		tail->next = temp;
		tail = temp;
		temp->next = head;
	}

	//Handle case when list was empty
	else {
		head = temp;
		tail = temp;
	}
	cardinality++;
}

void KnightList::pop_front() {
	KnightNode *temp = nullptr;								//Will point to head

	if (head != nullptr) {									//Only operate on populated list
		temp = head;										//Remember where this alocated memory is located
		head = head->next;									//Point head to the element after first

		delete temp;										//Return alocated memory to free store
		temp = nullptr;										//Ground pointe
	}
	cardinality--;
}

void KnightList::remove_next(KnightNode* node) {			// Assuming node is in the list
	KnightNode* target = node->next;

	if (target == head) { head = head->next; }				// For use with circularly linked list derived class
	else if (target == tail) { tail = node; }

	node->next = target->next;
	/*cout << target->name << " removed";*/
	target->next = nullptr;
	delete target;
	target = nullptr;
	cardinality--;
}

KnightList::~KnightList() {									// I Am The Omega
	KnightNode* temp = nullptr;								//Holds address of next node

	while (head != nullptr) {								//Loop through list deleting items until end is reached
		temp = head->next;
		delete head;
		head = temp;
	}

	tail = nullptr;											//Ground tail
}