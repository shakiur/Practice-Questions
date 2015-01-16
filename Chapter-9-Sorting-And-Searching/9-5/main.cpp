/*
Given a sorted array of strings which is interspersed with empty strings, write a method
to find the location of a given string.
Example: find “ball” in [“at”, “”, “”, “”, “ball”, “”, “”, “car”, “”, “”, “dad”, “”, “”] will return 4
Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”, “dad”, “”, “”] will return -1
*/
#include <iostream>

int binarySearchStringArr(std::string*, int, std::string);

bool isStringLessThan(std::string, std::string);

int main(){
	std::string arr1[13] = {"at", "","","","ball","","","car","","","dad","",""};
	std::string arr2[12] = {"at", "", "", "", "", "ball", "car", "", "", "dad", "", ""};

	std::cout << binarySearchStringArr(arr1, 12, "ball") << std::endl;
	std::cout << binarySearchStringArr(arr1, 11, "ballcar") << std::endl;

	/*
	std::string test1 = "e";
	std::string test2 = "cat";

	if(isStringLessThan(test1, test2))
		std::cout << test1 << " is less than " << test2 << "\n";
	else
		std::cout << test1 << " is greater than " << test2 << "\n";
	*/
}

int binarySearchStringArr(std::string* arr, int end, std::string needle){

	int beg = 0;
	int diff = 1;
	bool pos_diff = true;

	int mid = (beg + end)/2;

	while(beg <= end){
		
		/*
		// DEBUG INFO
		std::cout << "Val: " << needle << std::endl;
		std::cout << "Beg[" << beg << "]: " << arr[beg] << std::endl;
		std::cout << "Mid[" << mid << "]: " << arr[mid] <<std::endl;
		std::cout << "End[" << end << "]: " << arr[end] <<std::endl << std::endl;
		*/

		if(arr[mid] == needle){
			return mid;
		}
		else if(arr[beg] == ""){
			beg++;

			mid = (beg + end)/2;
		}
		else if(arr[end] == ""){
			end--;

			mid = (beg + end)/2;
		}
		else if(arr[mid] == ""){
			// Keep searching left/right until non-blank is found
			if(pos_diff){
				mid = mid + diff;
				diff++;

				pos_diff = false;
			}
			else{
				mid = mid - diff;
				diff++;

				pos_diff = true;
			}
		}
		else if(isStringLessThan(needle, arr[mid])){
			end = mid - 1;

			mid = (beg + end)/2;
		}
		else{
			beg = mid + 1;

			mid = (beg + end)/2;
		}
			
	}

	return -1;

}
		


bool isStringLessThan(std::string word1, std::string word2){
	int pos1 = 0;
	int pos2 = 0;

	while(pos1 < word1.size() && pos2 < word2.size()){

		if( int(word1[pos1]) > int(word2[pos2]) ){
			// Current word1 letter is greater
			return false;
		}
		else if( int(word1[pos1]) < int(word2[pos2])){
			// Current word1 letter is less
			return true;
		}
		else{
			// Both letters are equal
			pos1++;
			pos2++;
		}
	}

	// Word 1 is exact same as word2 except shorter, so its less
	if(pos1 == word1.size())
		return true;
	else
		return false;
}