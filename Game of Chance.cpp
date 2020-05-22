#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

srand(time(NULL));
class GameController
{
	private: 
		int betMoney;
		int remainingMoney;
	public:
		void betMoney(money)
		{
			if(remainingMoney<money)
				throw "Insufficient money";
			else
				remainingMoney-=money;			
		}
};

class Player:public GameController
{
	private:
		int Sum;
	public:
		void 
};

class Computer:public GameController
{
	private:
		int Sum;
		
};

class Deck:public GameController
{
	private:
		int DeckSize=52;
			
	public:
		void CheckDeck()
		{
			if(DeckSize==0)
			{
						
			}
		}
};

class DrawnCard:public Deck
{
	private:
		
	public:
		DrawnCard(int baseValue, std::string Suite)
		
};


int main()
{
	
	return(0);
}
