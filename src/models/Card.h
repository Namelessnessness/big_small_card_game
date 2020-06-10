#ifndef CARD_H
#define CARD_H
#endif
class Card
{
	private:
		int baseValue;
		int suit;
	public: 
		int get_baseValue();
		int get_suit();
		enum suit{CLUBS=1,DIAMONDS,HEARTS,SPADES};
		Card(int suit, int baseValue);
		Card();
		static Card *top;
};	
