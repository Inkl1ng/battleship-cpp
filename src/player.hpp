#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <array>

// class to represent players
// contains name, boards, and ships
class Player
{
    std::string name{};
    // 2d std::array to represent where the player has placed their
    // ships and where the ships have been hit
    std::array<std::array<char, 10>, 10> oceanBoard {};
    // 2d std::array to represent where the player has shot, hit, and missed
    std::array<std::array<char, 10>, 10> targetBoard {};

public:
    // Player class constructor
    Player(std::string playerName);

    // returns reference to the player's name
    std::string & getName();
    // get piece at (row, col) in oceanBorad
    char getOceanPiece(int row, int col);
    // get piece at (row, col) in targetBoard
    char getTargetPiece(int row, int col);
};

#endif