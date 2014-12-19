/*
Write a method to sort an array of strings so that all the anagrams are next to each
other.
*/
#include <iostream>

// Sorts a word by letter
void mergeSortWord(std::string&, int, int);
void mergeWord(std::string&, int, int, int, int);

// Sorts an array of strings alphabetically w/ anagrams next to each other
void mergeSortList(std::string*, int, int);
void mergeList(std::string*, int, int, int, int);

// Checks if string1 is alphabetically less than string2
bool compareWord(std::string, std::string);

// Display array
void display_arr(std::string*, int);

int main(){

	int size = 5;
	std::string arr[5] = {"def", "abc", "ghi", "cab", "hig"};

	std::string word = "qwekdfmcxzv";
	mergeSortWord(word, 0, word.size()-1);
	std::cout << word << std::endl;

	mergeSortList(arr, 0, size - 1);
	display_arr(arr, size);

}

void mergeSortList(std::string* list, int beg, int end){
	if(end > beg){
		int mid = (beg + end)/2;

		mergeSortList(list, beg, mid);
		mergeSortList(list, mid + 1, end);
		mergeList(list, beg, mid, mid + 1, end);
	}
}

void mergeList(std::string* list, int beg1, int end1, int beg2, int end2){

	/*
	// Debug
	std::cout << "list[" << beg1 << "]: " << list[beg1] << std::endl;
	std::cout << "list[" << end1 << "]: " << list[end1] << std::endl;
	std::cout << "list[" << beg2 << "]: " << list[beg2] << std::endl;
	std::cout << "list[" << end2 << "]: " << list[end2] << std::endl;
	*/

	std::string * new_list = new std::string[(end2 - beg1) + 1];

	int pos = 0;
	int size = (end2 - beg1) + 1;

	int init_beg1 = beg1;

	while(pos < size){
		std::string temp_beg1 = list[beg1];
		std::string temp_beg2 = list[beg2];

		mergeSortWord(temp_beg1, 0, temp_beg1.size()-1);
		mergeSortWord(temp_beg2, 0, temp_beg2.size()-1);

		if(beg1 <= end1 && beg2 <= end2){
			// Both halves of array have not been fully visited
			if(compareWord(temp_beg1, temp_beg2)){
				new_list[pos] = list[beg1];
				beg1++;
			}
			else{
				new_list[pos] = list[beg2];
				beg2++;
			}
		}
		else if(beg1 > end1 && beg2 <= end2){
			// First half of array has been visited, only grab from array 2
			new_list[pos] = list[beg2];
			beg2++;
		}
		else{
			// Second half of array has been visited, only grab from array 1
			new_list[pos] = list[beg1];
			beg1++;
		}
		pos++;
	}

	// Replace original array with new array
	for(int i = 0; i < size; i++, init_beg1++){
		list[init_beg1] = new_list[i];
	}
	
}


bool compareWord(std::string word1, std::string word2){
	
	int pos = 0;
	int max_pos;

	if(word1.size() < word2.size())
		max_pos = word1.size();
	else
		max_pos = word2.size();

	while(pos < max_pos){
		if(int(word1[pos]) > int(word2[pos]))
			return false;
		pos++;
	}

	return true;

}

void mergeSortWord(std::string& word, int beg, int end){
	if(end > beg){
		int mid = (beg + end)/2;

		mergeSortWord(word, beg, mid);
		mergeSortWord(word, mid + 1, end);
		mergeWord(word, beg, mid, mid + 1, end);
	}


}


void mergeWord(std::string& word, int beg1, int end1, int beg2, int end2){

	std::string new_word;

	int pos = 0;
	int size = (end2 - beg1) + 1;

	int init_beg1 = beg1;

	// Go through each letter in both halves until entire new word is organized
	while(pos < size){
		if(beg1 <= end1 && beg2 <= end2){
			// Both halves are not completely visited
			if(int(word[beg1]) < int(word[beg2])){
				new_word += word[beg1];
				beg1++;
			}
			else{
				new_word += word[beg2];
				beg2++;
			}
		}
		else if(beg1 > end1 && beg2 <= end2){
			// Word 1 has been completely visited, only use word 2
			new_word += word[beg2];
			beg2++;
		}
		else{
			// Word 2 has been completely visited, only use word 1
			new_word += word[beg1];
			beg1++;
		}
		pos++;
	}

	word = word.substr(0, init_beg1) + new_word + word.substr(end2+1);

}

void display_arr(std::string* arr, int size){
	for(int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}