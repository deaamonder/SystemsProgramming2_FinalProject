#include <iostream>
#include "Property.hpp"

using namespace std;

string Property::getName(){
    return this->name;
}

string Property::getColor(){
    return this->color;
}

int Property::getPrice(){
    return this->price;
}

int Property::getNumOfHouses(){
    return this->numOfHouses;
}

Player* Property::getOwner(){
    return this->owner;
}

void Property::setOwner(Player* owner){
    this->owner = owner;
}

// bool Property::buyProperty(Player& player){
//     if(player.getBalance() >= this->price){
//         player.pay(this->price);
//         this->owner = &player;
//         return true;
//     }
//     return false;
// }

void Property::chargeRent(Player& player){
    if(this->owner == &player){
        return; //in case that the player the function get is the owner of the property
    }
    player.payToOtherPlayer(this->owner,this->rent);
}

bool Property::buyHouse(Player& player){
    if(this->owner == &player && player.hasAllColor(this->color) && player.isSameNumberOfHouses(this->color)){
        if(player.getBalance() >= this->housePrice){
            this->numOfHouses++;
            player.pay(this->housePrice);
            return true;
        }
    }
    return false;
}

bool Property::buyHotel(Player& player){
    if(this->owner == &player && this->numOfHouses == 4){
        if(player.getBalance() >= this->housePrice*4 + 100){
            player.pay(this->housePrice*4 + 100);
            this->hasHotel = true;
            return true;
        }
        return false;
    }
    return false;
}