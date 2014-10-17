/*
How would you design a stack which, in addition to push and pop, also has a function 
min which returns the minimum element? Push, pop and min should all operate in 
O(1) time
*/

#include <iostream>
#include "headers/Node.h"
#include "headers/Stack.h"

using namespace std;

int main(){
	Stack * s = new Stack;
	s->push(5);
	s->push(4);
	s->push(3);
	s->push(2);
	s->push(1);

	// Check if min is correct
	cout << s->min()->getData() << endl;

	// Remove top/min element
	s->pop();

	// Check if new min is correct
	cout << s->min()->getData() << endl;
}