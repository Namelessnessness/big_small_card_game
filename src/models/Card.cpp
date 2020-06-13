#include "Card.h"

Card::Card()
: suit(0),baseValue(0){
	Card(suit,baseValue);
}

Card::Card(int suit, int baseValue)
 : suit(suit) ,baseValue(baseValue){
}

int Card::get_baseValue(){
	return baseValue;
}

int Card::get_suit(){
	return suit;
}
