#ifndef LinkedList_H
#define LinkedList_H


template <class T>
class Node {
public:
	Node(T elem, Node* nxt) : element(elem), next(nxt) {}
	Node() : element(T()), next(0) {} //default ctor
	T element;
	Node* next;
};

template <class T>
class LinkedList {
public:
	LinkedList();
	void add(T element, int pos = 0);
	void remove(int pos = 0);
	T get(int pos);
	void set(int pos, T value);
	int size();
private:
	int sizeVar;
	Node<T>* head;
};


#endif