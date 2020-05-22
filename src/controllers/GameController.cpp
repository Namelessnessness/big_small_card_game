#include "GameController.h"

void GameController::betMoney(int money) {
  if(remainingMoney<money)
    throw "Insufficient money";
  else 
	remainingMoney-=money;			
}