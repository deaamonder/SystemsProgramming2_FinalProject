#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Property.hpp"

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

bool Player::inJail(){
    return this->isInJail;
}

int Player::getJailTurns(){
    return this->jailTurns;
}

void Player::setJailTurns(int turns){
    this->jailTurns = turns;
}

void Player::setPostion(int postion){
    this->postion = postion;
}

void Player::move(int diceResult){
    this->postion += diceResult % 40; // the board has 40 squares
}

void Player::moveToJail(){
    this->postion = 10;
    this->isInJail = true;
    this->jailTurns = 0; // in case the player sent to jail twice
}

void Player::leaveJail(){
    this->isInJail = false;
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

void Player::getPaid(int amount){
    this->balance += amount;
}

void Player::buyProperty(Property& property){
    if(this->balance >= property.getPrice()){
        pay(property.getPrice());
        properties.push_back(&property);
        property.setOwner(this);
        cout << this->getName() << " bought " << property.getName() << endl;
    }
    else{
        cout << this->getName() << " cant buy the property " << endl;
    }
}

bool Player::hasAllColor(string color){
    int brownCount = 0, pinkCount = 0, orangeCount = 0, greenCount = 0, redCount = 0, yellowCount = 0, darkBlueCount = 0, lightBlueCount = 0;
    for(size_t i=0; i<this->properties.size(); i++){
        if(this->properties[i]->getColor() == "brown"){brownCount++;}
        if(this->properties[i]->getColor() == "pink"){pinkCount++;}
        if(this->properties[i]->getColor() == "orange"){orangeCount++;}
        if(this->properties[i]->getColor() == "red"){redCount++;}
        if(this->properties[i]->getColor() == "yellow"){yellowCount++;}
        if(this->properties[i]->getColor() == "green"){greenCount++;}
        if(this->properties[i]->getColor() == "light blue"){lightBlueCount++;}
        if(this->properties[i]->getColor() == "dark blue"){darkBlueCount++;}
    }
    if(color == "brown" && brownCount == 2){return true;}
    if(color == "light blue" && lightBlueCount == 3){return true;}
    if(color == "pink" && pinkCount == 3){return true;}
    if(color == "orange" && orangeCount == 3){return true;}
    if(color == "red" && redCount == 3){return true;}
    if(color == "yellow" && yellowCount == 3){return true;}
    if(color == "green" && greenCount == 3){return true;}
    if(color == "dark blue" && darkBlueCount == 2){return true;}
    return false;
}

void Player::showStatus(){
    cout << this->name << " has total of " << this->balance << " $ " << endl;
}

bool Player::isSameNumberOfHouses(string color){
    if(hasAllColor(color)){
        vector<Property*> colorGroupProperties;
        for(size_t i =0; i<this->properties.size(); i++){
            if(this->properties[i]->getColor() == color){colorGroupProperties.push_back(properties[i]);}
        }
        int numOfHouses = colorGroupProperties[0]->getNumOfHouses();
        for(size_t i=1; i<colorGroupProperties.size(); i++){
            if(colorGroupProperties[i]->getNumOfHouses() != numOfHouses){
                return false;
            }
        }
        return true;
    }
    return false;
}