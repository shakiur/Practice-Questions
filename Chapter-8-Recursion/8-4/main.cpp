/*
Write a method to compute all permutations of a string
*/
#include <iostream>

void computePerm(std::string);

void calcPerm(std::string, std::string, bool*, int);

int main(){
	computePerm("abcd");
}

void computePerm(std::string orig){
	std::string temp;
	bool* hold_char = new bool[temp.length()];

	// Initialize array to false
	for(int i = 0; i < orig.size(); i++){
		hold_char[i] = false;
	}

	calcPerm(orig, temp, hold_char, 0);
}

void calcPerm(std::string orig, std::string temp, bool* hold_char){
	if(temp.length() == orig.length()){
		std::cout << temp << std::endl;
	}
	else{
		
	}
}