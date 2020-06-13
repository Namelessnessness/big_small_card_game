#include<iostream>
#include "../src/controllers/GameController.h"
#include "../src/controllers/Computer.h"
#include "../src/controllers/Player.h"
#include "../src/models/Deck.h"
#include "../src/models/Card.h"
using namespace std;

int main()
{
	GameController controller;
	Player player;
	Computer computer;
	Deck deck;

	int Option = 1;
	cout << "----------Big Small Card Game----------" << endl
		<< "1) New Game" << endl
		<< "2) View High Score" << endl
		<< "3) Quit" << endl;
	cin >> Option;
	int returnedValue = controller.start(Option);

	if (returnedValue == 1) {	//If user chose to play the game.
		int Difficulty = 0;
		cout << "Select Difficulty:\n"
			<< "1) Easy(Starting sum is $1000)\n"
			<< "2) Normal(Starting sum is $500)\n"
			<< "3) Hard(Starting sum is $250)\n";
		cin >> Difficulty;
		switch (Difficulty)
		{
		case 1:
			player.pSum = 1000;
			break;
		case 2:
			player.pSum = 500;
			break;
		case 3:
			player.pSum = 250;
			break;
		}
	}

	else if (returnedValue == 2) {	//If user chose to see high score.
		int nextOption = 0;
		cout << endl;
		cout << "Next option: ";
		cin >> nextOption;
		controller.start(nextOption);
	}



	else if (returnedValue == 3) {	//If user chooses to quit.
		deck.top->clear();
		delete deck.top;
		deck.top = NULL;
		return 0;
	}

	else if (returnedValue == 0) {	//If default case is executed.
		int nextOption = 0;
		cout << endl;
		cout << "Invalid option! Please enter an option from 1-3.\n Next option: ";
		cin >> nextOption;
		controller.start(nextOption);
	}

	deck.setDeck(&deck);
	controller.shuffle(&deck);
	int wage = 0;

	while (true) //To keep the game looping until a condition that ends the game is met.
	{
		if (player.pSum <= 0) {
			cout << "You ran out of money! Game finished";
			deck.top->clear();
			delete deck.top;
			deck.top = NULL;
			return 0;
		}

		cout << endl;

		cout << "Cards Remaining: " << deck.remainingCards << endl
			<< "Account Balance: $" << player.pSum << endl
			<< "How much would you like to wage on this hand?" << endl
			<< "$";
		cin >> wage;

		returnedValue = player.wager(wage, &player);

		if (returnedValue == 1) { //If pSum is less than the wage.
			int newWage = 0;
			cout << "Insufficient money! Please give an appropriate value. Sum: $" << player.pSum << endl;
			cin >> newWage;
			player.wager(newWage, &player);
		}

		else if (returnedValue == 2) { //If wage provided was 0 or less.
			int newWage = 0;
			cout << "Invalid value! Please give an appropriate value. Sum: $ " << player.pSum << endl;
			cin >> newWage;
			player.wager(newWage, &player);
		}

		else if (returnedValue == 3){
			player.pSum -= wage;
			player.playerWage = wage;
		}
		returnedValue = controller.deal(&player, &computer, &deck); //Dealing a card from deck to player and computer.

		if (returnedValue == 0) {
			cout << "Deck ran out of cards! Game finished.\n Money:" << player.pSum;
			deck.top->clear();
			delete deck.top;
			deck.top = NULL;
			return 0;
		}

		returnedValue = controller.wageWinner(&player, &computer);

		cout << "Computer player received: " << computer.computer_Card.get_baseValue();

		switch (computer.computer_Card.get_suit()) {
		case(1):
			cout << "(Clubs)";
			break;
		case(2):
			cout << "(Diamonds)";
			break;
		case(3):
			cout << "(Hearts)";
			break;
		case(4):
			cout << "(Spades)";
			break;
		}

		cout << endl;

		cout << "Human player received: " << player.player_Card.get_baseValue();

		switch (player.player_Card.get_suit()) {
		case(1):
			cout << "(Clubs)";
			break;
		case(2):
			cout << "(Diamonds)";
			break;
		case(3):
			cout << "(Hearts)";
			break;
		case(4):
			cout << "(Spades)";
			break;
		}

		cout << endl;

		switch (returnedValue) {
		case 1: //If Computer player wins.
			cout << "You lost!\n computer player wins $" << 2 * player.playerWage << "!\n";
			break;

		case 2: //If Human player wins.
			cout << "Human player wins $" << 2 * player.playerWage << "!\n";
			player.pSum += 2 * player.playerWage;
			break;

		case 3: //If baseValues are equal.
			if (player.player_Card.get_suit() > computer.computer_Card.get_suit()) {
				cout << "You win $" << 2 * player.playerWage << "!\n";
				player.pSum += 2 * player.playerWage;
			}

			else {
				cout << "You lost!" << endl << "Computer player wins $" << 2 * player.playerWage << "!\n";
			}
			break;
		}
	}
	return(0);
}