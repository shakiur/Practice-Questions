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

			Node * f = new Node(d);
			s1->push(f);

		}

		Node * dequeue(){
			// Reverse order of s1 into s2 to get first
			// node that was placed in s1
			while(!s1->isEmpty()){
				s2->push(s1->pop());
			}

			Node * n = s2->pop();
			
			// Return elements to s1
			while(!s2->isEmpty()){
				s1->push(s2->pop());
			}

			return n;
		}
};

#endif