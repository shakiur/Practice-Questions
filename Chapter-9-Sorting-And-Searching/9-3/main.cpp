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

	/*
	for(int i = 1; i < 10; i++){
		std::cout << "Val " << i << ": " << binarySearch(arr, 0, 9, i) << std::endl;
	}
	*/

	//std::cout << binarySearch(arr, 0, 9, 4) << std::endl;

	/*
	for(int i = 1; i < 13; i++){
		std::cout << "Val " << i << ": " << rotateBinarySearch(arr2, 0, 13, i) << std::endl;
	}
	*/
	
	rotateBinarySearch(arr2, 0, 12, 1);
}

int rotateBinarySearch(int* arr, int beg, int end, int val){
	while(end >= beg){
		int mid = (beg + end)/2;

		std::cout << "Val: " << val << std::endl;
		std::cout << "Arr[" << mid << "]: " << arr[mid] << std::endl;
		std::cout << "Beg: " << beg << std::endl;
		std::cout << "Mid: " << mid << std::endl;
		std::cout << "End: " << end << std::endl << std::endl;

		if(arr[mid] == val){
			//std::cout << "Return " << mid << std::endl;
			return mid;
		}
		else if(arr[beg] > arr[end]){
			// Rotating portion found, figure out what to do
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

int binarySearch(int* arr, int beg, int end, int val){
	while(end >= beg){
		int mid = (beg + end)/2;

		/*
		std::cout << "Val: " << val << std::endl;
		std::cout << "Arr[" << mid << "]: " << arr[mid] << std::endl;
		std::cout << "Beg: " << beg << std::endl;
		std::cout << "Mid: " << mid << std::endl;
		std::cout << "End: " << end << std::endl << std::endl;
		*/

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