#include <iostream>
#include "Player.hpp"

using namespace std;

bool Player::getBroke(){
    return this->isBroke;
}

int Player::getBalance(){
    return this->balance;
}

int Player::getPosition(){
    return this->postion;
}

string Player::getName(){
    return this->name;
}

void Player::move(int diceResult){
    this->postion += diceResult % 40; // the board has 40 squares
}

void Player::pay(int amount){
    this->balance -= amount;
    //check if the player became broke
    if(this->balance < 0){
        this->isBroke = false;
    }
}

void Player::payToOtherPlayer(Player* other, int amount){
    this->balance -= amount;
    other->balance += amount;
    if(this->balance < 0){
        this->isBroke = true; 
    }
}