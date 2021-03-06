#ifndef BTNODE_H
#define BTNODE_H

class BTNode{
	int data;
	BTNode* left;
	BTNode* right;

	public:
		// Constructors
		BTNode(int d) : data(d), left(NULL), right(NULL) {}

		// Setters
		void setData(int d) { data = d; }
		void setLeft(BTNode* l) { left = l; }
		void setRight(BTNode* r) { right = r; }

		// Getters
		int getData() { return data; }
		BTNode* getLeft() { return left; }
		BTNode* getRight() { return right; }

		void add(int d){
			BTNode* temp = this;
			BTNode* n = new BTNode(d);

			while(temp){
				if(temp->getData() == d){
					delete n;
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
		}
};

#endif