#include "player.hpp"
#include "ship.hpp"
#include <iostream>

Player::Player(const std::string &playerName)
{
    this->name = playerName;

    for (int row { 0 }; row < 10; ++row)
    {
        for (int col { 0 }; col < 10; ++col)
        {
            this->oceanBoard[row][col] = '.';
            this->targetBoard[row][col] = '.';
        }
    }
}

std::string& Player::getName()
{
    return this->name;
}

char Player::getOceanPiece(int col, int row)
{
    return this->oceanBoard[row][col];
}

char Player::getTargetPiece(int col, int row)
{
    return this->targetBoard[row][col];
}

bool Player::shoot(int col, int row, Player &target)
{
    // input is 100% legal when it is passed through this method
    // check if the shot was a hit
    return false;
}