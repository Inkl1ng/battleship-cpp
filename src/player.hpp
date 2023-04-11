#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <array>

class Player
{
    std::string name{};
    // 2d std::array to represent boards
    std::array<std::array<char, 10>, 10> targetBoard {};

public:
    Player(std::string playerName);

    std::array<std::array<char, 10>, 10> oceanBoard {};
    std::array<std::array<char, 10>, 10> & getOceanBoard();
    std::array<std::array<char, 10>, 10> & getTargetBoard();
    std::string & getName();
};

#endif