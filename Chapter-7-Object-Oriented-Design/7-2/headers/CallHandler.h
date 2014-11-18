#ifndef CALLHANDLER_H
#define CALLHANDLER_H

#include "PhoneCall.h"
#include "Fresher.h"
#include "TechLead.h"
#include "ProductManager.h"

class CallHandler{
	std::vector<Fresher*> freshers;
	TechLead * tl;
	ProductManager* pm;
	
	public:
		CallHandler() {
			// Load all employees
			freshers.push_back(new Fresher("Bob", 0));
			freshers.push_back(new Fresher("Bill", 0));
			freshers.push_back(new Fresher("John", 0));
			freshers.push_back(new Fresher("Jack", 0));
			freshers.push_back(new Fresher("Matt", 0));

			tl = new TechLead("Jim", 1);

			pm = new ProductManager("Michael", 2);
		}

		Employee* getCallHandler(){

			// Find free fresher
			for(int i = 0; i < freshers.size(); i++){

				if(freshers[i]->isFree()){
					return freshers[i];
				}
				
			}

			// If freshers are full, escalate to tech lead
			if(tl->isFree())
				return tl;

			// If tech lead is full, escalate to product manager
			if(pm->isFree())
				return pm;

			// If all is full, return NULL and wait
			return NULL;
		}


};

#endif