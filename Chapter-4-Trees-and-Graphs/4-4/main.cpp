/*
Given a binary search tree, design an algorithm which creates
a linked list of all the ndoes at each depth (i.e., if you have
a tree with depth D, you'll have D linked lists)
*/

#include <iostream>
#include <algorithm>
#include "headers/LLNode.h"

// Create sample Binary Search Tree to be used
BTNode* buildTree();

// Gets hieght of longes branch within BST
int getHeight(BTNode*);

// Prints data at each recursive point to help understand
void printBTNodeData(int, int, int);

// Place nodes from BST into array of linked lists
LLNode** createListFromTree(BTNode*);

// Takes node from BST and adds to proper linked list
void placeNodesInList(BTNode*, LLNode**, int);

// Display all nodes at each level
void displayList(LLNode**);

int main(){

	BTNode* r = buildTree();

	LLNode ** table = createListFromTree(r);

	displayList(table);

}

BTNode* buildTree(){

	BTNode* r = new BTNode(5);

	r->add(2);
	r->add(1);
	r->add(3);

	r->add(7);
	r->add(6);
	r->add(8);

	r->add(4);

	return r;
}

int getHeight(BTNode* root){

	if(root == NULL){
		return 0;
	}
	else{

		int l_height = getHeight(root->getLeft());
		int r_height = getHeight(root->getRight());
		
		//printBTNodeData(root->getData(), l_height, r_height);

		if(l_height > r_height){
			return 1 + l_height;
		}
		else{
			return 1 + r_height;
		}
		

	}

}

void printBTNodeData(int data, int l_height, int r_height){

		std::cout << "Data: " << data << std::endl
				  << "L Height: " << l_height << std::endl
				  << "R Height: " << r_height << std::endl;

		std::cout << "1 + " << (l_height > r_height ? l_height : r_height);
		std::cout << " = " << (l_height > r_height ? (1 + l_height) : (1 + r_height));

		std::cout << std::endl << std::endl;

}

void placeNodesInList(BTNode* b, LLNode** levels, int l){

	if(b == NULL)
		return;
	else{
		levels[l]->add(b);
		placeNodesInList(b->getLeft(), levels, l+1);
		placeNodesInList(b->getRight(), levels, l+1);
	}
}

LLNode** createListFromTree(BTNode* r){

	int num_levels = getHeight(r);
	
	LLNode** levels = new LLNode*[num_levels];

	// Load each list with empty LLNode
	for(int i = 0; i < num_levels; i++){
		levels[i] = new LLNode;
	}

	placeNodesInList(r, levels, 0);

	return levels;
}

void displayList(LLNode** levels){

	for(int i = 0; i < 4; i++){
		LLNode * temp = levels[i];

		std::cout << "Level " << i << ": ";

		while(temp){
			std::cout << temp->getData()->getData() << "->";
			temp = temp->getNext();
		}

		std::cout << "NULL\n";
	}

}