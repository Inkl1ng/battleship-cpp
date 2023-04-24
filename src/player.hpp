#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ship.hpp"
#include <iostream>
#include <string>
#include <array>
#include <vector>

// class to represent players
// contains name, boards, and ships
class Player
{
    public:
        // Player class constructor
        Player(const std::string &playerName);

        // returns reference to the player's name
        std::string & getName();

        // get piece at (row, col) in oceanBorad
        char getOceanPiece(int col, int row);

        // get piece at (row, col) in targetBoard
        char getTargetPiece(int col, int row);
        
        // gets a specific ship given the fist character of the ships's type
        Ship* getShip(char symbol);

        void setOceanPiece(int col, int row, char piece);
        void setTargetPiece(int col, int row, char piece);

        // hanldes shooting, player that is shooting will call this method,
        // returns tile that was shot at
        char shoot(int col, int row, Player &target);

        void addShip(Ship &newShip);
        void removeShip(std::string targetShipType);


    private:
        std::string name {};

        // represents where the player has placed their ships and where the
        // ships have been hit
        std::array<std::array<char, 10>, 10> oceanBoard {};

        // represents where the player has shot, hit, and missed
        std::array<std::array<char, 10>, 10> targetBoard {};

        std::vector<Ship> ships {};
};

#endif