#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

#include "Stack.h"
#include <vector>

using namespace std;

class SetOfStacks{
    vector<Stack*> s;

    public:
        SetOfStacks() {
            Stack * temp = new Stack;
            s.push_back(temp);
        }
        void push(int d){

            if(s.back()->isAtCapacity()){
                // Latest stack at capacity, create new stack
                Stack * new_stack = new Stack(d);
                s.push_back(new_stack);
            }
            else{
                // Latest stack is not full, push to that stack
                s.back()->push(d);
            }
        }

        Node* pop(){
            // Gets last stack in vector, pops the stack
            return s.back()->pop();
        }

        Node* popAt(int indx){
            Node * pop = s[indx]->pop();

            return pop;
        }
};

#endif