/*
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. THerefore,
in real life, we would likely start a new stack when the previous stack exceeds
some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks
should be composed of seceral stacks, and should create a new stack once the previous
one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave
identically to a single stack (that is, pop() should return the same values as it would if
there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operations on a sepeicific
sub-stack
*/

#include <iostream>
#include <vector>
#include "headers/SetOfStacks.h"

using namespace std;

int main(){

    SetOfStacks * ss = new SetOfStacks;
    
    // Old Stack
    ss->push(0);
    ss->push(1);
    ss->push(2);
    ss->push(3);
    ss->push(4);
    ss->push(5);
    ss->push(6);
    ss->push(7);
    ss->push(8);
    ss->push(9);

    // New Stack
    ss->push(10);
    ss->push(11);
    ss->push(12);
    ss->push(13);
    ss->push(14);
    ss->push(15);
    ss->push(16);
    ss->push(17);
    ss->push(18);
    ss->push(19);
    
    // Pop from 1st Stack
    ss->popAt(0);

    // Pop from 2nd Stack
    ss->popAt(1);
}