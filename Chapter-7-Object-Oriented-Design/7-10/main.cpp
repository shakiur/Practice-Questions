/*
Describe the data structures and algorithms that you would use to implement a gar-
bage collector in C++.
*/
#include <iostream>
#include "Headers/Person.h"
#include "Headers/SP.h"

void testFunc();

int main(){

	SP<Person> p2(new Person("Jack2", 25));
	p2->display();

	{
		SP<Person> q;
		q = p2;
		q->display();

		// Normally q will be deleted, but it has a counter
		// So it won't delete the "person" before the counter is 0
	}

	p2->display();

}
