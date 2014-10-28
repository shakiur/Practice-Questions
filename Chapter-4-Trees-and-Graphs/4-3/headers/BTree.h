#ifndef BTREE_H
#define BTREE_H

#include "Node.h"

class BTree{
	Node* root;

	public:
		BTree() : root(NULL) {}
		BTree(int d) : root(new Node(d)) {}
		void add(int d){
			if(root == NULL){
				root = new Node(d);
			}
			else{
				root->add(d);
			}
		}
};

#endif