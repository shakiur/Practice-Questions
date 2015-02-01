/*
You are given a binary tree in which each node contains a value. Design an algorithm 
to print all paths which sum up to that value. Note that it can be any path in the tree 
- it does not have to start at the root.
*/
#include <iostream>
#include "headers/Stack.h"

BTNode* buildTree();

void printPathsToVal(BTNode*, int);

void findPaths(BTNode*, Stack*, int, int);

void calcPaths(BTNode*, Stack*, int, int&);

int main(){
	BTNode* root = buildTree();
	printPathsToVal(root, 5);
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

void printPathsToVal(BTNode* root, int val){

	Stack* s = new Stack(root);
	findPaths(root, s, val, 0);

}

void findPaths(BTNode* root, Stack* s, int val, int total){ 
	if(root){ 

		calcPaths(root, s, val, total);

		if(root->getLeft())
			findPaths(root->getLeft(), s, val, total);

		if(root->getRight())
			findPaths(root->getRight(), s, val, total);
	}
}

void calcPaths(BTNode* root, Stack* s, int val, int& total){

	total += root->getData();
	s->push(root);

	if(total == val){	
		// Print current stack
		// Delete last entry in stack
	}
	else if(total < val){	
		// Return from here
	}
	else{ 
		// new total is higher than value

	}

	// Pop up top of stack
	// Subtrack from total so you can start over
}