/*
Write a method to sort an array of strings so that all the anagrams are next to each
other.
*/
#include <iostream>

void mergeSortWord(std::string&, int, int);

void mergeWord(std::string&, int, int, int, int);

int main(){

	std::string arr[5] = {"abc", "def", "ghi", "cab", "hig"};

	std::string word = "cabhvnm";

	mergeSortWord(word, 0, word.size()-1);

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