// Implement an algorithm to determine if a string has all unique characters. What if you
// can not use additional data structures?

#include <iostream>

using namespace std;

const int ASCII_SIZE = 128;

bool allUnique(string);

bool allUniqueNoAddlStruct(string);

int main() {

}

bool allUnique(string s){

	int * char_count = new int[ASCII_SIZE];
	int len = s.length();

	// Set char_count array to 0
	for(int i = 0; i < ASCII_SIZE; i++){
		char_count[i] = 0;
	}

	for(int i = 0; i < len; i++){
		char_count[int(s[i])]++;

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