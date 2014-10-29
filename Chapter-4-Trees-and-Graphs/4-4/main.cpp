/*
Given a binary search tree, design an algorithm which creates
a linked list of all the ndoes at each depth (i.e., if you have
a tree with depth D, you'll have D linked lists)
*/

#include <iostream>
#include <algorithm>
#include "headers/Node.h"

int getHeight(Node*);

int main(){

	// Build binary search tree
	Node* r = new Node(5);

	r->add(2);
	r->add(1);
	r->add(3);

	r->add(7);
	r->add(6);
	r->add(8);

	r->add(4);

	std::cout << getHeight(r) << std::endl;

}

int getHeight(Node* root){

	if(root){

		int l_height = getHeight(root->getLeft());
		int r_height = getHeight(root->getRight());
		
		if(l_height > r_height){
			std::cout << "L Data: " << root->getData() 
				 << " | 1 + " << l_height << " = " << (1 + l_height)
				 << std::endl;
			return 1 + l_height;
		}
		else{
			std::cout << "R Data: " << root->getData() 
				 << " | 1 + " << r_height << " = " << (1 + r_height)
				 << std::endl;
			return 1 + r_height;
		}

	}
	else{
		return 0;
	}

}