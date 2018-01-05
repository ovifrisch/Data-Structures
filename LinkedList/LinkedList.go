package main

import "fmt"

type Node struct {
	element int
	next *Node
}

type LinkedList struct {
	sizeVar int
	head *Node
}

func (list *LinkedList) Add(value int, pos int) {
	if (pos < 0 || pos > list.sizeVar) {
		return
	} else {
		if (pos == 0) {
			rest := list.head
			list.head = &Node{value, rest}
		} else {
			current := list.head
			for ; pos > 1 ; {
				current = current.next
				pos--
			}
			if (pos == list.sizeVar) {
				current.next = &Node{value, nil}
			} else {
				rest := current.next
				current.next = &Node{value, rest}
			}
		}
		list.sizeVar++
	}
}

func (list *LinkedList) Remove(pos int) {
	if (pos < 0 || pos > list.sizeVar - 1) {
		return
	} else {
		if (pos == 0) {
			list.head = list.head.next
		} else {
			current := list.head
			for ; pos > 1 ; {
				current = current.next
				pos--
			}
			if (pos == list.sizeVar - 1) {
				current.next = nil
			} else {
				newNext := current.next.next
				current.next = newNext
			}
		}
		list.sizeVar--
	}
}

func (list *LinkedList) Get(pos int) int {
	if (pos < 0 || pos >= list.sizeVar) {
		return 0
	}

	current := list.head
	for ; pos > 0 ; {
		current = current.next
		pos--
	}
	return current.element
}

func (list *LinkedList) Set(pos int, value int) {
	if (pos < 0 || pos >= list.sizeVar) {
		return
	}
	current := list.head
	for ; pos > 0 ; {
		current = current.next
		pos--
	}
	current.element = value
}

func (list *LinkedList) Size() int {
	return list.sizeVar
}

func main () {
	myList := LinkedList{0, nil}
	myList.Add(1, 0)
	fmt.Println(myList.Get(0))
}