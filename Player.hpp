#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        int postion;
        int balance;
        bool isBroke;

    public:
        Player(string name){
            this->name = name;
            this->postion = 0;
            this->balance = 1500;
            this->isBroke = false;
        }
        
        //is the player Broke ?
        bool getBroke();

        //name getter
        string getName();

        //postion getter
        int getPosition();

        //balance getter
        int getBalance();

        //function that allow the player to move 
        void move(int diceResult);

        //function that update the player's balance and the player status
        void pay(int amount);

        //function that allow one player to pay for another player, will be used 
        //when paying rent 
        void payToOtherPlayer(Player* Other, int amount);


};