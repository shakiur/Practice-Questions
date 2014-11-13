#ifndef CARD_H
#define CARD_H

#include <string>
enum Suit{club = 1, spade = 2, heart = 3, diamond = 4 };

class Card{
	int value;
	Suit suit;

	public:
		Card(int v, Suit s) : value(v), suit(s) {}
		int getValue() { return value; }
		Suit getSuit() { return suit; }
};

#endif