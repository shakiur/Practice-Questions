#ifndef LLNODE_H
#define LLNODE_H

#include "BTNode.h"

class LLNode{
	BTNode * data;
	LLNode * next;

	public:
		// Constructors
		LLNode() : data(NULL), next(NULL) {}
		LLNode(BTNode* d) : data(d), next(NULL) {}

		// Getters
		BTNode* getData() { return data; }
		LLNode* getNext() { return next; }

		// Setters
		void setData(BTNode* d) { data = d; }
		void setNext(LLNode* n) { next = n; }

		void add(BTNode* b){

			LLNode * n = new LLNode(b);

			// If LLNode is empty, add BTNode to current
			if(data == NULL){
				data = b;
				return;
			}

			// Otherwise iterate until last LLNode is found
			LLNode * temp = this;

			while(temp->getNext()){
				temp = temp->getNext();
			}

			temp->setNext(n);

		}

};

#endif