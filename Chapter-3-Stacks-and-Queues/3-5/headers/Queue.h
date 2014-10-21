#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

#include <iostream>

using namespace std;

class Queue{
	Node* head;
	Node* tail;

	public:
		// Constructors
		Queue() : head(NULL), tail(NULL) {}
		Queue(Node* n) : head(n), tail(n) {}

		void enqueue(int d){

			Node* n = new Node(d);

			if(head == NULL){
				// No entries in queue
				head = n;
				tail = n;
			}
			else{
				// Queue has people, append tot ail
				tail->setNext(n);
				tail = n;
			}
		}

		Node * dequeue(){
			if(head == NULL){
				// Queue is empty return null
				return NULL;
			}
			else if (head == tail){
				// Queue has 1 entry
				Node * n = head;
				head = NULL;
				tail = NULL;

				return n;
			}
			else{
				// Queue has multiple entries
				Node * n = head;
				head = head->getNext();
				return n;
			}

		}

		void display(){
			Node * itr = head;

			while(itr){
				cout << itr->getData() << "->";
				itr = itr->getNext();
			}
			cout << "NULL" << endl;
		}
};

#endif