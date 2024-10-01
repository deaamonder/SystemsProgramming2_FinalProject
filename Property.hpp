#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <iostream>
#include "Player.hpp"

using namespace std;

class Property{
    private :
        string name;
        string color;
        int price;
        int rent;
        int houseRent;
        int housePrice;
        int hotelRent;
        Player* owner;
        int numOfHouses;
        bool hasHotel;
        bool isMortgaged;

    public :
        Property(string name, string color, int price, int rent, int houseRent, int hotelRent, Player* owner){
            this->name = name;
            this->color = color;
            this->price = price;
            this->rent = rent;
            this->houseRent = houseRent;
            this->hotelRent = hotelRent;
            this->owner = owner;
            this->numOfHouses = 0;
            this->hasHotel = false;
            this->isMortgaged = false;
            calculatePrice();
        }

        //function to calcuate the house price
        void calculatePrice(){
            if(this->color == "brown"){this->housePrice = 50;}
            if(this->color == "light blue"){this->housePrice = 50;}
            if(this->color == "pink"){this->housePrice = 100;}
            if(this->color == "orange"){this->housePrice = 100;}
            if(this->color == "red"){this->housePrice = 150;}
            if(this->color == "yellow"){this->housePrice = 150;}
            if(this->color == "green"){this->housePrice = 200;}
            if(this->color == "dark blue"){this->housePrice = 200;}
        }

        //name getter
        string getName();

        //color getter
        string getColor();

        //price getter
        int getPrice();

        //number of houses getter
        int getNumOfHouses();

        //owner setter
        void setOwner(Player* owner);

        //owner getter
        Player* getOwner();

        //function to buy the property , return true if it success and false else
        //bool buyProperty(Player& player);

        //function to charge the rent , the function get a player and this player 
        // must pay the rent for the property owner 
        void chargeRent(Player& player);

        //function to buy a house , return ture if the player can buy a house and 
        //false else
        bool buyHouse(Player& player);

        //function to buy a hotel , return true if the player can buy a hotel and
        //false else
        bool buyHotel(Player& player);
};

#endif // PROPERTY_HPP