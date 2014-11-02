/*
Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in 
a binary search tree where each node has a link to its parent.
*/

#include <iostream>
#include "headers/BTNode.h"

// Builds sample BST to work with
BTNode* buildBST();

// Find in-order succcessor
BTNode* findNextInOrder(BTNode*);

BTNode* findLeftMost(BTNode*);

int main(){
    BTNode* root = buildBST();
    BTNode* n = findNextInOrder(root);

    std::cout << n->getData() << std::endl;
}

BTNode* buildBST(){
    BTNode* n1 = new BTNode(20);
    BTNode* n2 = new BTNode(8);
    BTNode* n3 = new BTNode(22);
    BTNode* n4 = new BTNode(4);
    BTNode* n5 = new BTNode(12);
    BTNode* n6 = new BTNode(10);
    BTNode* n7 = new BTNode(14);

    n1->setLeft(n2);
    n1->setRight(n3);

    n2->setLeft(n4);
    n2->setRight(n5);
    n2->setParent(n1);

    n5->setLeft(n6);
    n5->setRight(n7);
    n5->setParent(n2);

    return n1;
}

BTNode* findNextInOrder(BTNode* n){

    if(n->getRight()){
        return findLeftMost(n->getRight());
    }
    else{
        BTNode* parent = n->getParent();

        if(parent->getLeft() == n)
            return parent;
        else
            return n;
    }

}

BTNode* findLeftMost(BTNode* root){
    if(root->getLeft() == NULL)
        return root;
    else
        return findLeftMost(root->getLeft());
}
