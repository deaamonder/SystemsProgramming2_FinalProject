#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <iostream>
#include <vector>
#include "Property.hpp"

using namespace std;

class Board{
    private :
        vector<Property> Properties;

    public:
        Board(){
            Properties.push_back(Property("go", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Mediterranean Avenue", "brown", 60, 2, 10, 250, nullptr));
            Properties.push_back(Property("Community Chest", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Baltic Avenue", "brown", 60, 4, 20, 450, nullptr));
            Properties.push_back(Property("Income Tax", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Reading Railroad", "nullptr", 200, 0, 0, 0, nullptr));
            Properties.push_back(Property("Oriental Avenue", "light blue", 100, 6, 30, 550, nullptr));
            Properties.push_back(Property("Chance", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Vermont Avenue", "light blue", 100, 6, 30, 550, nullptr));
            Properties.push_back(Property("Connecticut Avenue", "light blue", 120, 8, 40, 600, nullptr));
            Properties.push_back(Property("Jail", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("St.Charles Place", "pink", 140, 10, 50, 750, nullptr));
            Properties.push_back(Property("Electric Company", "nullptr", 150, 0, 0, 0, nullptr));
            Properties.push_back(Property("States Avenue", "pink", 140, 10, 50, 750, nullptr));
            Properties.push_back(Property("Virginia Avenue", "pink", 160, 12, 60, 900, nullptr));
            Properties.push_back(Property("Pennsylvania Railroad", "nullptr", 200, 0, 0, 0, nullptr));
            Properties.push_back(Property("St.James Place", "orange", 180, 14, 70, 950, nullptr));
            Properties.push_back(Property("Community Chest", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Tennessee Avenue", "orange", 180, 14, 70, 950, nullptr));
            Properties.push_back(Property("New York Avenue", "orange", 200, 16, 80, 1000, nullptr));
            Properties.push_back(Property("Free Parking", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Kentucky Avenue", "red", 220, 18, 90, 1050, nullptr));
            Properties.push_back(Property("Chance", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Indiana Avenue", "red", 220, 18, 90, 1050, nullptr));
            Properties.push_back(Property("Illinois Avenue", "red", 240, 20, 100, 1100, nullptr));
            Properties.push_back(Property("B&O Railroad", "nullptr", 200, 0, 0, 0, nullptr));
            Properties.push_back(Property("Atlantic Avenue", "yellow", 260, 22, 110, 1150, nullptr));
            Properties.push_back(Property("Ventnor Avenue", "yellow", 260, 22, 110, 1150, nullptr));
            Properties.push_back(Property("Water Works", "nullptr", 150, 0, 0, 0, nullptr));
            Properties.push_back(Property("Marvin Gardens", "yellow", 280, 24, 120, 1200, nullptr));
            Properties.push_back(Property("Go To Jail", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Pacific Avenue", "green", 300, 26, 130, 1275, nullptr));
            Properties.push_back(Property("North Carolina Avenue", "green", 300, 26, 130, 1275, nullptr));
            Properties.push_back(Property("Community Chest", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Pennsylvania Avenue", "green", 300, 26, 130, 1275, nullptr));
            Properties.push_back(Property("Short Line Railroad", "nullptr", 200, 0, 0, 0, nullptr));
            Properties.push_back(Property("Chance", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Park Place", "dark blue", 350, 35, 175, 1500, nullptr));
            Properties.push_back(Property("Luxury Tax", "nullptr", 0, 0, 0, 0, nullptr));
            Properties.push_back(Property("Board Walk", "dark blue", 400, 50, 200, 2000, nullptr));
        }

        Property& getProperty(int postion);
};

#endif // GAMEBOARD_HPP