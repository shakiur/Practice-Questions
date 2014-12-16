/*
Implement the “paint fill” function that one might see on many image editing pro-
grams. That is, given a screen (represented by a 2 dimensional array of Colors), a
point, and a new color, fill in the surrounding area until you hit a border of that col-
or.’	
*/
#include <iostream>

char** createImage(int);

void displayImage(char**, int);

void colorIn(int, int, char**, char, int);

int main(){
	int size = 10;
	char** image = createImage(size);
	displayImage(image, size);

	colorIn(4, 5, image, '-', size);

	displayImage(image, size);
}

char** createImage(int size){
	char** image = new char*[size];

	for(int i = 0; i < size; i++){
		image[i] = new char[size];

		for(int j = 0; j < size; j++){
			image[i][j] = 'X';
		}
	}

	// Top
	image[2][2] = '-';
	image[2][3] = '-';
	image[2][4] = '-';
	image[2][5] = '-';
	image[2][6] = '-';
	image[2][7] = '-';

	// Left
	image[3][2] = '-';
	image[4][2] = '-';
	image[5][2] = '-';
	image[6][2] = '-';
	image[7][2] = '-';

	// Right
	image[3][7] = '-';
	image[4][7] = '-';
	image[5][7] = '-';
	image[6][7] = '-';
	image[7][7] = '-';

	// Bottom
	image[7][3] = '-';
	image[7][4] = '-';
	image[7][5] = '-';
	image[7][6] = '-';

	return image;
}

void displayImage(char** image, int size){

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << image[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void colorIn(int x, int y, char** image, char c, int size){
	if(x >= 0 && x < size && y >= 0 && y < size){
		if(image[y][x] != c){
			image[y][x] = c;
	
			colorIn(x+1, y, image, c, size);
			colorIn(x-1, y, image, c, size);
			colorIn(x, y+1, image, c, size);
			colorIn(x, y-1, image, c, size);
		}
	}
}