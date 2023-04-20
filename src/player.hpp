#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ship.hpp"
#include <iostream>
#include <string>
#include <array>

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
        // hanldes shooting, player that is shooting will call this method,
        // returns true if there was a hit
        bool shoot(int col, int row, Player &target);

    private:
        std::string name{};
        // represents where the player has placed their ships and where the
        // ships have been hit
        std::array<std::array<char, 10>, 10> oceanBoard {};
        // represents where the player has shot, hit, and missed
        std::array<std::array<char, 10>, 10> targetBoard {};
};

#endif