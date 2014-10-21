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

		Node* popLast(){
			if(!top)
				return NULL;
			else{
				Node * itr = top;
				Node * itr2 = top;

				// Find last element
				while(itr->getNext())
					itr = itr->getNext();

				cout << "Last Elem: " << itr->getData() << endl;


				// Remove last itr
				while(itr2){

					if(itr2->getNext() == itr)
						itr2->setNext(NULL);
					
					itr2 = itr2->getNext();
				}

				return itr;
			}
		}

		bool isEmpty() {
			return top == NULL;
		}
};

#endif