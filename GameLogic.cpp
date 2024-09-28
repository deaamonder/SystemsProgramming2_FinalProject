#include <iostream>
#include <vector>
#include <cstdlib>
#include "GameLogic.hpp"

using namespace std;

void GameLogic::rollTheDiceAndMove(Player& player){
    int diceRoll = (rand() % 6) + 1 + (rand() % 6) + 1; //simulates rolling two dice
    cout << player.getName() << " rolls " << diceRoll << endl;
    player.move(diceRoll);

    Property& landedProperty = board.getProperty(player.getPosition());
    cout << player.getName() << " landed on " << landedProperty.getName() << endl;

    if (landedProperty.getOwner() == nullptr) {
        cout << landedProperty.getName() << " is available for purchase." << endl;
        char choice;
        cout << "Do you want to buy it? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            if (landedProperty.buyProperty(player)) {
                cout << player.getName() << " bought " << landedProperty.getName() << endl;
            } else {
                cout << "Not enough money to buy this property." << endl;
            }
        }
    } else {
        cout << landedProperty.getName() << " is owned by " << landedProperty.getOwner()->getName() <<endl;
        landedProperty.chargeRent(player);
    }
}

void GameLogic::nextTurn(){
    this->CPI = (this->CPI + 1) % this->players.size();
}

void GameLogic::startGame(){
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    while (true) {
        Player& currentPlayer = players[CPI];
        if (!currentPlayer.getBroke()) {
            cout << "\nIt's " << currentPlayer.getName() << "'s turn." << endl;
            rollTheDiceAndMove(currentPlayer);
        }
        nextTurn();
    }
}