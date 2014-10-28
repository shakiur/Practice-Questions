#ifndef NODE_H
#define NODE_H

class Node{
	int data;
	Node* left;
	Node* right;

	public:
		// Constructors
		Node() : left(NULL), right(NULL) {}
		Node(int d) : data(d), left(NULL), right(NULL) {}

		// Setters
		void setData(int d) { data = d; }
		void setLeft(Node* l) { left = l; }
		void setRight(Node* r) { right = r; }

		// Getters
		int getData() { return data; }
		Node* getLeft() { return left; }
		Node* getRight() { return right; }

		void add(int d){
			Node * temp = this;
			Node * n = new Node(d);

			if(temp->getData() == d){
				return;
			}
			else if(d < temp->getData()){
				if(temp->getLeft()){
					temp = temp->getLeft();
				}
				else{
					temp->setLeft(n);
					return;
				}
			}
			else{
				if(temp->getRight()){
					temp = temp->getRight();
				}
				else{
					temp->setRight(n);
					return;
				}
			}
				
		}
};

#endif