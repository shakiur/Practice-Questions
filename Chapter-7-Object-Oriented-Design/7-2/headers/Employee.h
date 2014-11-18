#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
	std::string name;
	int rank;
	PhoneCall* call;

	public:
		// Constructors
		Employee(std::string n, int r) : name(n), rank(r), call(NULL) {}

		// Getters
		std::string getName() { return name; }
		bool isFree() { return call == NULL; }

		// Setters
		void setCall(PhoneCall* c) { call = c;	}
		void setFree() { call = NULL; }
};

#endif