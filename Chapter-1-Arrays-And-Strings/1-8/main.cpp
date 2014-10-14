/*
Assume you have a method isSubstring which checks if one word is a substring of 
another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using 
only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

#include <iostream>

using namespace std;

bool checkRotation(string, string);

int main(){

	string str1 = "waterbottle";
	string str2 = "erbottlewat";

	if(checkRotation(str1, str2))
		cout << "Rotation is TRUE\n";
	else
		cout << "Rotation is FALSE\n";
}

bool checkRotation(string str1, string str2){

	// Double str2 so str1 will be a full substring within str2
	str2 = str2 + str2;

	int len1 = str1.length();
	int len2 = str2.length();

	int i = 0;
	int len2_count = 0;

	for(int j = 0; j < len2; j++){

		if(str1[i] == str2[j]) {

			for(int k = j; k < len2; k++){

				if(len2_count == len1-1){

					// Went through all of str1 and it matched
					return true;
				}
				else if(str1[i] == str2[k]){

					// Go to next element to see if it continues to match
					i++;
					len2_count++;
				}
				else{

					// Letter is different, reset counters
					i = 0;
					len2_count = 0;

					break;
				}

			}

		}

	}

	return false;

}