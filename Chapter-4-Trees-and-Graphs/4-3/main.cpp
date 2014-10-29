/*
Given a sorted (increasing order) array, write an algorithm to create
a binary tree with minimal height
*/

#include <iostream>
#include "headers/BTNode.h"

BTNode* addNodes(int[], int, int);
BTNode* buildTree(int[], int);

int main(){

	int size = 7;
	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	BTNode* root = buildTree(arr, size);
}

BTNode* addNodes(int arr[], int begin, int end){

	if(begin <= end){
		int mid = (begin + end)/2;

		/*
		std::cout << begin << " | " << end << std::endl;
		std::cout << "Mid: " << mid << "\n";
		std::cout << "Val: " << arr[mid] << std::endl << std::endl;
		*/
		
		BTNode * n = new BTNode(arr[mid]);

		n->setLeft(addNodes(arr, begin, mid-1));
		n->setRight(addNodes(arr, mid+1, end));

		return n;
	}
	else{
		return NULL;
	}

}

BTNode* buildTree(int arr[], int size){
	return addNodes(arr, 0, size-1);
}