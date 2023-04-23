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
            oceanBoard[row][col] = '.';
            targetBoard[row][col] = '.';
        }
    }
}

std::string& Player::getName()
{
    return name;
}

char Player::getOceanPiece(int col, int row)
{
    return oceanBoard[row][col];
}

char Player::getTargetPiece(int col, int row)
{
    return targetBoard[row][col];
}

void Player::setOceanPiece(int col, int row, char piece)
{
    oceanBoard[row][col] = piece;
}

void Player::setTargetPiece(int col, int row, char piece)
{
    targetBoard[row][col] = piece;
}

bool Player::shoot(int col, int row, Player &target)
{
    bool hitShip {};

    // check if the shot was a hit
    char targetPiece = target.getOceanPiece(col, row);
    hitShip = !(targetPiece == '.');

    if (hitShip)
    {
        // mark hits
        setTargetPiece(col, row, 'X');
        target.setOceanPiece(col, row, '#');
    }
    else
    {
        setTargetPiece(col, row, 'o');
        target.setOceanPiece(col, row, 'o');
    }
    
    return hitShip;
}


void Player::addShip(Ship &newShip)
{
    ships.push_back(newShip);
}

void Player::removeShip(std::string targetShipType)
{
    for (int index { 0 }; index < sizeof(ships); ++index)
    {
        Ship &targetShip = ships[index];
        if (targetShip.getType() == targetShipType)
        {
            ships.erase(index + ships.begin());
            return;
        }
    }
}