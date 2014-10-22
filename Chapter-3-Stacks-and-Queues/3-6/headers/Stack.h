#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

using namespace std;

class Stack{
	Node* top;

	public:
		Stack() : top(NULL) {}
		Stack(int d) : top(new Node(d)) {}
		Stack(Node* n) : top(n) {}

		void push(int d){
			Node* n = new Node(d);

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

		Node* peek(){
			if(!top){
				return NULL;
			}
			else{
				return top;
			}
		}

		bool isEmpty(){
			return top == NULL;
		}
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