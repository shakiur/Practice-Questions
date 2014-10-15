#ifndef NODEFILE_H
#define NODEFILE_H

class Node{
	Node * next;
	int data;

public:
	// Constructors
	Node(int);
	Node(int, Node*);

	// Getters
	int getData();
	Node * getNext();

	// Setters
	void setNext(Node*);
};

#endif