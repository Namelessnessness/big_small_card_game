#ifndef DECK_HEADER
#define DECK_HEADER


#include<vector>
#include "../models/Card.h"

class Deck
{
	public:
		Deck();
		~Deck();
		void setDeck(Deck *d);
		unsigned short remainingCards=52;
		std::vector<Card> *top = new std::vector<Card>(52);
		
};
#endif