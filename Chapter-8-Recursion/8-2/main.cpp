/*
Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can
only move in two directions: right and down. How many possible paths are there for
the robot?
FOLLOW UP
Imagine certain squares are “off limits”, such that the robot can not step on them.
Design an algorithm to get all possible paths for the robot.
*/
#include <iostream>

int findPaths(int, int, int);

int main(){
	int n = 4;

	std::cout << findPaths(n, 0, 0);
}

int findPaths(int n, int x, int y){
	// If x or y dimension has gone past length of grid, 
	// then it is a complete path
	if(x > (n-1))
		return 1;
	else if(y > (n-1))
		return 1;
	else
		return findPaths(n, x+1, y) + findPaths(n, x, y+1);
}