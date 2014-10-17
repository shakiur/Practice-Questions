#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack{

	int stack_size;
	int * arr;
	int * stack_ptr;


	public:
		Stack(){
			stack_size = 300;

			// Array to hold all 3 stacks
			arr = new int[stack_size*3];

			// Pointers to keep track of each stack
			stack_ptr = new int[3];
			stack_ptr[0] = 0;
			stack_ptr[1] = 0;
			stack_ptr[2] = 0;

		}

		void push(int stack_num, int data){

			// stack_num * stack_size indicates which stack
			// out of 3, stack_ptr shows where in stack
			// theres a free slot
			arr[stack_num * stack_size + stack_ptr[stack_num]] = data;

			stack_ptr[stack_num]++;
		}

		int pop(int stack_num){
			int pos = (stack_num * stack_size + stack_ptr[stack_num])-1;
			
			int pop = arr[pos];
			arr[pos] = 0;

			return pop;

		}



};

#endif