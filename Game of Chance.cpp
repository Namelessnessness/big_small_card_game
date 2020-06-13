#include<cstdlib>
#include<ctime>
#include<iostream>
#include <vector>
using namespace std;

class Card
{
	private:
		int baseValue;
		int suit;
	public: 
		int get_baseValue();
		int get_suit();
		enum suit{CLUBS=1,DIAMONDS,HEARTS,SPADES};
		Card(int suit, int baseValue);
		Card();
		static Card *top;
};	
Card::Card(int suit, int baseValue)
 : suit(suit) ,baseValue(baseValue){
   }
Card::Card()
: suit(0),baseValue(0){
	Card(suit,baseValue);
}
int Card::get_baseValue(){
	return baseValue;
}
int Card::get_suit(){
	return suit;
}


class Deck
{
	public:
		Deck();
		void setDeck(Deck *d);
		unsigned short remainingCards=52;
		std::vector<Card> *top = new std::vector<Card>(52);
		~Deck();
};

Deck::~Deck(){
}

void Deck::setDeck(Deck *d){
	int x=0;
	for(int i=0;i<13;++i)
	{
		d->top->at(x) = {Card::CLUBS,i+2};
		++x;
		d->top->at(x) = {Card::DIAMONDS,i+2};
		++x;
		d->top->at(x) = {Card::HEARTS,i+2};
		++x;
		d->top->at(x) = {Card::SPADES,i+2};
		++x;
	}
}

Deck::Deck(){
}


class Player
{
	public:
		Player();
		Card player_Card;
		int playerCard_pile=0;//Number of times a card was dealt to Player.
		int pSum=0;
		int highScore=0;
		int playerWage=0;		
		int wager(int wage,Player *p);
};

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
Player::Player(){
}


class Computer
{
	public:
		Card computer_Card;//Default values for Computer_Card.
		int computerCard_pile=0;//Number of times a card was dealt to Computer.
		Computer();
};

Computer::Computer(){
}


class GameController
{
	public:
		GameController();
		int start(int option);
		int deal(Player *p, Computer *c,Deck *d);
		void shuffle(Deck *d);
		int wageWinner(Player *p, Computer *c);
};

GameController::GameController(){
}

int GameController::start(int option)
{
	switch(option){
		
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

int GameController::deal(Player *p, Computer *c, Deck *d)
{
	if(d->remainingCards == 0){
		return 0;
	}
	
	else{
		p->player_Card=d->top->at(d->remainingCards-1);
		++p->playerCard_pile;
		--d->remainingCards;
		c->computer_Card=d->top->at(d->remainingCards-1);
		++c->computerCard_pile;
		--d->remainingCards;
	}
}

void GameController::shuffle(Deck *d)
{
	srand(time(NULL));
   	for(int i=0;i<2704;i++){
   		int Index1 = rand()%52;//chooses a random number from 0 to 51, since the array starts from index 0 to 51. 
   		int Index2 = rand()%52;
		if( Index1 != Index2 ){
			Card temp = d->top->at(Index1);//Making a temporary variable to store the data at Index1 before initializing Index1 to Index2's value.
			d->top->at(Index1) = d->top->at(Index2);
			d->top->at(Index2) = temp;
		}
	}
}

int GameController::wageWinner(Player *p, Computer *c)
{
	if(p->player_Card.get_baseValue() < c->computer_Card.get_baseValue()){
		return 1;
	}
	
	else if(p->player_Card.get_baseValue() > c->computer_Card.get_baseValue()){
		return 2;
	}
	
	else{
		return 3;
	}
}


int main()
{
	GameController controller;
	Player player;
	Computer computer;
	Deck deck;
	
	int Option=1;
	cout<<"----------Big Small Card Game----------"<<endl
	<<"1) New Game"<<endl
	<<"2) View High Score"<<endl
	<<"3) Quit"<<endl;
	cin>>Option;
	int returnedValue=controller.start(Option);
	
	if(returnedValue == 1){		//If user chose to play the game.
		int Difficulty=0;
		cout<<"Select Difficulty:\n"
		<<"1) Easy(Starting sum is $1000)\n"
		<<"2) Normal(Starting sum is $500)\n"
		<<"3) Hard(Starting sum is $250)\n";
		cin>>Difficulty;
		switch(Difficulty)
		{
			case 1:
				player.pSum=1000;
			break;
			case 2:
				player.pSum=500;
			break;
			case 3:
				player.pSum=250;
			break;
		}
	}
	
	else if(returnedValue == 2){	//If user chose to see high score.
		int nextOption=0;
		cout<<endl;
		cout<<"Next option: ";
		cin>>nextOption;
		controller.start(nextOption);
	}
	
	
	
	else if(returnedValue == 3){	//If user chooses to quit.
		deck.top->clear();
		delete deck.top;
		deck.top=NULL;
		return 0;
	}

	else if(returnedValue == 0){	//If default case is executed.
		int nextOption=0;
		cout<<endl;
		cout<<"Invalid option! Please enter an option from 1-3.\n Next option: ";
		cin>>nextOption;
		controller.start(nextOption);
	}
	
	deck.setDeck(&deck);
	controller.shuffle(&deck);	
	int wage=0;
	
	while(true) //To keep the game looping until a condition that ends the game is met.
	{
		if(player.pSum<=0){
			cout<<"You ran out of money! Game finished";
			deck.top->clear();
			delete deck.top;
			deck.top=NULL;
			return 0;
		}
		
		cout<<endl;
		
		cout<<"Cards Remaining: "<<deck.remainingCards<<endl
		<<"Account Balance: $"<<player.pSum<<endl
		<<"How much would you like to wage on this hand?"<<endl
		<<"$";
		cin>>wage;
		
		returnedValue = player.wager(wage,&player);
		
		if(returnedValue == 1){ //If pSum is less than the wage.
			int newWage=0;
			cout<<"Insufficient money! Please give an appropriate value. Sum: $"<<player.pSum<<endl;
			cin>>newWage;
			player.wager(newWage,&player);
		}
		
		else if(returnedValue == 2){ //If wage provided was 0 or less.
			int newWage=0;
			cout<<"Invalid value! Please give an appropriate value. Sum: $ "<<player.pSum<<endl;
			cin>>newWage;
			player.wager(newWage,&player);
		}
		
		returnedValue = controller.deal(&player,&computer,&deck); //Dealing a card from deck to player and computer.
		
		if(returnedValue==0){
			cout<<"Deck ran out of cards! Game finished.\n Money:"<<player.pSum;
			deck.top->clear();
			delete deck.top;
			deck.top=NULL;
			return 0;
		}
		
		returnedValue = controller.wageWinner(&player,&computer);
		
		cout<<"Computer player received: "<<computer.computer_Card.get_baseValue();
		
		switch (computer.computer_Card.get_suit()){
			case(1):
				cout<<"(Clubs)";
			break;
			case(2):
				cout<<"(Diamonds)";
			break;
			case(3):
				cout<<"(Hearts)";
			break;
			case(4):
				cout<<"(Spades)";
			break;
		}
		
		cout<<endl;
		
		cout<<"Human player received: "<<player.player_Card.get_baseValue();
		
		switch (player.player_Card.get_suit()){
			case(1):
				cout<<"(Clubs)";
			break;
			case(2):
				cout<<"(Diamonds)";
			break;
			case(3):
				cout<<"(Hearts)";
			break;
			case(4):
				cout<<"(Spades)";
			break;
		}
		
		cout<<endl;
		
		switch(returnedValue){
			case 1: //If Computer player wins.
				cout<<"You lost!\n computer player wins $"<<2*player.playerWage<<"!\n";
			break;
			
			case 2: //If Human player wins.
				cout<<"Human player wins $"<<2*player.playerWage<<"!\n";
				player.pSum+=2*player.playerWage;
			break;
							
			case 3: //If baseValues are equal.
				if(player.player_Card.get_suit()>computer.computer_Card.get_suit()){
					cout<<"You win $"<<2*player.playerWage<<"!\n";
					player.pSum+=2*player.playerWage;
				}	
				
				else{
					cout<<"You lost!"<<endl<<"Computer player wins $"<<2*player.playerWage<<"!\n";
				}
			break;	
		}	
	}
	return(0);
}
