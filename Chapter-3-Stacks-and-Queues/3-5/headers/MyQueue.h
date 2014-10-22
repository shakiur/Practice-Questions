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
			}else{
				end->push(n);
			}
			
		}

		Node * dequeue(){
			// Remove front of queue
			Node * tmp = front->pop();

			// Take last elem from end list and push it
			// to front stack
			Node * last = end->popLast();
			front->push(last);

			return tmp;
		}
};

#endif