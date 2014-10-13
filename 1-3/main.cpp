/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer. NOTE: One or two additional variables are fine.
An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.
*/

#include <iostream>

using namespace std;

void removeDupe(string&);

int main(){

}

void removeDupe(string& str) {

	int len = str.length();

	for(int i = 0; i < len; i++) {

		for(int j = (i+1); j < len; j++) {

			// Repeat character is found
			while(str[i] == str[j]){

				// Shift characters over
				for(int k = j; k < len; k++) {
					str[k] = str[k+1];
				}

				// Decrease length so blank characters aren't checked
				len--;

			}			

		}

	}


}