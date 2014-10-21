#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "Stack.h"

using namespace std;

class MyQueue{
	Stack * front;
	Stack * end;

	public:
		// Constructors
		MyQueue() : front(new Stack), end(new Stack) {}

		void enqueue(int d){
			Node * n = new Node(d);

			if(front->isEmpty()){
				Node * f = new Node(d);
				front->push(f);
			}
			
			end->push(n);
			
		}

		Node * dequeue(){
			Node * tmp = front->pop();

			front->push(end->popLast());

			return tmp;
		}
};

#endif