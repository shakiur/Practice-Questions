/*
Given an image represented by an NxN matrix, where each pixel in the image is 4 
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>

using namespace std;

// Create 2D Array based off height and width
char ** createArray(int, int);

// Add letters to 2D array to create "image"
void addLetters(char**);

// Display the 2D array
void displayArr(char**, int, int);

// Rotate the 2D array by 90 degrees
void rotateArr(char**&, int, int);

int main(){

	int height = 4;
	int width = 4;

	char ** arr = createArray(height, width);
	addLetters(arr);

	cout << "\n===OLD ARRAY===\n";
	displayArr(arr, height, width);

	rotateArr(arr, height, width);

	cout << "\n===NEW ARRAY===\n";
	displayArr(arr, height, width);


}

char ** createArray(int h, int w){
	
	char ** arr = new char*[h];

	// Create 2D Array
	for(int i = 0; i < h; i++){
		arr[i] = new char[w];
	}

	// Load array with 'X'
	for(int x = 0; x < h; x++){
		for(int y = 0; y < w; y++)
			arr[x][y] = 'X';
	}



	return arr;
}

void addLetters(char** arr){
	arr[1][0] = 'A';
	arr[1][3] = 'B';
	arr[2][0] = 'C';
	arr[2][3] = 'D';
}

void displayArr(char** arr, int h, int w){

	for(int x = 0; x < h; x++){
		for(int y = 0; y < w; y++)
			cout << arr[x][y] << ' ';
		cout << endl;
	}
}

void rotateArr(char**& arr, int h, int w){

	// Create new 2D array to hold rotated image
	char ** new_arr = createArray(h, w);

	// Add letters to new_arr based of old arr
	for(int x = 0; x < h; x++){
		for(int y = 0; y < w; y++)
			new_arr[y][(h-1)-x] = arr[x][y];
	}

	// Delete all elements from original arr
	for(int x = 0; x < h; x++){
			delete arr[x];
	}

	arr = new_arr;

}