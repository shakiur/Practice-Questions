#ifndef NODE_H
#define NODE_H

class Node{

	char data;
	Node * next;

	public:
		// Constructors
		Node();
		Node(char);
		Node(char, Node*);

		// Setters
		void setData(char);
		void setNext(Node*);

		// Getters
		char getData();
		Node* getNext();

		// Append
		void append(char);
};

#endif