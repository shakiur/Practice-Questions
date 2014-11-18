#ifndef PRODUCTMGR_H
#define PRODUCTMGR_H

#include "Employee.h"

class ProductManager : public Employee {

	public:
		ProductManager(std::string n, int r) : Employee(n, r) {}
};

#endif