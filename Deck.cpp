#include <iostream>
#include <vector>
#include <cstdlib>
#include "Deck.hpp"

using namespace std;

void Deck::addCard(Card* card){
    cards.push_back(card);
}

void Deck::shuffle(){
    for(size_t i=0; i<this->cards.size(); i++){
        int rand1 = rand() % this->cards.size();
        int rand2 = rand() % this->cards.size();
        if(rand1 != rand2){
            Card* temp = cards[rand1];
            cards[rand1] = cards[rand2];
            cards[rand2] = temp;
        }
    }
}

Card* Deck::drawCard(){
    if (cards.empty()) {
        return nullptr; // can also throw an exception
    }

    if (currentIndex >= cards.size()) {
        currentIndex = 0; 
    }
    
    return cards[currentIndex++];
}