#ifndef TECHLEAD_H
#define TECHLEAD_H

#include "Employee.h"

class TechLead : public Employee{

	public:
		TechLead(std::string n, int r) : Employee(n, r) {}
};

#endif