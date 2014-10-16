/*
Implement an algorithm to delete a node in the middle of a single linked list, given 
only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include <iostream>
#include "headers/Node.h"

using namespace std;

template<class T>
void display(Node<T>*);

template<class T>
void removeNode(Node<T>*&);

int main(){
	Node<char>* e = new Node<char>('e');
	Node<char>* d = new Node<char>('d', e);
	Node<char>* c = new Node<char>('c', d);
	Node<char>* b = new Node<char>('b', c);
	Node<char>* a = new Node<char>('a', b);

	display(a);

	removeNode(c);

	display(a);
}

template<class T>
void display(Node<T>* head){
	while(head){
		cout << head->getData() << "->";
		head = head->getNext();
	}
	cout << "NULL" << endl;
}

template<class T>
void removeNode(Node<T>*& curr){

	Node<T>* next = curr->getNext();

	// Last element cannot be removed
	if(next){
		// Swap data
		curr->setData(next->getData());
	
		// Remove next data from linked list
		curr->setNext(next->getNext());
	}

}