#include <iostream>
#include "Property.hpp"

using namespace std;

string Property::getName(){
    return this->name;
}

Player* Property::getOwner(){
    return this->owner;
}

void Property::setOwner(Player* owner){
    this->owner = owner;
}

bool Property::buyProperty(Player& player){
    if(player.getBalance() >= this->price){
        player.pay(this->price);
        this->owner = &player;
        return true;
    }
    return false;
}

void Property::chargeRent(Player& player){
    if(this->owner == &player){
        return; //in case that the player the function get is the owner of the property
    }
    player.payToOtherPlayer(this->owner,this->rent);
}