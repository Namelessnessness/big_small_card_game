#ifndef CARD_HEADER
#define CARD_HEADER


class Card
{
	private:
		int baseValue;
		int suit;
	public: 
		Card(int suit, int baseValue);
		Card();
		int get_baseValue();
		int get_suit();
		enum suit{CLUBS=1,DIAMONDS,HEARTS,SPADES};
		static Card *top;
};	
#endif