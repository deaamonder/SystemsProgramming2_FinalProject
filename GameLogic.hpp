#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Player.hpp"
#include "GameBoard.hpp"
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

class GameLogic{
    private:
        vector<Player> players;
        Board board;
        int CPI; //CPI stands for Current Player Index
        Deck* communityChest;
        Deck* chance;
    
    public:
        GameLogic(int numOfPlayers) : board(){
            for(int i = 0; i < numOfPlayers; i++){
                string playerName;
                cout << "enter player " << i+1 << " name :";
                cin >> playerName;
                players.push_back(Player(playerName));
            }
            CPI = 0;
            communityChest = new communityChestDeck();
            chance = new chanceDeck();
            initializeDecks();
        }

        ~GameLogic() {
            delete communityChest; 
            delete chance;  
        }

        void rollTheDiceAndMove(Player& player);

        void nextTurn();

        void startGame();

        //a function to initialize the community chest and chance Decks
        void initializeDecks();


};

#endif // GAMELOGIC_HPP