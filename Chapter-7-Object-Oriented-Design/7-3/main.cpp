/*
Design a musical jukebox using object oriented principles
*/

#include <iostream>
#include "headers/JukeBox.h"

JukeBox* buildJukeBox();

int main(){
	JukeBox* j = buildJukeBox();
	j->displayAllSongs();
	j->play();
}

JukeBox* buildJukeBox(){
	JukeBox* j = new JukeBox;
	j->addSong(new Song("Fake Plastic Trees", "Radiohead", 5));
	j->addSong(new Song("Down and out", "Cam'ron", 4));
	j->addSong(new Song("All falls down", "Kanye West", 7));
	j->addSong(new Song("New Slang", "The Shins", 9));

	j->addToPlaylist(3);
	j->addToPlaylist(0);

	return j;
}