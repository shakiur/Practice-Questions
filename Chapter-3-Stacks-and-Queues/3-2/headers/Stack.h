#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack{
	Node * top;

	public:
		Stack() : top(NULL) {}
		Stack(int d) : top(new Node(d)) {}
		void push(int d){

			// New Node to place at stop of stack
			Node * new_top = new Node(d);

			// Sets new top next value to current top
			new_top->setNext(top);

			// Top of stack is now newest node
			top = new_top;

		}
		Node * pop(){

			// Holds old top which will be removed
			Node * old_top = top;

			// Sets top to the next Node
			top = old_top->getNext();

			// Returns top most Node
			return old_top;
		}

};

#endif