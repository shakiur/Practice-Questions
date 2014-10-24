/*
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one
*/

#include <iostream>
#include "headers/Node.h"

void preOrder(Node*);

int maxDepth(Node*);
int minDepth(Node*);

bool isBalanced(Node*);

using namespace std;

int main(){
	Node * n = new Node(10);
	n->push(5);
	n->push(3);
	n->push(1);
	n->push(20);

	//preOrder(n);

	if(isBalanced(n))
		cout << "Tree is balanced\n";
	else
		cout << "Tree is NOT balanced\n";
}

void preOrder(Node* itr){

	cout << itr->getData() << endl;

	if(itr->getLeft()){
		cout << "Left: ";
		preOrder(itr->getLeft());
	}
	if(itr->getRight()){
		cout << "Right: ";
		preOrder(itr->getRight());
	}

}

int maxDepth(Node* r){
	if(r == NULL)
		return 0;
	else
		return 1 + max(maxDepth(r->getRight()), maxDepth(r->getLeft()));
}

int minDepth(Node* r){
	if(r == NULL)
		return 0;
	else
		return 1 + min(minDepth(r->getRight()), minDepth(r->getLeft()));
}

bool isBalanced(Node* r){
	cout << "Max Depth: " << maxDepth(r) << endl;
	cout << "Min Depth: " << minDepth(r) << endl;
	return (maxDepth(r) - minDepth(r) <= 1);
}