#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "../models/Card.h"

class Player
{
	public:
		Player();
		~Player();
		Card player_Card;
		int playerCard_pile=0;//Number of times a card was dealt to Player.
		int pSum=0;
		int highScore=0;
		int playerWage=0;		
		int wager(int wage,Player *p);
};
#endif 