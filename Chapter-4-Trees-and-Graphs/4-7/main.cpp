/*
You have two very large binary trees: T1, with millions of nodes, and T2, with hun-
dreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
*/
#include <iostream>
#include "headers/BTNode.h"

BTNode* buildTree();
BTNode* buildSubTree();

bool checkIfSubTree(BTNode*, BTNode* );

bool checkAllNodes(BTNode*, BTNode* );

int main(){
	BTNode* r1 = buildTree();
	BTNode* r2 = buildSubTree();
}

BTNode* buildTree(){
	BTNode* root = new BTNode(5);
	root->push(2);
	root->push(7);
	root->push(1);
	root->push(3);
	root->push(4);
	root->push(6);
	root->push(8);

	return root;
}

BTNode* buildSubTree(){
	BTNode* root = new BTNode(7);
	root->push(6);
	root->push(8);

	return root;
}

bool checkIfSubTree(BTNode* r1, BTNode* r2){
	if(r1 == NULL){
		// r1 has been full analyzed
		return false;
	}
	else if(r1->getData() == r2->getData()){
		if(checkAllNodes(r1, r2))
			return true;
	}
	else{
		return checkIfSubTree(r1->getLeft(), r2) || checkIfSubTree(r1->getRight(), r2);
	}
}

bool checkAllNodes(BTNode* r1, BTNode* r2){
	return true;
}