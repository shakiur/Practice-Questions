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

			if(top){

				if(d > top->getData()){
					cout << "NODE NOT ADDED\n";
					return;
				}
			}

			Node * n = new Node(d, top);
			top = n;

		}

		Node* pop(){
			Node * pop_n = top;

			if(top)
				top = top->getNext();

			return pop_n;
		}

		bool isEmpty() { return top == NULL; }

		void display(){
			Node * itr = top;

			while(itr){
				cout << itr->getData() << "->";
				itr = itr->getNext();
			}

			cout << "NULL" << endl;
		}

};

#endif