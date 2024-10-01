#include <iostream>
#include <vector>
#include <cstdlib>
#include "GameLogic.hpp"

using namespace std;

void GameLogic::rollTheDiceAndMove(Player& player){
    if(player.inJail()){
        if(player.getJailTurns() < 3){
            int choose;
            cout << "choose one of those options :" << endl;
            cout << "(1) pay 50$ and leave the jail" << endl;
            cout << "(2) try to get a double " << endl;
            cout << "(3) wait for the three rounds to pass" << endl;
            cin >> choose;
            if(choose == 1){
                player.pay(50);
                player.leaveJail();
            }
            else if(choose == 2){
                int die1 = (rand() % 6) + 1;
                int die2 = (rand() % 6) + 1;
                cout << "You rolled " << die1 << " and " << die2 << std::endl;
                if (die1 == die2) {
                    player.leaveJail();
                    std::cout << "You rolled doubles! You're free!" << std::endl;
                } else {
                    player.setJailTurns(player.getJailTurns()+1);
                    std::cout << "You didn't roll doubles. Stay in jail." << std::endl;
                }
            }
            else if(choose == 3){
                player.setJailTurns(player.getJailTurns()+1);
            }
        }
        else{
            player.leaveJail();
        }
    }
    else{
        int diceRoll = (rand() % 6) + 1 + (rand() % 6) + 1; //simulates rolling two dice
        cout << player.getName() << " rolls " << diceRoll << endl;
        player.move(diceRoll);

        Property& landedProperty = board.getProperty(player.getPosition());
        cout << player.getName() << " landed on " << landedProperty.getName() << endl;

        if (landedProperty.getOwner() == nullptr && landedProperty.getName()!="Jail"
        && landedProperty.getName()!="Community Chest" && landedProperty.getName()!="Chance"
        && landedProperty.getName()!="Luxury Tax" && landedProperty.getName()!="Income Tax"
        && landedProperty.getName()!="Go To Jail" && landedProperty.getName()!="Free Parking"
        && landedProperty.getName()!="go") {
            cout << landedProperty.getName() << " is available for purchase for " << landedProperty.getPrice() << "$" << endl;
            int choice;
            cout << "(1)show your balance " << endl;
            cout << "(2)buy the property " << endl;
            cout << "(3)continue " << endl;
            cin >> choice;
            if (choice == 2) {
                player.buyProperty(landedProperty);
            }
            else if(choice == 1){
                player.showStatus();
                cout << "do you want to buy the property (y/n) ?" << endl;
                char choose;
                cin >> choose;
                if(choose == 'y'){
                    player.buyProperty(landedProperty);
                }
            }
        }
        else if(landedProperty.getName()=="Income Tax" || landedProperty.getName()=="Luxury Tax"){
            player.pay(100);
        }
        else if(landedProperty.getName()=="go"){
            player.move(0);
        }
        else if(landedProperty.getName()=="Jail"){
            player.moveToJail();
        }
        else if(landedProperty.getName()=="Go To Jail"){
            player.moveToJail();
        }
        else if(landedProperty.getName()=="Community Chest"){
            Card* card = communityChest->drawCard();
            card->applyEffect(player);
            cout << card->description << endl;
        }
        else if(landedProperty.getName()=="Chance"){
            Card* card = chance->drawCard();
            card->applyEffect(player);
            cout << card->description << endl;
        }
        else if(landedProperty.getOwner() == &player){
            cout << player.getName() << "  , this property is yours" << endl;
            if(player.hasAllColor(landedProperty.getColor())){
                cout << "do you want to buy a house or hotel?(y/n)" << endl;
                char choice;
                cin >> choice;
                if(choice == 'y'){
                    cout << "what to buy ? (h)for house (H)for hotel" << endl;
                    char choose;
                    cin >> choose;
                    if(choose == 'h'){
                        landedProperty.buyHouse(player);
                    }
                    else if(choose == 'H'){
                        landedProperty.buyHotel(player);
                    }
                }
            }
        }
        else {
            cout << landedProperty.getName() << " is owned by " << landedProperty.getOwner()->getName() <<endl;
            landedProperty.chargeRent(player);
        }
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
            initializeDecks();
            rollTheDiceAndMove(currentPlayer);
        }
        nextTurn();
    }
}

void GameLogic::initializeDecks(){
    communityChest->addCard(new goToJailCard());
    communityChest->addCard(new advanceToGoCard());

    chance->addCard(new goBackCard());
    chance->addCard(new poorTaxCard());

    communityChest->shuffle();
    chance->shuffle();
}