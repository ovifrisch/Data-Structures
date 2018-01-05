#ifndef BinaryHeap_H
#define BinaryHeap_H

#include <vector>

template <class Comparable>
class BinaryHeap {
public:
	BinaryHeap();
	BinaryHeap(Comparable* arr, int numElements);
	void insert(Comparable value);
	void removeMin();
	Comparable getMin();
	void print();
private:
	void buildHeap();
	void percolateUp(int hole);
	void percolateDown(int hole);
	std::vector<int> theArray;
};

#endif