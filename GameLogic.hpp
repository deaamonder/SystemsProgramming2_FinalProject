#include <iostream>
#include <vector>
#include <cstdlib>
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

class GameLogic{
    private:
        vector<Player> players;
        Board board;
        int CPI; //CPI stands for Current Player Index
    
    public:
        GameLogic(int numOfPlayers) : board(){
            for(int i = 0; i < numOfPlayers; i++){
                string playerName;
                cout << "enter player" << i+1 << "name :";
                cin >> playerName;
                players.push_back(Player(playerName));
            }
            CPI = 0;
        }

        void rollTheDiceAndMove(Player& player);

        void nextTurn();

        void startGame();
};