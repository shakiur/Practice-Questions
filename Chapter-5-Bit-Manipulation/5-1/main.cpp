/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
method to set all bits between i and j in N equal to M (e.g., M becomes a substring of
N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
_________________________
*/

#include <iostream>

void setBits(int, int, int, int);

int main(){

	setBits(1024, 21, 2, 6);

}


void setBits(int N, int M, int i, int j){
	// Shifts M so it lines up to where it will be replaced
	int M_shift = M << i;

	// Sets all bits to 1
	int ones = ~0;

	// Build bits where portion to be changed is 0's
	int left_mask = ones << j;
	int right_mask = ~(ones << i);

	int mask = left_mask | right_mask;

	// Sets 0's to the bits that need to be changed
	int N_gap = N & mask;

	int result = N_gap | M_shift;

	// Prints out result
	std::cout << result << std::endl;
}