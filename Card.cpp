#include <iostream>
#include <string>
#include "Card.hpp"

using namespace std;

string Card::getName(){
    return this->description;
}

void goToJailCard::applyEffect(Player& player){
    player.moveToJail();
    cout << "player " << player.getName() << " draw Go To Jail Card" << endl;
}

void advanceToGoCard::applyEffect(Player& player){
    player.setPostion(0);
    player.getPaid(200);
}

void goBackCard::applyEffect(Player& player){
    player.setPostion((player.getPosition() - 3) % 40);
}

void poorTaxCard::applyEffect(Player& player){
    player.pay(15);
}