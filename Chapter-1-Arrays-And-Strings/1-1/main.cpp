// Implement an algorithm to determine if a string has all unique characters. What if you
// can not use additional data structures?

#include <iostream>

using namespace std;

const int ASCII_SIZE = 128;

bool allUnique(string);

bool allUniqueNoAddlStruct(string);

int main() {

	string s = "abcdb";

	if(allUnique(s))
		cout << s << " is all unique\n";
	else
		cout << s << " is not all unique\n";
}

bool allUnique(string s){

	// Holds which characters have been visited (only 128 chars in regular Ascii)
	int char_count[ASCII_SIZE] = {0};
	int len = s.length();

	for(int i = 0; i < len; i++){
		char_count[int(s[i])]++;

		// If character count is greater than 1, then it already exists in string
		if(char_count[int(s[i])] > 1)
			return false;
	}

	return true;
}

bool allUniqueNoAddlStruct(string s){

	int len = s.length();

	for(int i = 0; i < len; i++) {

		for(int j = (i+1); j < len; j++) {

			if(s[i] == s[j])
				return false;

		}
	}

	return true;

}