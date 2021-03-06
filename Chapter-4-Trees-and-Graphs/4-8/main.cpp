/*
You are given a binary tree in which each node contains a value. Design an algorithm 
to print all paths which sum up to that value. Note that it can be any path in the tree 
- it does not have to start at the root.
*/
#include <iostream>
#include "headers/Stack.h"

BTNode* buildTree();

void findPaths(BTNode*, int);

void calcPaths(BTNode*, Stack*, int, int);

int main(){
	BTNode* root = buildTree();
	findPaths(root, 5);
}

BTNode* buildTree(){
	BTNode* root = new BTNode(5);
	root->push(2);
	root->push(1);
	root->push(3);
	root->push(4);
	root->push(7);
	root->push(6);
	root->push(8);

	return root;
}

void findPaths(BTNode* root, int val){ 
	if(root){ 

		Stack* s = new Stack;
		int total = 0;

		calcPaths(root, s, val, total);

		if(root->getLeft())
			findPaths(root->getLeft(), val);

		if(root->getRight())
			findPaths(root->getRight(), val);

	}
}

void calcPaths(BTNode* root, Stack* s, int val, int total){

	total += root->getData();
	s->push(root);

	if(total == val){	
		// Print current stack
		s->display();
	}
	else if(total < val){	
		// Check left and right path
		if(root->getLeft())
			calcPaths(root->getLeft(), s, val, total);
		
		if(root->getRight())
			calcPaths(root->getRight(), s, val, total);
	}
	else{
		// new total is higher than value
		// Subtract latest value and return
		total -= root->getData();
		s->pop();
	}

}