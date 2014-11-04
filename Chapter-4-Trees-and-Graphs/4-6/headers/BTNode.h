#ifndef BTNODE_H
#define BTNODE_H

class BTNode{
	int data;
	BTNode* left;
	BTNode* right;
	BTNode* parent;
	public:
		// Constructors
		BTNode(int d, BTNode* l = NULL, BTNode* r = NULL, BTNode* p = NULL) : data(d), left(l), right(r), parent(p) {}

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
};

#endif
