#include "BinaryHeap.h"
#include <iostream>
using namespace std;

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap() {
	theArray.push_back(0);
}

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(Comparable* arr, int numElements) {
	theArray.push_back(0);
	for (int i = 0; i < numElements; i++) {
		theArray.push_back(arr[i]);
	}
	buildHeap();
}

template <class Comparable>
void BinaryHeap<Comparable>::insert(Comparable value) {
	theArray.push_back(value);
	percolateUp(theArray.size() - 1);
}

template <class Comparable>
void BinaryHeap<Comparable>::removeMin() {
	if (theArray.size() == 1) {
		cout << "Sorry, but the heap is empty" << endl;
		return;
	}
	else if (theArray.size() == 2) {
		theArray.erase(theArray.begin() + 1);
	}
	else {
		theArray[1] = theArray[theArray.size() - 1];
		theArray.erase(theArray.begin() + theArray.size() - 1);
		percolateDown(1);
	}
}

template <class Comparable>
Comparable BinaryHeap<Comparable>::getMin() {
	return theArray[1];
}

template <class Comparable>
void BinaryHeap<Comparable>::print() {
	for (int i = 1; i < theArray.size(); i++) {
		cout << theArray[i] << " ";
	}
	cout << endl;
}

template <class Comparable>
void BinaryHeap<Comparable>::buildHeap() {
	for (int i = (theArray.size() - 1) / 2; i > 0; i--) {
		percolateDown(i);
	}
}

template <class Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole) {
	int child;
	Comparable temp = theArray[hole];

	for (; hole * 2 <= theArray.size() - 1; hole = child) {
		child = hole * 2;
		if (child != theArray.size() - 1 && theArray[child + 1] < theArray[child]) {
			++child;
		}
		if (theArray[child] < temp) {
			theArray[hole] = theArray[child];
		}
		else {
			break;
		}
	}
	theArray[hole] = temp;
}

template <class Comparable>
void BinaryHeap<Comparable>::percolateUp(int hole) {
	Comparable temp = theArray[hole];

	for (; hole > 1 && temp < theArray[hole / 2]; hole /= 2) {
		theArray[hole] = theArray[hole / 2];
	}
	theArray[hole] = temp;
}


int main() {
	int initials[4] = {32, 20, 11, 3};
	BinaryHeap<int>* myHeap = new BinaryHeap<int>(initials, 4);
}









