#ifndef SP_H
#define SP_H

#include "RC.h"

template<class T>
class SP{
	T* value;
	RC* reference;
	public:
		SP(T* v) : value(v) {
			reference = new RC;
			reference->addRef();
		}

		~SP(){ 

			delete value; 
		}

		T& operator*() { return *value; }
		T* operator->() { return value; }

	    SP<T>& operator = (const SP<T>& sp)
	    {
	        // Assignment operator
	        if (this != &sp) // Avoid self assignment
	        {
	            // Decrement the old reference count
	            // if reference become zero delete the old data
	            if(reference->release() == 0)
	            {
	                delete value;
	                delete reference;
	            }

	            // Copy the data and reference pointer
	            // and increment the reference count
	            value = sp.value;
	            reference = sp.reference;
	            reference->addRef();
	        }
	        return *this;
	    }
};

#endif