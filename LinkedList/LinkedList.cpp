#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
	sizeVar = 0;
	head = NULL;
}

template <class T>
void LinkedList<T>::add(T element, int pos) {
	if (pos < 0 || pos > sizeVar) {
		return;
	}
	else {
		if (pos == 0) {
			Node<T>* rest = head;
			head = new Node<T>(element, rest);
		}
		else {
			Node<T>* current = head;
			while (pos > 1) {
				current = current->next;
				pos--;
			}
			if (pos == sizeVar) {
				current->next = new Node<T>(element, NULL);
			}
			else {
				Node<T>* rest = current->next;
				current->next = new Node<T>(element, rest);
			}
		}
		sizeVar++;
	}
}

template <class T>
void LinkedList<T>::remove(int pos) {
	if (pos < 0 || pos > sizeVar - 1) {
		return;
	}
	else {
		if (pos == 0) {
			head = head->next;
		}
		else {
			Node<T>* current = head;
			while (pos > 1) {
				current = current->next;
				pos--;
			}
			if (pos == sizeVar - 1) {
				current->next = NULL;
			}
			else {
				Node<T>* newNext = current->next->next;
				current->next = newNext;
			}
		}
		sizeVar--;
	}
}

template <class T>
T LinkedList<T>::get(int pos) {
	if (pos < 0 || pos > sizeVar - 1) {
		return 0;
	}
	Node<T>* current = head;
	while (pos > 0) {
		current = current->next;
		pos--;
	}
	return current->element;
}

template <class T>
void LinkedList<T>::set(int pos, T value) {
	if (pos < 0 || pos > sizeVar - 1) {
		return;
	}
	Node<T>* current = head;
	while (pos > 0) {
		current = current->next;
		pos--;
	}
	current->element = value;
}

template <class T>
int LinkedList<T>::size() {
	return sizeVar;
}

int main() {
	
}
