#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#endif
#include "Player.h"
#include "Computer.h"
#include "Deck.h"
class GameController
{
	public:
		GameController();
		int start(int option);
		int deal(Player *p, Computer *c,Deck *d);
		void shuffle(Deck *d);
		int wageWinner(Player *p, Computer *c);
};
