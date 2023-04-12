#include "player.hpp"
#include <iostream>

Player::Player(std::string playerName)
{
    this->name = playerName;

    for (int row { 0 }; row < 10; ++row)
    {
        for (int col { 0 }; col < 10; ++col)
        {
            this->targetBoard[row][col] = '.';
            this->oceanBoard[row][col] = '.';
        }
    }
}

std::string& Player::getName()
{
    return this->name;
}

char Player::getOceanPiece(int row, int col)
{
    return this->oceanBoard[row][col];
}

char Player::getTargetPiece(int row, int col)
{
    return this->targetBoard[row][col];
}
