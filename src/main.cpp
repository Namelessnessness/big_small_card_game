#include<iostream>
#include "GameController.h"
#include "Computer.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
int main(int argc, char *argv[])
{
	GameController controller;
	Player p;
	Computer c;
	Deck d;
	
	int Option=1;
	cout<<"----------Big Small Card Game----------"<<endl
	<<"1) New Game"<<endl
	<<"2) View High Score"<<endl
	<<"3) Quit"<<endl;
	cin<<Option;
	int returnedValue=controller.start(Option);
	if(returnedValue==0)
	{
		return 0;
	}
	else if(returnedValue==1)
	{
		int Difficulty=0;
		cout<<"Select Difficulty:\n"
		<<"1) Easy(Starting sum is $1000)\n"
		<<"2) Normal(Starting sum is $500)\n"
		<<"3) Hard(Starting sum is $250)\n";
		cin>>Difficulty;
		switch(Difficulty)
		{
			case 1:
				p.pSum=1000;
			break;
			case 2:
				p.pSum=500;
			break;
			case 3:
				p.pSum=250;
			break;
		}
	}
	
	d.setDeck();
	controller.shuffle();	
	int wage=0;
	while(true)
	{
		if(p.pSum==0)
		{
			delete[]
			cout<<"You ran out of money! Game finished";
			return 0;
		}
		srand(time(NULL));
		cout<<"Cards Remaining: "<<d.RemainingCards<<endl
		<<"Account Balance: "<<p.pSum<<endl
		<<"How much would you like to wage on this hand?"<<endl
		<<"$";
		cin>>wage;
		returnedValue=p.wager(wage);
		if(returnedValue==1)
		{
			int newWage=0;
			cout<<"Insufficient money! Please give an appropriate value. Sum: "<<p.pSum<<endl;
			cin>>newWage;
			p.wager(newWage);
		}
		returnedValue=controller.deal();
		if(returnedValue==0)
		{
			cout<<"Deck ran out of cards! Game finished.\n Money:"<<p.pSum;
		}
		returnedValue=controller.wageWinner();
		switch(returnedValue)
		{
			case 1:
				
			break;
			case 2:
				p.pSum+=p.playerWage;
			break;				
			case 3:
				if(player_Card.get_suit<computer_Card.get_suit)
				{
					
				}
				if(player_Card.get_suit<computer_Card.get_suit)
				{
					
				}	
			break;	
		}	
	}
	return(0);
}
