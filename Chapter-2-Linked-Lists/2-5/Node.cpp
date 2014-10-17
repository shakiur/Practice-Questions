#include <iostream>
#include "headers/Node.h"

// Constructors
Node::Node() : next(NULL) {}
Node::Node(char d) : data(d), next(NULL) {}
Node::Node(char d, Node* n) : data(d), next(n) {}

// Setters
void Node::setData(char d) { data = d; }
void Node::setNext(Node* n) { next = n; }

// Getters
char Node::getData() { return data; }
Node* Node::getNext() { return next; }

// Append new node to end of list
void Node::append(char d){

	// New node to append
	Node * new_node = new Node(d);

	// Node to iterate through list
	Node * temp = next;

	// Find last node in list
	while(temp->getNext()){
		temp = temp->getNext();
	}

	// Set last lists next to new node
	temp->setNext(new_node);
	
}
