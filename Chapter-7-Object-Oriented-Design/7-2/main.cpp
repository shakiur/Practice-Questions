/*
Imagine you have a call center with three levels of employees: fresher, technical lead
(TL), product manager (PM). There can be multiple employees, but only one TL or PM.
An incoming telephone call must be allocated to a fresher who is free. If a fresher
can’t handle the call, he or she must escalate the call to technical lead. If the TL is
not free or not able to handle it, then the call should be escalated to PM. Design the
classes and data structures for this problem. Implement a method getCallHandler().
*/

#include <iostream>
#include <vector>
#include <string>

#include "headers/PhoneCall.h"
#include "headers/Fresher.h"
#include "headers/TechLead.h"
#include "headers/ProductManager.h"

int main(){
	PhoneCall* p1 = new PhoneCall("7188460559");
	Fresher* f1 = new Fresher("Jack", 0);
	TechLead* t1 = new TechLead("Stephen", 1);
	ProductManager* pm1 = new ProductManager("Mary", 1);


}