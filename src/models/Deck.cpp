#include "Deck.h"

Deck::~Deck()
{
}
void Deck::setDeck(Deck *d){
	int x=0;
	for(int i=0;i<13;++i)
	{
		d->top->at(x) = {Card::CLUBS,i+2};
		++x;
		d->top->at(x) = {Card::DIAMONDS,i+2};
		++x;
		d->top->at(x) = {Card::HEARTS,i+2};
		++x;
		d->top->at(x) = {Card::SPADES,i+2};
		++x;
	}
}
Deck::Deck(){
}

