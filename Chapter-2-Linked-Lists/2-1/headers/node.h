#ifndef NODEFILE_H
#define NODEFILE_H

class Node{
	Node * next;
	int data;

public:
	Node(int);
	int getData();
	Node * getNext();
};

#endif