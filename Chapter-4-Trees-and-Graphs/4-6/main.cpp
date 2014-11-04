/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree.
*/
#include <iostream>
#include "headers/BTNode.h"

// Builds unbalanced tree
BTNode* buildTree();

// 
BTNode* getCommonAncestor(BTNode*, int, int);

// Get height of tree
int getHeight(BTNode*);

int main(){
	BTNode* n = buildTree();



}

BTNode* buildTree(){
	BTNode* n7 = new BTNode(25);
	BTNode* n6 = new BTNode(10, n7);
	BTNode* n5 = new BTNode(3);
	BTNode* n4 = new BTNode(7, n5, n6);
	BTNode* n3 = new BTNode(20);
	BTNode* n2 = new BTNode(8, NULL, n3);
	BTNode* n1 = new BTNode(5, n4, n2);

	return n1;

}

int getHeight(BTNode* root){
	if(root == NULL)
		return 0;
	else{
		int l_height = getHeight(root->getLeft());
		int r_height = getHeight(root->getRight());

		if(l_height > r_height)
			return 1 + l_height;
		else
			return 1 + r_height;
	}
}