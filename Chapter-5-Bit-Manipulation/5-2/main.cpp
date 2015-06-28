/*
Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary rep-
resentation. If the number can not be represented accurately in binary, print “ERROR”
*/
#include <iostream>

int main(){

	int i; // declare variables
	float f;
	int bit = 0;

	f = 3.65;

	int *b = reinterpret_cast<int*>(&f); // use reinterpret_cast function

	std::cout << f << std::endl;
	std::cout << *b << std::endl;

	for (int k = 31; k >=0; k--) // for loop to print out binary pattern
	{
		bit = ((*b >> k)&1); // get the copied bit value shift right k times, then and with a 1.
		std::cout << bit; // print the bit.
	}
}

