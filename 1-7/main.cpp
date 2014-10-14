/*
Write an algorithm such that if an element in an MxN matrix is 0, 
its entire row and column is set to 0.
*/

#include <iostream>

using namespace std;

// Allocate memory for new 2d array
char ** buildArr(int);

// Display the 2D array
void displayArr(char**, int);

// Convert rows and columns to 0
void convertRowCol(char**&, int);

int main(){

	const int n = 10;

	char ** arr = buildArr(n);

	arr[1][2] = '0';
	arr[6][7] = '0';

	cout << "\n===Old 2D Array===\n";
	displayArr(arr, n);

	convertRowCol(arr, n);

	cout << "\n===New 2D Array===\n";
	displayArr(arr, n);

}

char ** buildArr(int n){

	// Allocate new memory for 2d array
	char ** arr = new char*[n];

	for(int i = 0; i < n; i++){
		arr[i] = new char[n];
	}

	// Set all values in 2d array to 'X'
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			arr[x][y] = 'X';
		}
	}

	return arr;

}

void displayArr(char** arr, int n){

	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++)
			cout << arr[x][y] << ' ';
		cout << endl;
	}
}

void convertRowCol(char**& arr, int n){

	// Arrays to hold which row/column to convert
	bool * row = new bool[n];
	bool * column = new bool[n];

	// Initialize both arrays to false
	for(int i = 0; i < n; i++){
		row[i] = false;
		column[i] = false;
	}

	// Go through 2d array
	// If '0' is found, set row and column to true
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(arr[x][y] == '0'){
				row[x] = true;
				column[y] = true;
			}
		}
	}

	// Go through array, if row or column is true then set
	// arr to '0'
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			if(row[x] || column[y])
				arr[x][y] = '0';
		}
	}
}