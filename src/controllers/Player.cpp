#include "Player.h"

Player::Player(){
}

Player::~Player() {
}

int Player::wager(int wage, Player *p){
	if(p->pSum<wage){
		return 1;
	}

	else if(wage <= 0){
		return 2;
	}

	else{
		return 3;
	}
}

