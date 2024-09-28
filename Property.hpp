#include <iostream>
#include "Player.hpp"

using namespace std;

class Property{
    private :
        string name;
        int price;
        int rent;
        Player* owner;

    public :
        Property(string name, int price, int rent, Player* owner){
            this->name = name;
            this->price = price;
            this->rent = rent;
            this->owner = owner;
        }

        //name getter
        string getName();

        //owner setter
        void setOwner(Player* owner);

        //owner getter
        Player* getOwner();

        //function to buy the property , return true if it success and false else
        bool buyProperty(Player& player);

        //function to charge the rent , the function get a player and this player 
        // must pay the rent for the property owner 
        void chargeRent(Player& player);
};