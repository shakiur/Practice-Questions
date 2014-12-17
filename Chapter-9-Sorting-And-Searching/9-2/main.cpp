/*
Write a method to sort an array of strings so that all the anagrams are next to each
other.
*/
#include <iostream>

std::string mergeSortWord(std::string&, int, int);

std::string mergeWord(std::string&, int, int, int, int);

int main(){

	std::string arr[5] = {"abc", "def", "ghi", "cab", "hig"};

}


std::string mergeSortWord(std::string& word, int beg, int end){
	if(end > beg){
		int mid = (beg + end)/2;

		mergeSortWord(word, beg, mid);
		mergeSortWord(word, mid + 1, end);
		mergeWord(word, beg, mid, mid + 1, end);
	}


}


std::string mergeWord(std::string& word, int beg1, int end1, int beg2, int end2){

	std::string new_word;
	int pos = 0;


}