#ifndef GAMECONTROLLER_HEADER
#define GAMECONTROLLER_HEADER


#include "Player.h"
#include "Computer.h"
#include "../models/Deck.h"

class GameController
{
	public:
		GameController();
		~GameController();
		int start(int option);
		int deal(Player *p, Computer *c,Deck *d);
		void shuffle(Deck *d);
		int wageWinner(Player *p, Computer *c);
};
#endif