#include "Player.h"

int Player::wager(int wage, Player *p){
	if(p->pSum<wage){
		return 1;
	}
	else if(wage <= 0)
	{
		return 2;
	}
	else{
	p->pSum-=wage;
	p->playerWage=wage;
	}
}
Player::Player()
{
}
