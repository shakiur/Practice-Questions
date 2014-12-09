/*
Write a method to compute all permutations of a string
*/
#include <iostream>

void computePerm(std::string);

void calcPerm(std::string, std::string, bool*);

int main(){
	computePerm("abc");
}

void computePerm(std::string orig){
	std::string temp;
	bool* hold_char = new bool[temp.length()];

	// Initialize array to false
	for(int i = 0; i < orig.size(); i++){
		hold_char[i] = false;
	}

	calcPerm(orig, temp, hold_char);
}

void calcPerm(std::string orig, std::string temp, bool* hold_char){
	if(temp.length() == orig.length()){
		std::cout << temp << std::endl;
	}
	else{
		for(int i = 0; i < orig.size(); i++){

			if(hold_char[i] == false){
				hold_char[i] = true;
				
				// Add non-visited letter to temp word
				temp += orig[i];

				calcPerm(orig, temp, hold_char);

				temp = temp.substr(0, temp.size()-1);
				hold_char[i] = false;


			}

		}
	}
}