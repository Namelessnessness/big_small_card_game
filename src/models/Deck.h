#include<vector>
#ifndef DECK_H
#define DECK_H
#endif
#include "Card.h"
class Deck
{
	public:
		Deck();
		void setDeck(Deck *d);
		unsigned short remainingCards=52;
		std::vector<Card> *top = new std::vector<Card>(52);
		~Deck();
};
