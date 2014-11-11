/*
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
*/
#include <iostream>

int swap(int);

int main(){
	swap(234);
}

int swap(int x){
	int y = 0;
	int prev_bit;
	int cur_bit;

	for(int i = 31; i >= 0; i--){

		if(i % 2)
			prev_bit = ((x >> i) && 1);
		else{
			cur_bit = ((x >> i) && 1);
		}
	}

	std::cout << std::endl;

	return y;
}