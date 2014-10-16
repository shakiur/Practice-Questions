#ifndef NODE_H
#define NODE_H

class Node{
	Node * next;	
	int data;

	public:
		// Constructors
		Node();
		Node(int);
		Node(int, Node*);

		// Getters
		int getData();
		Node * getNext();

		// Setters
		void setData(int);
		void setNext(Node*);
};

#endif