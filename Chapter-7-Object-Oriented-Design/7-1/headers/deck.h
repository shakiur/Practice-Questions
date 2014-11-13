#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck{
	Card ** all_cards;

	public:
		Deck(int num = 52) {
			all_cards = new Card*[num];

			// Add cards for each suit
			for(int i = 0; i < 4; i++){
				Suit s;
				if(i == 0)
					s = club;
				else if(i == 1)
					s = spade;
				else if(i == 2)
					s = heart;
				else
					s = diamond;

				// For every suit add card of each value (Ace - King)
				for(int j = 0; j < 13; j++){
					all_cards[(i*13)+j] = new Card((j+1), s);
				}
			}
		}

		void showAllCards(){
			for(int i = 0; i < 52; i++){
				std::cout << "Card[" << i << "]: " << all_cards[i]->getSuit() << " " << all_cards[i]->getValue() << std::endl;
			}
		}
};

#endif