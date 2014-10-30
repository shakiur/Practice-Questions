/*
Given a binary search tree, design an algorithm which creates
a linked list of all the ndoes at each depth (i.e., if you have
a tree with depth D, you'll have D linked lists)
*/

#include <iostream>
#include <algorithm>
#include "headers/BTNode.h"

int getHeight(BTNode*);

void printBTNodeData(int, int, int);



int main(){

	// Build binary search tree
	BTNode* r = new BTNode(5);

	r->add(2);
	r->add(1);
	r->add(3);

	r->add(7);
	r->add(6);
	r->add(8);

	r->add(4);

	std::cout << getHeight(r) << std::endl;

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