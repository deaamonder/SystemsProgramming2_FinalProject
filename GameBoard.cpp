#include <iostream>
#include "GameBoard.hpp"

using namespace std;

Property& Board::getProperty(int postion){
    return Properties[postion % Properties.size()];
}