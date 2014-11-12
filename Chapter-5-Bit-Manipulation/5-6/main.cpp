/*
Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
*/
#include <iostream>
#include <bitset>

int swap(int);

int main(){
	std::cout << swap(234) << std::endl;
}

int swap(int x){

	int prev_bit;
	int cur_bit;

	std::bitset<sizeof(x)*8> x_bs(x);

	for(int i = x_bs.size() - 1; i >= 0; i--){
		if(i % 2){
			// Odd bit
			prev_bit = ((x >> i) & 1);
		}
		else{
			//Even bit
			cur_bit = ((x >> i) & 1);

			// Switch bits
			x_bs.set(i, prev_bit);
			x_bs.set(i+1, cur_bit);

		}
	}

	return (int)x_bs.to_ulong();

}