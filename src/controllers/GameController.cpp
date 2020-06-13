#include<iostream>
#include<cstdlib>
#include<ctime>
#include "GameController.h"
#include "Computer.h"
#include "Player.h"
#include "../models/Deck.h"


using namespace std;
GameController::GameController(){
}

GameController::~GameController() {
}

int GameController::start(int option)
{
	switch (option) {
		case 1:
		{
			return 1;
		}
		case 2:
		{
			return 2;
		}
		case 3:
		{
			return 3;
		}
		default:
		{
			return 0;
		}
	}
}

int GameController::deal(Player* p, Computer* c, Deck* d)
{
	if (d->remainingCards == 0){
		return 0;
	}
	else {
		p->player_Card = d->top->at(d->remainingCards - 1);
		++p->playerCard_pile;
		--d->remainingCards;
		c->computer_Card = d->top->at(d->remainingCards - 1);
		++c->computerCard_pile;
		--d->remainingCards;
	}
}

void GameController::shuffle(Deck * d)
{
	srand(time(NULL));
	for (int i = 0; i < 2704; i++){
		int Index1 = rand() % 52;//chooses a random number from 0 to 51, since the array starts from index 0 to 51. 
		int Index2 = rand() % 52;
		if (Index1 != Index2){
			Card temp = d->top->at(Index1);//Making a temporary variable to store the data at Index1 before initializing Index1 to Index2's value.
			d->top->at(Index1) = d->top->at(Index2);
			d->top->at(Index2) = temp;
		}
	}
}

int GameController::wageWinner(Player * p, Computer * c)
{
	if (p->player_Card.get_baseValue() < c->computer_Card.get_baseValue()){
		return 1;
	}
	else if (p->player_Card.get_baseValue() > c->computer_Card.get_baseValue()){
		return 2;
	}
	else{
		return 3;
	}
}