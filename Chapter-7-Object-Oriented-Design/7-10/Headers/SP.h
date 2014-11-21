#ifndef SP_H
#define SP_H

#include "RC.h"

template<class T>
class SP{
	T* value;
	RC* reference;

	public:
		SP() : value(NULL){

			reference = new RC;
			reference->addRef();
		}

		SP(T* v) : value(v) {
			reference = new RC;
			reference->addRef();
		}

		~SP(){ 
			if(reference->release() == 0){

				if(value)
					delete value;

				delete reference;

			}

		}

		T& operator*() { return *value; }
		T* operator->() { return value; }

		SP<T>& operator= (const SP<T>& right_sp){
			if(this != &right_sp){

				// Left side SP is being replaced by right side SP
				// So we need to decrease the reference and delete
				// if it's the last one
				if(reference->release() == 0){
					if(value)
						delete value;
					delete reference;
				}

				// Copy over data to right side SP
				value = right_sp.value;
				reference = right_sp.reference;
				reference->addRef();
			}
			return *this;
		}

};

#endif