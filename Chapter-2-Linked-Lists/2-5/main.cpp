/*
Given a circular linked list, implement an algorithm which returns node at the begin-
ning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
earlier node, so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
*/

#include <iostream>
#include "headers/Node.h"

using namespace std;

// Builds a circular linked list
Node* buildCircularList();

Node* findStartOfLoop(Node*);

int main(){
	Node * head = buildCircularList();

	Node * start_of_loop = findStartOfLoop(head);

	cout << start_of_loop->getData() << endl;
}

Node * buildCircularList(){

	Node * e = new Node('e');
	Node * d = new Node('d', e);
	Node * c = new Node('c', d);
	Node * b = new Node('b', c);
	Node * a = new Node('a', b);

	e->setNext(c);

	return a;
}

Node* findStartOfLoop(Node* head){

	Node * itr1 = head;
	Node * itr2 = head;

	while(itr1 && itr2){

		itr1 = itr1->getNext();
		itr2 = itr2->getNext()->getNext();

		if(itr1 == itr2){
			
			// Resetting itr1 means itr1 & itr2 are equally
			// distance from beginning of cycle			
			itr1 = head;

			while(itr1 && itr2){
				itr1 = itr1->getNext();
				itr2 = itr2->getNext();

				// When both are equal, we have met the first cyclic node
				if(itr1 == itr2)
					return itr1;
			}

		}
	}

}