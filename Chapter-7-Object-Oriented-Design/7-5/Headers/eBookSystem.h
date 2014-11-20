#ifndef EBOOKSYSTEM_H
#define EBOOKSYSTEM_H

#include <vector>
#include "eBook.h"
#include "User.h"

class eBookSystem{

	std::vector<eBook*> all_books;
	std::vector<User*> all_users;

	public:
		eBookSystem();
		void addBook();
		void addUser();
		void login();

		void run();

};

eBookSystem::eBookSystem(){
	// Add books
	all_books.push_back(new eBook(	"JK Rowling", 
									"Harry Potter", 
									1998, 
									313, 
									15.98,
									"There was a boy who lived.\n"));

	all_books.push_back(new eBook(	"Neil Gailman", 
									"American Gods", 
									2003, 
									450, 
									8.95,
									"This is a story about Gods.\n"));

	all_books.push_back(new eBook(	"Jonathan Foer", 
									"Everything Is Illuminated", 
									2005, 
									289, 
									9.98,
									"Three stories in one.\n"));

	// Add Users
	all_users.push_back(new User("Jack", "Jack123"));
	all_users.push_back(new User("Bill", "Bill123"));
	all_users.push_back(new User("Todd", "Todd123"));

}

void eBookSystem::addBook(){
	std::string title;
	std::string author;
	int year;
	int pages;
	double cost;

	std::string text;

	std::cout << "Enter Author: ";
	std::cin >> author;

	std::cout << "Enter Title: ";
	std::cin >> title;

	std::cout << "Enter Year: ";
	std::cin >> year;

	std::cout << "Enter Total Pages: ";
	std::cin >> pages;

	std::cout << "Enter Cost: ";
	std::cin >> cost;

	std::cout << "Enter Text: ";
	std::cin >> text;

	all_books.push_back(new eBook(author, title, year, pages, cost, text));

}

void eBookSystem::addUser(){
	std::string username;
	std::string password;

	std::cout << "Enter Username: ";
	std::cin >> username;

	std::cout << "Enter Password: ";
	std::cin >> password;

	all_users.push_back(new User(username, password));
}

void eBookSystem::login(){
	std::string username;
	std::string password;
	int found = -1;

	std::cout << "Enter Username: ";
	std::cin >> username;

	std::cout << "Enter Password: ";
	std::cin >> password;

	// Find if username is valid
	for(int i = 0; i < all_users.size(); i++){
		if(all_users[i]->getUsername() == username){
			found = i;
		}
	}

	if(found != -1){
		if(all_users[found]->checkPassword(password)){
			std::cout << "Successful Login!\n\n";
		}
		else{
			std::cout << "Incorrect Password!\n\n";
		}
	}
	else{
		std::cout << "NO Member Found!\n\n";
	}
}

void eBookSystem::run(){
	int selection;

	do{
		std::cout << "Please Select The Following:\n\n";
		std::cout << "1. Add New Book\n";
		std::cout << "2. Add New user\n";
		std::cout << "3. Login\n";
		std::cout << "4. Exit\n\n";

		std::cout << "Enter Selection: ";
		std::cin >> selection;

		switch(selection)
		{
			case 1:
				addBook();
				break;
			case 2:
				addUser();
				break;
			case 3:
				login();
				break;
			case 4:
				return;
			default:
				std::cout << "Invalid Selection\n";
				return;
		}
	}
	while(selection != 4);
}
#endif