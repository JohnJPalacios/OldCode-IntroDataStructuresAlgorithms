

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <vector>
using namespace std;

template<typename T>
class MaxHeap
{
private:
	vector<T> heapArray;
public:
	MaxHeap();
	~MaxHeap();

private:
	void percolateUp(int);
	void swap(int, int);
	void percolateDown(int);
	void percolateDown(int, int);
	void heapSort();
};

template<typename T>
MaxHeap<T>::MaxHeap()
{
}

template<typename T>
MaxHeap<T>::~MaxHeap()
{
}
#endif // !MAXHEAP_H
