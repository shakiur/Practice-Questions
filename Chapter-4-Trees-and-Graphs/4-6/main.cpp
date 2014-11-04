/*
Design an algorithm and write code to find the first common ancestor of two nodes
in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree.
*/
#include <iostream>
#include <map>
#include "headers/BTNode.h"

// Builds unbalanced tree
BTNode* buildTree();

// Finds common ancestor by traverseing parent nodes
BTNode* getCommonAncestor(BTNode*, BTNode*, BTNode*);

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

	n7->setParent(n6);
	n6->setParent(n4);
	n5->setParent(n4);
	n4->setParent(n1);
	n3->setParent(n2);
	n2->setParent(n1);

	return n1;

}

BTNode* getCommonAncestor(BTNode* root, BTNode* p, BTNode q){
	std::map<BTNode*, bool> p_visit;

	// Marks each parent node as visited
	while(p != root){
		p_visit[p] = true;
		p = p->getParent();
	}

	// Traverse q's parent node until matching node from q is found
	while(q != root){
		if(p_visit[q])
			return q;
		q = q->getParent();
	}

	return NULL;
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