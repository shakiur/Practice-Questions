/*
Given a sorted array of n integers that has been rotated an unknown number of
times, give an O(log n) algorithm that finds an element in the array. You may assume
that the array was originally sorted in increasing order.
EXAMPLE:
Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
Output: 8 (the index of 5 in the array)
*/
#include <iostream>

int binarySearch(int*, int, int, int);

int rotateBinarySearch(int*, int, int, int);

int main(){

	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

	std::cout << rotateBinarySearch(arr, 0, 12, 5) << std::endl;

}

int rotateBinarySearch(int* arr, int beg, int end, int val){
	while(end > beg){
		int mid = (beg + end)/2;

		std::cout << mid << std::endl;

		return 0;
	}
}

int binarySearch(int* arr, int beg, int end, int val){
	while(end > beg){
		int mid = (beg + end)/2;

		if(arr[mid] == val){
			return mid;
		}
		else if(val < arr[mid]){
			end = mid - 1;
		}
		else{
			beg = mid + 1;
		}
	}

	return -1;


}