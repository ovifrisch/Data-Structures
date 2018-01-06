#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap {
	int* array;
	int currentSize;
	int capacity;
};

void percolateDown(struct BinaryHeap* heap, int hole) {
	int child;
	int temp = heap->array[hole];

	for (; hole * 2 <= heap->currentSize; hole = child) {
		child = hole * 2;
		if (child != heap->currentSize && heap->array[child + 1] < heap->array[child]) {
			++child;
		}
		if (heap->array[child] < temp) {
			heap->array[hole] = heap->array[child];
		}
		else {
			break;
		}
	}
	heap->array[hole] = temp;
}

void percolateUp(struct BinaryHeap* heap, int hole) {
	int temp = heap->array[hole];

	for (; hole > 1 && temp < heap->array[hole / 2]; hole /= 2) {
		heap->array[hole] = heap->array[hole / 2];
	}
	heap->array[hole] = temp;
}

void buildHeap(struct BinaryHeap* heap) {
	for (int i = heap->currentSize / 2; i > 0; i--) {
		percolateDown(heap, i);
	}
}

void initializeHeap(struct BinaryHeap* heap, int* arr, int size) {
	heap->array = (int*)malloc(size * 2 * sizeof(int));
	for (int i = 0; i < size; i++) {
		heap->array[i + 1] = arr[i];
	}
	heap->currentSize = size;
	heap->capacity = size * 2;
	buildHeap(heap);
}

void initializeEmptyHeap(struct BinaryHeap* heap) {
	heap->array = malloc(10 * sizeof(int));
	heap->currentSize = 0;
	heap->capacity = 10;
}

void insert(struct BinaryHeap* heap, int value) {
	if (heap->currentSize + 1 >= heap->capacity) {
		heap->array = (int*)realloc(heap->array, heap->capacity * 2);
		heap->capacity *= 2;
	}
	heap->array[heap->currentSize + 1] = value;
	heap->currentSize++;
	percolateUp(heap, heap->currentSize);
}

void removeMin(struct BinaryHeap* heap) {
	if (heap->currentSize == 0) {
		printf("Sorry, but the heap is empty");
		return;
	}
	else if (heap->currentSize == 1) {
		heap->currentSize--;
	}
	else {
		heap->array[1] = heap->array[heap->currentSize];
		heap->currentSize--;
		percolateDown(heap, 1);
	}
}

int getMin(struct BinaryHeap* heap) {
	return heap->array[1];
}

void print(struct BinaryHeap* heap) {
	for (int i = 1; i <= heap->currentSize; i++) {
		printf("%d ", heap->array[i]);
	}
	printf("\n");
}

int main() {
	int initials[13] = {4, 3, 2, 3, 7, 89, 23, 14, 56, 23, 2, 1, 1};
	struct BinaryHeap* heap = malloc(sizeof(struct BinaryHeap));
	initializeHeap(heap, initials, 13);
}



/*
you need to store your struct on the heap in order
to malloc its array fields.
*/