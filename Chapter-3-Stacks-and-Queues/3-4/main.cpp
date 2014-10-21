/*
In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different
sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending
order of size from top to bottom (e.g., each disk sits on top of an even larger one). You
have the following constraints:	
(A) Only one disk can be moved at a time.
(B) A disk is slid off the top of one rod onto the next rod.
(C) A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks.
*/

#include <iostream>
#include "headers/Stack.h"

using namespace std;

Stack* buildDiscs();

void hanoi(int, Stack*&, Stack*&, Stack*&);

int main(){

	int size = 5;

	Stack * rod1 = buildDiscs();
	Stack * rod2 = new Stack;
	Stack * rod3 = new Stack;

	hanoi(size, rod1, rod2, rod3);
	
}

Stack* buildDiscs(){
	Stack * discs = new Stack;

	discs->push(5);
	discs->push(4);
	discs->push(3);
	discs->push(2);
	discs->push(1);

	return discs;
}

void hanoi(int discs, Stack*& source, Stack*& dest, Stack*& spare){

	if(discs == 1){
		dest->push(source->pop()->getData());
	}
	else{
		hanoi(discs-1, source, spare, dest);
		dest->push(source->pop()->getData());
		hanoi(discs-1, spare, dest, source);
	}

}