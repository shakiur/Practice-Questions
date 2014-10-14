/*
Write a method to replace all spaces in a string with ‘%20’.
*/

#include <iostream>
#include <string>

using namespace std;

void replaceSpace(string&);

int main(){

}

void replaceSpace(string& str){

	int len = str.length();

	for(int i = 0; i < len; i++){
		if(str[i] == ' '){
			str = str.substr(0,i) + "%20" + str.substr(i+1,len);
		}
	}

}
