#ifndef USER_H
#define USER_H

#include <vector>

class User{
	std::string username;
	std::string password;

	std::vector<eBook*> collection;

	double money;

	public:
		// Constructors
		User(std::string u, std::string p) : username(u), password(p), money(20.00) {}

		// Getters
		std::string getUsername() { return username; }
		double getMoney() { return money; }

		// Setters
		void setUsername(std::string u) { username = u; }
		void setPassword(std::string p) { password = p; }

		bool checkPassword(std::string p) { return p == password; }

		void addBook(eBook* eb) { collection.push_back(eb); }
		void addMoney(double m) { money += m; }
		void subtractMoney(double m) {money -= m; }

		void browseCollection(){
			int select = 0;

			while(select != -1){
				std::cout << "Book Collection:\n";

				for(size_t i = 0; i < collection.size(); i++){
					std::cout << i << ". \"" 
							  << collection[i]->getTitle() << "\" by "
							  << collection[i]->getAuthor() << "\n";
				}

				std::cout << "Enter -1 to Exit\n\n";
				std::cout << "Enter Selection: ";

				std::cin >> select;

				std::cout << collection[select]->getText() << std::endl;

			}
		}
};

#endif