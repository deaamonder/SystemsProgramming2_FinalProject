#include <iostream>
#include "GameBoard.hpp"
#include "GameLogic.hpp"
#include "Player.hpp"
#include "Property.hpp"
#include "Card.hpp"

using namespace std;

int main(){
    int numOfPlayers;
    cout << "enter the number of players in the game" << endl;
    cin >> numOfPlayers;
    if(numOfPlayers < 2 || numOfPlayers > 8){
        cout << "invalid number of players" << endl;
        return 1;
    }

    GameLogic game(numOfPlayers);
    game.startGame();
    

    return 0;
}