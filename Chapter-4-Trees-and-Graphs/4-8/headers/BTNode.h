#ifndef BTNODE_H
#define BTNODE_H

class BTNode{
	int data;
	BTNode* left;
	BTNode* right;
	BTNode* parent;

	public:
		BTNode(int d) : data(d), left(NULL), right(NULL), parent(NULL) {}

		// Setters
		void setData(int d) { data = d; }
		void setLeft(BTNode* l) { left = l; }
		void setRight(BTNode* r) { right = r; }
		void setParent(BTNode* p) { parent = p; }

		// Getters
		int getData() { return data; }
		BTNode* getLeft() { return left; }
		BTNode* getRight() { return right; }
		BTNode* getParent() { return parent; }

		void push(int d){
			BTNode* n = new BTNode(d);
			BTNode* temp = this;

			while(temp){
				if(d == temp->getData()){
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