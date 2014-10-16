/*

You have two numbers represented by a linked list, where each node
contains a single digit. THe digits are stored in reverse order,
such that the 1's digit is at the head of the list. Write a 
function that adds the two numbers and returns the sum
as a linked list

EXAMPLE:
Input: (3->1->5) + (5->9->2)
Output: 8->0->2

*/

#include <iostream>
#include <math.h>
#include "headers/node.h"

using namespace std;

// Build list1 to add
template<class T>
Node<T>* buildList1();

// Build list 2 to add
template<class T>
Node<T>* buildList2();

// Displays a linked list
template<class T>
void display(Node<T>*);

// Sums 2 lists and returns porn to the total list
template<class T>
Node<T>* sum_nodes(Node<T>*, Node<T>*);

// Appends new node with (data) to end of list
template<class T>
void appendNode(Node<T>*&, T data);

int main(){
	Node<int>* list1 = buildList1<int>();
	Node<int>* list2 = buildList2<int>();

	Node<int>* sum_list = sum_nodes(list1, list2);

	display(list1);
	cout << "+\n";
	display(list2);
	cout << "=============\n";

	display(sum_list);
}

template<class T>
Node<T>* buildList1(){
	Node<T> * n3 = new Node<T>(5);
	Node<T> * n2 = new Node<T>(1, n3);
	Node<T> * n1 = new Node<T>(3, n2);

	return n1;
}

template<class T>
Node<T>* buildList2(){
	Node<T> * n3 = new Node<T>(2);
	Node<T> * n2 = new Node<T>(9, n3);
	Node<T> * n1 = new Node<T>(5, n2);

	return n1;
}

template<class T>
void display(Node<T>* head){
	while(head){
		cout << head->getData() << "->";
		head = head->getNext();
	}
	cout << "NULL" << endl;
}

template<class T>
Node<T>* sum_nodes(Node<T>* list1, Node<T>* list2){

	int power1 = 0;
	int power2 = 0;
	int power3 = 0;

	int total = 0;

	// Convert list1 to a number
	while(list1){
		total += pow(10,power1)*list1->getData();

		power1++;
		list1 = list1->getNext();
	}

	// Convert list2 to a number
	while(list2){
		total += pow(10,power2)*list2->getData();

		power2++;
		list2 = list2->getNext();
	}

	// Node to hold total digits
	Node<int>* totalNode = NULL;

	// Convert total into single digits
	while(total){
		int digit = total % int(pow(10, power3+1));
		digit /= pow(10, power3);

		// Append node/digit to totalNode list
		appendNode<int>(totalNode, digit);

		total -= digit * pow(10, power3);
		power3++;
	}

	return totalNode;
}

template<class T>
void appendNode(Node<T>*& head, T data){

	// Case if head is empty
	if(head == NULL){
		head = new Node<T>(data);
		return;
	}

	Node<T>* head_itr = head;

	// If head is full, iterate until last node is found
	while(head_itr){

		if(head_itr->getNext() == NULL) {

			// Last node found, append new node
			Node<T>* temp = new Node<T>(data);
			head_itr->setNext(temp);
			return;

		}

		head_itr = head_itr->getNext();

	}

}