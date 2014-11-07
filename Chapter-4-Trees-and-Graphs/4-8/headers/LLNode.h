#ifndef LLNODE_H
#define LLNODE_H
#include "BTNode.h"

class LLNode{
	BTNode* data;
	LLNode* next;

	public:
		LLNode(BTNode* d): data(d), next(NULL){}
		LLNode(BTNode* d, LLNode* n) : data(d), next(n) {}

		// Getters
		BTNode* getData() { return data; }
		LLNode* getNext() { return next; }

		// Setters
		void setData(BTNode* d) { data = d; }
		void setNext(LLNode* n) { next = n; }
};

#endif