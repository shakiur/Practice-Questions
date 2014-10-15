/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include "headers/node.h"
#include "headers/hashentry.h"
#include "headers/hashmap.h"

using namespace std;

void displayList(Node*);

void removeDupe(Node*&);

int main(){

	Node * f = new Node(6);
	Node * e = new Node(5, f);
	Node * d = new Node(4, e);
	Node * c = new Node(1, d);
	Node * b = new Node(1, c);
	Node * a = new Node(1, b);

	cout << "\n===Old List===\n";
	displayList(a);

	removeDupe(a);

	cout << "\n===New List===\n";
	displayList(a);


	
}

void displayList(Node* head){

	while(head){
		cout << head->getData() << endl;
		head = head->getNext();
	}

}

void removeDupe(Node*& head){

	HashMap * node_hm = new HashMap();
	Node * curr = head;
	Node * prev = head;

	// Go through linked list and update counts in hash table
	while(curr){
		int count = node_hm->getValue(curr->getData());

		// -1 indicates first node, set to 0 so it will
		// be incremented corrected
		if(count == -1)
			count++;

		node_hm->insertEntry(curr->getData(), (++count));
		
		// If current node has count > 1, remove
		if(count > 1){
			prev->setNext(curr->getNext());
			
			curr = prev->getNext();
		}
		
		curr = curr->getNext();
		prev = curr;

	}

	//node_hm->display();
	

}