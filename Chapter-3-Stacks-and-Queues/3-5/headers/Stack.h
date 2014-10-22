#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

using namespace std;

class Stack{
	Node* top;

	public:
		// Constructors
		Stack() : top(NULL) {}
		Stack(int d) : top(new Node(d)) {}

		void push(int d){
			Node * n = new Node(d);
			n->setNext(top);
			top = n;
		}

		void push(Node* n){
			n->setNext(top);

			top = n;

		}

		Node* pop(){
			if(!top)
				return NULL;
			else{
				Node * n = top;
				top = top->getNext();
				return n;
			}
		}

		bool isEmpty() {
			return top == NULL;
		}
};

#endif