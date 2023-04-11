#ifndef RENDER_H
#define RENDER_H

#include "player.hpp"
#include <iostream>

namespace Render
{
    const std::string ALPHABET { "abcdefghijklmnopqrstuvwxyz" }; 
    void whitespace(int amount);
    void renderBoards(Player &player1, Player &player2);
}


#endif