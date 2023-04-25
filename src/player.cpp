#include "player.hpp"
#include "ship.hpp"
#include "render.hpp"
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

std::vector<Ship>& Player::getShips()
{
    return ships;
}

void Player::setOceanPiece(int col, int row, char piece)
{
    oceanBoard[row][col] = piece;
}

void Player::setTargetPiece(int col, int row, char piece)
{
    targetBoard[row][col] = piece;
}

void Player::shoot(int col, int row, Player &target, bool isPlayer2)
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

        std::vector<Ship>& targetShips { target.getShips() };

        for (Ship& ship : targetShips)
        {
            if (targetPiece == ship.getType()[0])
            {
                
                // std::cout << locations.size() << '\n';
                ship.shootAt(col, row) ? Render::message("You sunk ", isPlayer2) :
                           Render::message("You hit ", false);
                // can use cout here because the indentation has already happened
                std::cout << "their " + ship.getType() + "!\n";
                return; // end the function
            }
        }   
    }
    else
    {
        // mark miss
        setTargetPiece(col, row, 'o');
        target.setOceanPiece(col, row, 'o');
        Render::message("Miss!\n", isPlayer2);
    }
}


void Player::addShip(Ship &newShip)
{
    int row;
    int col;
    for (std::array<int, 2> location : newShip.getLocations())
    {
        row = location[1];
        col = location[0];
        setOceanPiece(col, row, newShip.getType()[0]);
    }
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