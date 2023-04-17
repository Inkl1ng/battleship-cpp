#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "types.hpp"
#include <iostream>
#include <string>
#include <array>

// class to represent players
// contains name, boards, and ships
class Player
{
    public:
        // Player class constructor
        Player(std::string playerName);

        // returns reference to the player's name
        std::string & getName();
        // get piece at (row, col) in oceanBorad
        char getOceanPiece(int row, int col);
        // get piece at (row, col) in targetBoard
        char getTargetPiece(int row, int col);
        bool shoot(int row, int col, Player &target);

    private:
        std::string name{};
        // represents where the player has placed their ships and where the
        // ships have been hit
        Board oceanBoard {};
        // represents where the player has shot, hit, and missed
        Board targetBoard {};
};

#endif