/*
Write a program to sort a stack in ascending order. 
You should not make any assumptions about how the stack 
is implemented. The following are hte only functions 
that should be used to write this prgoram: push | 
pop | peek | isEmpty.
*/

#include <iostream>
#include "headers/Stack.h"

using namespace std;

void sortStack(Stack*&);

int main(){
	Stack* s = new Stack;
	s->push(4);
	s->push(2);
	s->push(1);
	s->push(7);
	s->push(3);

	s->display();

	sortStack(s);
	
	s->display();

}

void sortStack(Stack*& s1){
	Stack* s2 = new Stack;

	while(!s1->isEmpty()){
		// Holds top from s1
		Node * tmp = s1->pop();

		// Pops elements back to s1 is greater
		while(!s2->isEmpty() && tmp->getData() > s2->peek()->getData()){
			s1->push(s2->pop());
		}
		s2->push(tmp);

	}
	s1 = s2;
}