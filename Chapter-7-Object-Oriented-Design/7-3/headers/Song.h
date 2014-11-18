#ifndef SONG_H
#define SONG_H

#include <thread>
#include <chrono>

class Song{
	std::string title;
	std::string artist;
	int length;

	public:
		Song(std::string n, std::string a, int l) : 
			title(n), artist(a), length(l) {}

		// Getters
		std::string getTitle() { return title; }
		std::string getArtist() { return artist; }
		int getLength() { return length; }

		void playSong(){
			std::cout << "Playing \"" << artist << " - " << title 
									  << "\"..." << std::endl;
			for(int i = length; i >= 0; i--){
				std::cout << i;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << std::endl;
			}
		}

};

#endif