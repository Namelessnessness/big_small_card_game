#ifndef COMPUTER_HEADER
#define COMPUTER_HEADER


#include "../models/Card.h"


class Computer
{
public:
	Computer();
	~Computer();
	Card computer_Card;//Default values for Computer_Card.
	int computerCard_pile = 0;//Number of times a card was dealt to Computer.
	
};
#endif