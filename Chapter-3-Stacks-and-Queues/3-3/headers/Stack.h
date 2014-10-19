#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack{
    Node* top;
    int total;

    public:
        Stack() : top(NULL), total(0) {}
        Stack(int d) : top(new Node(d)), total(1) {}
        void push(int d) {

            Node * n = new Node(d);
            n->setNext(top);

            top = n;
            total++;

        }
        Node* pop(){
            Node * pop = top;

            if(top){
                top = top->getNext();
                total--;
            }

            return pop;
        }
        bool isEmpty() { 
            if(top == NULL)
                return true;
            else
                return false;
        }
        bool isAtCapacity(){
            return (total == 10);
        }
        int getTotal(){return total;}
};

#endif