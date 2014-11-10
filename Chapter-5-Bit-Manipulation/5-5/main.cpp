/*
Write a function to determine the number of bits required to convert integer A to 
integer B. 
Input: 31, 14
Output: 2
*/
#include <iostream>

int bitsToConvert(int, int);

int main(){
	int result = bitsToConvert(31, 14);

	std::cout << result << std::endl;

}

int bitsToConvert(int a, int b){
	int bits_changed = 0;

	// Iterate through each bit in both numbers
	// If bit is different then it needs to be switched
	for(int i = 31; i >= 0; i--){
		if(((a >> i) & 1) != ((b >> i) & 1))
			bits_changed++;
	}

	return bits_changed;
}