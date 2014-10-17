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

			// If old top has a min, then either update new top 
			// with itself or use old_tops min node
			if(top){
				if(d < top->getMin()->getData())
					new_top->setMin(new_top);
				else
					new_top->setMin(top->getMin());
			}
			else{
				new_top->setMin(new_top);
			}

			// Places new_top on top of stack
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

		Node * min() { return top->getMin(); }

};

#endif