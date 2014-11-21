/*
Describe the data structures and algorithms that you would use to implement a gar-
bage collector in C++.
*/
#include <iostream>
#include "Headers/Person.h"
#include "Headers/SP.h"

int main(){
	Person* p1 = new Person("Jack1", 25);

	SP<Person> p2(new Person("Jack2", 25));

	SP<Person> p(new Person("Scott", 25));
    

}