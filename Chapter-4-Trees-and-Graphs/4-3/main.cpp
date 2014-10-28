/*
Given a sorted (increasing order) array, write an algorithm to create
a binary tree with minimal height
*/
#include <iostream>
#include "headers/BTree.h"

int main(){

	int arr[] = {1, 2, 3, 4, 5};
	int size = 4;

	int root = arr[size/2];
	arr[size/2] = -1;

	BTree* n = new BTree(root);

	for(int i = 0; i < size; i++){
		if(arr[i] != -1)
			n->add(arr[i]);
	}

}