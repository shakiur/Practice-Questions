/*
Design a chess game using object oriented principles
*/

#include <iostream>
#include "headers/GameHandler.h"

void getNames(std::string&, std::string&);

int main(){

	GameHandler* gh = new GameHandler;

}

void getNames(std::string& name1, std::string& name2){
	std::cout << "Please enter names of 2 players:\n\n";

	std::cout << "Player 1: ";
	std::cin >> name1;

	std::cout << "Player 2: ";
	std::cin >> name2;

}