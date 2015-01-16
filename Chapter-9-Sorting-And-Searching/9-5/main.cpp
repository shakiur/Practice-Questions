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


}

int binarySearchStringArr(std::string* arr, int end, std::string needle){

	int beg = 0;

	while(beg <= end){

		int mid = (beg + end)/2;

		if(arr[mid] == needle){
			return mid;
		}
		else if(arr[beg] == ""){
			beg++;
		}
		else if(arr[end] == ""){
			end--;
		}
		else if(arr[mid] == ""){
			// Figure out case if arr[mid] is "" because then you cant compare it
		}
			
	}

	return -1;

}
		


bool isStringLessThan(std::string word1, std::string word2){
	int pos1 = 0;
	int pos2 = 0;

	while(pos1 < word1.size() && pos2 < word2.size()){

		if( int(word1[pos1]) < int(word2[pos2]) )
			return true;

		pos1++;
		pos2++;
	}

	if(pos1 == word1.size())
		return true;
	else
		return false;
}