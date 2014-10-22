#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "Stack.h"

using namespace std;

class MyQueue{
	Stack * s1;
	Stack * s2;

	public:
		// Constructors
		MyQueue() : s1(new Stack), s2(new Stack) {}

		void enqueue(int d){

			Node * n = new Node(d);
			s1->push(n);
			
		}

		Node * dequeue(){

			// Get last node in s1 by popping/pushing
			// all nodes to s2
			while(!s1->isEmpty())
				s2->push(s1->pop());

			Node * n = s2->pop();

			// Places nodes back in s1
			while(!s2->isEmpty())
				s1->push(s2->pop());

			return n;
		}
};

#endif