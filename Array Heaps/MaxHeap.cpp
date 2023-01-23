

#include "MaxHeap.h"

template<typename T>
void MaxHeap<T>::swap(int in1, int in2) {
	T temp;
	temp = heapArray[in1];
	heapArray[in1] = heapArray[in2];
	heapArray[in2] = temp;
}

template<typename T>
void MaxHeap<T>::percolateUp(int index) {
	int parentIndex;
	while (index > 0) {
		parentIndex = (index - 1) / 2;
		if (heapArray[index] <= heapArray[parentIndex]) {
			return;
		}
		else {
			swap(index, parentIndex);
			index = parentIndex;
		}
	}
}

template<typename T>
void MaxHeap<T>::percolateDown(int index) {
	int childIndex = 2 * index + 1;
	T value = heapArray[index];
	T maxValue;
	int maxIndex;

	while (childIndex < heapArray.size()) {
		maxValue = value;
		maxIndex = -1;
		for (int i = 0; i < 2 && i+ childIndex < heapArray.size(); i++) {
			if (heapArray[i + childIndex] > maxValue) {
				maxValue = heapArray[i + childIndex];
				maxIndex = 1 + childIndex;
			}
		}

		if (maxValue == value) { return; }
		else {
			swap(index, maxIndex);
			index = maxIndex;
			childIndex = 2 * index + 1;
		}
	}
}

template<typename T>
void MaxHeap<T>::percolateDown(int index, int size) {
	int childIndex = 2 * index + 1;
	T value = heapArray[index];
	T maxValue;
	int maxIndex

	while (childIndex < size) {
		maxValue = value;
		maxIndex = -1;
		for (int i = 0; i < 2 && i + childIndex < size; i++) {
			if (heapArray[i + childIndex] > maxValue) {
				maxValue = heapArray[i + childIndex];
				maxIndex = 1 + childIndex;
			}
		}

		if (maxValue == value) { return; }
		else {
			swap(index, maxIndex);
			index = maxIndex;
			childIndex = 2 * index + 1;
		}
	}
}

template<typename T>
void MaxHeap<T>::heapSort() {
	int size = heapArray.size();
	for (int i = size / 2 - 1; i >= 0; i--) {
		percolateDown(i);
	}

	for (int i = size - 1; i > 0; i--) {
		swap(0, i);
		percolateDown(0, i);
	}
}