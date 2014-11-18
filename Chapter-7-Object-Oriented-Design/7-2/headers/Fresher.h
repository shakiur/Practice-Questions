#ifndef FRESHER_H
#define FRESHER_H

#include "Employee.h"

class Fresher : public Employee{

	public:
		Fresher(std::string n, int r) : Employee(n, r) {}
};

#endif