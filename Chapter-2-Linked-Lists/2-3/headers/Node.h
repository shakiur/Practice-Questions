#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node{
	T data;
	Node<T>* next;

	public:
		// Constructors;
		Node();
		Node(T);
		Node(T, Node<T>*);

		// Getters
		T getData();
		Node<T>* getNext();

		// Setters
		void setData(T);
		void setNext(Node<T>*);
};

// Constructors
template<class T> 
Node<T>::Node() : next(NULL) {}

template<class T> 
Node<T>::Node(T d) : data(d), next(NULL) {}

template<class T> 
Node<T>::Node(T d, Node<T>* n) : data(d), next(n) {}

// Getters
template<class T> 
T Node<T>::getData() { return data; }

template<class T> 
Node<T>* Node<T>::getNext() { return next; }

// Setters
template<class T> 
void Node<T>::setData(T d) { data = d; }

template<class T> void
 Node<T>::setNext(Node<T>* n) { next = n; }

#endif