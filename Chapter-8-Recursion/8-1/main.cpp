/*
Write a method to generate the nth Fibonacci number.
*/
#include <iostream>

int fib(int);

int main(){

	for(int i = 0; i < 10; i++)
		std::cout << i << ": " << fib(i) << std::endl;
	
}

int fib(int n){
	if(n == 0 || n == 1)
		return n;
	else
		return fib(n-2) + fib(n-1);
}
