#ifndef PERSON_H
#define PERSON_H

class Person{
	std::string name;
	int age;

	public:
		Person() : name("TBD"), age(0) {}
		~Person() { std::cout << name << " deleted\n"; }
		Person(std::string n, int a) : name(n), age(a) {}
		void Display() { std::cout << name << std::endl;}

};

#endif