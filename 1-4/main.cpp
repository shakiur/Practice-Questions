/* 
/*
Write a method to decide if two strings are anagrams or not.
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int ASCII_SIZE = 128;

bool checkAnagram(string, string);

bool checkAnagramNoSort(string, string);

int main(){

}

bool checkAnagram(string str1, string str2){

	sort(str1.begin(), str1.end()); 
	sort(str2.begin(), str2.end());

	return str1 == str2;
}

bool checkAnagramNoSort(string str1, string str2){

	int len1 = str1.length();
	int len2 = str2.length();

	if(len1 != len2)
		return false;

	int char_count1[ASCII_SIZE];
	int char_count2[ASCII_SIZE];

	// Initialize arrays to 0
	for(int i = 0; i < ASCII_SIZE; i++){
		char_count1[i] = 0;
		char_count2[i] = 0;
	}

	// Populate both arrays with
	for(int i = 0; i < len1; i++){
		char_count1[int(str1[i])]++;
		char_count2[int(str2[i])]++;
	}

	// Check if both arrays match every letter
	// If not return false
	for(int i = 0; i < ASCII_SIZE; i++){
		if(char_count1[i] != char_count2[i])
			return false;
	}


	return true;
}