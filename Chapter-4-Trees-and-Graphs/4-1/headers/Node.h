#ifndef NODE_H
#define NODE_H

class Node{
	int data;
	Node* left;
	Node* right;

	public:
		// Constructors
		Node(int d) : data(d), left(NULL), right(NULL) {}

		// Getters
		int getData() { return data; }
		Node* getLeft() { return left; }
		Node* getRight() { return right; }

		// Setters
		void setData(int d) { data = d; }
		void setLeft(Node* n) { left = n; }
		void setRight(Node* n) { right = n; }

		void push(int d){
			Node * n = new Node(d);
			Node * itr = this;

			while(itr){
				if(d < itr->getData()){
					if(itr->getLeft()){
						itr = itr->getLeft();
					}
					else{
						itr->setLeft(n);
						break;
					}
				}
				else if(d > itr->getData()){
					if(itr->getRight()){
						itr = itr->getRight();
					}
					else{
						itr->setRight(n);
						break;
					}
				}
				else	{
					// d = data
					break;
				}
			}



		}
};

#endif