/*
Implement an algorithm to print all valid (e.g., properly opened and closed) combi-
nations of n-pairs of parentheses.
EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))
*/
#include <iostream>

void printCombos(int);

void findValidCombo(std::string, int, int, int);

int main(){
	printCombos(3);
}

void printCombos(int n){
	int left_p(n);
	int right_p(n);
	std::string temp;

	findValidCombo(temp, left_p, right_p, n);

}

void findValidCombo(std::string temp, int left_p, int right_p, int n){
	if(temp.size() == (n*2)){
		std::cout << temp << std::endl;
	}
	else {
		// Add left parenthesis
		if(left_p > 0){
			temp += "(";
			left_p--;
			findValidCombo(temp, left_p, right_p, n);
		}

		// Add right parenthesis
		if(right_p > 0){
			temp += ")";
			right_p--;
			findValidCombo(temp, left_p, right_p, n);
		}
	}
}