/*
Describe how you could use a single array to implement three stacks
*/

#include <iostream>
#include "headers/Node.h"
#include "headers/Stack.h"

using namespace std;

int main(){
	Stack * s = new Stack;
	s->push(0,1);

	cout << s->pop(0) << endl;
}