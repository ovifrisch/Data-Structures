package main
import "fmt"

type BinaryHeap struct {
	list []int

}

func (heap *BinaryHeap) buildHeap() {
	for i := (len(heap.list) - 1) / 2; i > 0; i-- {
		heap.percolateDown(i)
	}
}

func (heap *BinaryHeap) percolateUp(hole int) {
	temp := heap.list[hole]

	for ; hole > 1 && temp < heap.list[hole / 2] ; hole /= 2 {
		heap.list[hole] = heap.list[hole / 2]
	}
	heap.list[hole] = temp
}

func (heap *BinaryHeap) percolateDown(hole int) {
	var child int
	temp := heap.list[hole]

	for ; hole * 2 <= len(heap.list) - 1; hole = child {
		child = hole * 2
		if (child != len(heap.list) - 1 && heap.list[child + 1] < heap.list[child]) {
			child++
		}

		if (heap.list[child] < temp) {
			heap.list[hole] = heap.list[child]
		} else {
			break
		}
	}
	heap.list[hole] = temp
}

func (heap *BinaryHeap) initializeEmptyHeap() {
	heap.list = make([]int, 1)
}

func (heap *BinaryHeap) initializeHeap(arr []int) {
	heap.list = make([]int, len(arr) + 1)
	for i := 0; i < len(arr); i++ {
		heap.list[i + 1] = arr[i]
	}
	heap.buildHeap()
}

func (heap *BinaryHeap) insert(value int) {
	if (cap(heap.list) > len(heap.list)) {
		heap.list = heap.list[0: len(heap.list) + 1]
		heap.list[len(heap.list) - 1] = value;
	} else {
		heap.list = append(heap.list, value)
	}
	heap.percolateUp(len(heap.list) - 1)
}

func (heap *BinaryHeap) removeMin() {
	if (len(heap.list) == 1) {
		fmt.Println("Sorry, but the heap is empty")

	} else if (len(heap.list) == 2) {
		heap.list = make([]int, 1)
	} else {
		heap.list[1] = heap.list[len(heap.list) - 1]
		heap.list = heap.list[0:len(heap.list) - 1]
		heap.percolateDown(1)
	}
}

func (heap *BinaryHeap) getMin() int {
	return heap.list[1]
}

func (heap *BinaryHeap) print() {
	for i := 1; i < len(heap.list); i++ {
		fmt.Print(heap.list[i], " ")
	}
	fmt.Println()
}

func main() {
	myHeap := BinaryHeap{}
	myHeap.initializeHeap([]int{7, 6, 5, 4})
}

/*
The capacity of a slice is the number of elements in 
the underlying array, counting from the first element in the slice.
*/
