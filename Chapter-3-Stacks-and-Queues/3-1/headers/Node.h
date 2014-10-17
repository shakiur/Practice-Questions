#ifndef NODE_H
#define NODE_H

class Node{
	int data;
	Node* next;

	public:
		// Constructors
		Node() : next(NULL){}
		Node(int d) : data(d), next(NULL) {}
		Node(int d, Node* n) : data(d), next(NULL) {}

		// Setters
		void setData(int d) { data = d; }
		void setNext(Node* n) { next = n; }

		// Getters
		int getData() { return data; }
		Node* getNext() { return next; }

		// Append to end
		void appendToEnd(int d){
			Node * new_entry = new Node(d);

			Node * next_itr = next;

			// Gets last node within the list
			while(next_itr->getNext())
				next_itr = next->getNext();

			// Appends new_entry to last node
			next_itr->setNext(new_entry);

		}
};

#endif