/*
An array A[1...n] contains all the integers from 0 to n except for one number which is
missing. In this problem, we cannot access an entire integer in A with a single opera-
tion. The elements of A are represented in binary, and the only operation we can use
to access them is “fetch the jth bit of A[i]”, which takes constant time. Write code to
find the missing integer. Can you do it in O(n) time?
*/

#include <iostream>
#include <math.h>

const int size = 12;

int findMissingInt(int[], int);

int returnBit(int, int);

int main(){

	int arr[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };

	std::cout << findMissingInt(arr, size) << std::endl;

}

int findMissingInt(int bs_arr[], int size){

	int missing = 0;

	int prev_bit = returnBit(bs_arr[0], 0);

	for(int i = 1; i < size; i++){
		//std::cout << bs_arr[i] << ": " << ((bs_arr[i]) & 1) << std::endl;

		if(prev_bit == returnBit(bs_arr[i], 0)){

			// Missing bit found, calculate value and subtract by 1
			for(int j = 0; j < 32; j++){

				if(returnBit(bs_arr[i], j))
					missing += pow(2, j);

			}

			missing--;
		}

		prev_bit = returnBit(bs_arr[i], 0);

	}
	return missing;
}

int returnBit(int num, int pos){
	return (num >> pos) & 1;
}