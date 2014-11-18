#ifndef JUKEBOX_H
#define JUKEBOX_H

#include <vector>
#include <queue>
#include "Song.h"

class JukeBox{
	std::vector<Song*> all_songs;
	std::queue<Song*> playlist;

	public:
		JukeBox() {}
		void addSong(Song* s){
			all_songs.push_back(s);
		}

		void displayAllSongs(){
			for(int i = 0; i < all_songs.size(); i++){
				std::cout << i+1 << ". " << all_songs[i]->getArtist()
						  << " - \"" << all_songs[i]->getTitle()
						  << "\" " << all_songs[i]->getLength()
						  << " sec\n";
			}


		}

		bool addToPlaylist(int pos){
			if(pos > all_songs.size()-1)
				return false;
			else{
				playlist.push(all_songs[pos]);
			}
		}

		void play(){
			while(!playlist.empty()){
				playlist.front()->playSong();
				playlist.pop();
			}
		}
};

#endif