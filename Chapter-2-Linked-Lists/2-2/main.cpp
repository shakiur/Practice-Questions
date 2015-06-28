/*
Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>
#include "headers/Node.h"

using namespace std;

const string display_text = "th to last element is ";

// Builds list to test with
Node * buildList();

// Displays entire linked list
void display(Node*);

// Finds nth to last element in linked list
Node * findNthToLast(Node*, int);

int main(){
	Node * head = buildList();
	display(head);

	std::cout << 0 << display_text << findNthToLast(head, 0)->getData() << std::endl;
	std::cout << 4 << display_text << findNthToLast(head, 4)->getData() << std::endl;
	std::cout << 8 << display_text << findNthToLast(head, 8)->getData() << std::endl;
}

Node * buildList() {
	Node * n1 = new Node(1);
	Node * n2 = new Node(2, n1);
	Node * n3 = new Node(3, n2);
	Node * n4 = new Node(4, n3);
	Node * n5 = new Node(5, n4);
	Node * n6 = new Node(6, n5);
	Node * n7 = new Node(7, n6);
	Node * n8 = new Node(8, n7);
	Node * n9 = new Node(9, n8);

	return n9;
}

void display(Node* head){
	while(head){
		cout << head->getData() << "->";
		head = head->getNext();
	}
	cout << "NULL" << endl;
}

Node * findNthToLast(Node* head, int n){

	if(head == NULL)
		return NULL;

	Node * itr1 = head;
	Node * itr2 = head;

	for(int i = 0; i <= n; i++){

		// Not enough elements
		if(itr1 == NULL)
			return NULL;

		itr1 = itr1->getNext();
	}

	while(itr1){
		itr1 = itr1->getNext();
		itr2 = itr2->getNext();
	}

	return itr2;


}