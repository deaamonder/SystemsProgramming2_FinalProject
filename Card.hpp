#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

class Card{
    public:
        string description;

        Card(string description){
            this->description = description;
        }

        virtual ~Card(){}

        //name getter (description) will be used in test
        virtual string getName();

        //function to apply the card effect on the player
        virtual void applyEffect(Player& player) = 0; 
};

class goToJailCard : public Card {
    public:
        goToJailCard() : Card("Go To Jail"){}

        void applyEffect(Player& player) override;
};

class advanceToGoCard : public Card{
    public:
        advanceToGoCard() : Card("Advance To Go"){}

        void applyEffect(Player& player) override;

};

class goBackCard : public Card{
    public:
        goBackCard() : Card("Go Back"){}

        //this card will take the player back 3 steps
        void applyEffect(Player& player) override;
};

class poorTaxCard : public Card{
    public:
        poorTaxCard() : Card("Pay a Tax of 15$"){}

        //this card makes the player pay a tax of 15$
        void applyEffect(Player& player) override;
};

#endif // CARD_HPP