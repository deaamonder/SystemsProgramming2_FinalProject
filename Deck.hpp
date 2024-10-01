#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Card.hpp"

using namespace std;

class Deck{
    private:    
        vector<Card*> cards;
        size_t currentIndex;
    
    public:
        Deck(){
            this->currentIndex = 0;
        }

        ~Deck() {
            for (Card* card : cards) {
                delete card;  
            }
            cards.clear();  
        }

        //function to add a card 
        void addCard(Card* card);

        //shuffle the deck
        void shuffle();

        //function to draw the next card in the deck 
        Card* drawCard();

};

class communityChestDeck : public Deck{
    public:
        communityChestDeck() : Deck(){}

};

class chanceDeck : public Deck{
    public:
        chanceDeck() : Deck(){}

};

#endif // DECK_HPP
