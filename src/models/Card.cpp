#include "Card.h"

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
