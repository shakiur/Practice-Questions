/*
Implement an algorithm to print all valid (e.g., properly opened and closed) combi-
nations of n-pairs of parentheses.
EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))
*/
#include <iostream>

void printCombos(int);

void findValidCombo(std::string, int, int);

int main(){
	printCombos(3);
}

void printCombos(int n){
	int left_p(n);
	int right_p(n);
	std::string temp;

	findValidCombo(temp, left_p, right_p);

}

void findValidCombo(std::string temp, int left_p, int right_p){
	if(temp.size() == (left_p + right_p)){
		std::cout << temp;
	}
	else {

	}
}