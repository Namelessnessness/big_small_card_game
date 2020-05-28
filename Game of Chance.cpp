#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

class GameController
{
	private: 
		int betMoney;
		int Sum=1000;
	public:
		int betMoney(int bet);
		void Draw();
		int getSum()
		{
			return Sum;
		}
};
	int betMoney(int bet)
		{
			if(Sum<bet)
				throw "Insufficient money";
			else
				Sum-=bet;			
		}
	void Draw()
	{
		
	}
class Player:public GameController
{
	private:
		  
	public:
		
};

class Computer:public GameController
{
	private:
		int Sum;
	
};

class Deck
{
	private:
		DeckSize;
	protected:
	
	public:
		void Shuffle();
		void CheckDeck();

	
	class Card
		{
		private:
			Card Deck[52]={
						   {1,"Clubs"} , {2,"Clubs"} , {3,"Clubs"} , {4,"Clubs",} , {5,"Clubs"} , {6,"Clubs"} , {7,"Clubs"} , {8,"Clubs"} , {9,"Clubs"} , {10,"Clubs"} , {11,"Clubs"} , {12,"Clubs"} , {13,"Clubs"}
						   {1,"Diamonds"} , {2,"Diamonds"} , {3,"Diamonds"} , {4,"Diamonds"} , {5,"Diamonds"} , {6,"Diamonds"} , {7,"Diamonds"} , {8,"Diamonds"} , {9,"Diamonds"} , {10,"Diamonds"} , {11,"Diamonds"} , {12,"Diamonds"} , {13,"Diamonds"}
						   {1,"Hearts"} , {2,"Hearts"} , {3,"Hearts"} , {4,"Hearts"} , {5,"Hearts"} , {6,"Hearts"}{7,"Hearts"} , {8,"Hearts"}{9,"Hearts"}{10,"Hearts"} , {11,"Hearts"} , {12,"Hearts"} , {13,"Hearts"}
						   {1,"Spades"} , {2,"Spades"} , {3,"Spades"} , {4,"Spades"} , {5,"Spades"} , {6,"Spades"} , {7,"Spades"} , {8,"Spades"} , {9,"Spades"} , {10,"Spades"} , {11,"Spades"} , {12,"Spades"} , {13,"Spades"}
						  };
	public:	
		int baseValue;
		std::string Suite;
		Card(int baseValue, std::string Suite)
		{
			this->baseValue=baseValue;
			this->Suite=Suite;
		}
		
};

};
	srand(time(NULL));
    void Deck::Shuffle()
    {
		
    	for(int i=0;i<2704;i++)
    	{
    		Index1=rand()%52;//chooses a random number from 0 to 51, since the array starts from index 0 to 51. 
    		Index2=rand()%52;
			if( Index1 != Index2 )
			{
				Card temp=Deck[Index1];//Making a temporary variable to store Index1's value before initializing Index1 to Index2's value.
				Deck[Index1]=Deck[Index2];
				Index2=temp;
				Deck[Index2]=temp;
			}
		}	
	}
	
	void Deck::CheckDeck()
		{
			if(DeckSize==0)
			{
				
			}
		}

int main()
{
	
	
	return(0);
}
