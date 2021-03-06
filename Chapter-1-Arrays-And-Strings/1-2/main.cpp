// Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
// five characters, including the null character.)

#include <iostream>

using namespace std;

void reverseChar(char[], int);

int main(){
	char x[] = "Hell";
	
	std::cout << x << std::endl;
	reverseChar(x, 4);
	std::cout << x << std::endl;
}

void reverseChar(char c[], int length){

	int begin = 0;
	int end = length-1;

	while(end > begin) {

		char temp = c[begin];
		c[begin] = c[end];
		c[end] = temp;

		begin++;
		end--;

	}

}