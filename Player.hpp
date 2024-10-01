#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector> 

using namespace std;

//forward declration to avoid circular dependency
class Property;

class Player{
    private:
        string name;
        int postion;
        int balance;
        bool isBroke;
        bool isInJail;
        int jailTurns;
        vector<Property*> properties; //each property that the player buy will be added here

    public:
        Player(string name){
            this->name = name;
            this->postion = 0;
            this->balance = 1500;
            this->isBroke = false;
            this->isInJail = false;
            this->jailTurns = 0;
        }
        
        //is the player Broke ?
        bool getBroke();

        //name getter
        string getName();

        //postion getter
        int getPosition();

        //balance getter
        int getBalance();

        //is the player in Jail
        bool inJail();

        //Jail turns getter
        int getJailTurns();

        //jail turns setter
        void setJailTurns(int turns);

        //postion setter , will be used in some chance cards
        void setPostion(int postion);

        //function that allow the player to move 
        void move(int diceResult);

        //a function to move to jail
        void moveToJail();

        //a function to leave the jail
        void leaveJail();

        //function that update the player's balance and the player status
        void pay(int amount);

        //function that allow one player to pay for another player, will be used 
        //when paying rent 
        void payToOtherPlayer(Player* Other, int amount);

        //function to get paid
        void getPaid(int amount);

        //function to buy a property
        void buyProperty(Property& property);

        //function that return true if the player has all property of the giving color
        bool hasAllColor(string color);

        //function that shows the player financial
        void showStatus();

        //function to check if all color category properties has same number of houses
        bool isSameNumberOfHouses(string color);


};

#endif // PLAYER_HPP