/*
You are given a binary tree in which each node contains a value. Design an algorithm 
to print all paths which sum up to that value. Note that it can be any path in the tree 
- it does not have to start at the root.
*/
#include <iostream>
#include "headers/Stack.h"

BTNode* buildTree();

void printPathsToVal(BTNode*, int);

void lookForPaths(Stack*, BTNode*, int, int);

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
	if(root){
		printPathsToVal(root->getLeft(), val);

		// Stack holds paths starting from current root
		Stack* s = new Stack(root);
		lookForPaths(s, root, val, 0);

		printPathsToVal(root->getRight(), val);
		
	}
}

void lookForPaths(Stack* s, BTNode* root, int val, int total){
	
}