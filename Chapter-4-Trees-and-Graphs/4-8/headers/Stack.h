#ifndef STACK_H
#define STACK_H
#include "LLNode.h"
class Stack{
	LLNode* top;

	public:
		Stack(BTNode* t) : top(new LLNode(t)){}
		void push(BTNode* b){
			LLNode* n = new LLNode(b);
			n->setNext(top);
			top = n;
		}
		LLNode* pop(){
			LLNode* temp = top;
			top = top->getNext();
			return temp;
		}
};

#endif