#include<iostream>
#include<cstdlib>
#include<ctime>
#include "GameController.h"
#include "Computer.h"
#include "Player.h"
#include "Deck.h"


using namespace std;

GameController::GameController()
{
}

int GameController::start(int option)
{
	switch(option)
	{
		case 1:
			{
			return 1;
			}
		case 2:
			{
			int nextOption=0;
			cout<<highScore<<endl;
			cout<<"Next option: ";
			cin>>nextOption;
			start(nextOption);
			break;		
			}
		case 3:
			{
			return 0;
			break;
			}
		default:
			{
			int nextOption=0;
			cout<<"Invalid option! Please enter an option from 1-3.\n Next option: ";
			cin>>nextOption;
			start(nextOption);
			break;		
			}
	}
}

int GameController::deal()
{
	if(remainingCards==0)
	{
		return 0;
	}
	else if(playerCard_pile==computerCard_pile)
	{
		player_Card=*top;
		++playerCard_pile;
		--remainingCards;
	}
	else
	{
		computer_Card=*top;
		++computerCard_pile;
		--remainingCards;
	}
}

void GameController::shuffle()
{
   	for(int i=0;i<2704;i++)
   	{
   		int Index1=rand()%52;//chooses a random number from 0 to 51, since the array starts from index 0 to 51. 
   		int Index2=rand()%52;
		if( Index1 != Index2 )
		{
			Card temp=Deck[Index1];//Making a temporary variable to store the data at Index1 before initializing Index1 to Index2's value.
			Deck[Index1]=Deck[Index2];
			Index2=temp;
			Deck[Index2]=temp;
		}
	}
}

void GameController::wageWinner()
{
	if(get_baseValue<computer_Card.get_baseValue)
	{
		return 1;
	}
	else if(player_Card.get_baseValue>computer_Card.get_baseValue)
	{
		return 2;
	}
	else
	{
		return 3;			
	}
}
