#ifndef RENDER_HPP
#define RENDER_HPP

#include "player.hpp"
#include <iostream>

// contains functions to render the game
namespace Render
{
    // string containing all the letters of the alphabet
    const std::string ALPHABET { "abcdefghijklmnopqrstuvwxyz" };
    // prints out [amount] number of whitespaces
    void renderWhitespace(int amount);
    // prints out numbers (1-10)
    void renderNumberRow();
    // prints out row of a board ('o' for ocean, 't' for target)
    void renderBoardRow(Player &player, char type, int row);
    // prints out player 1 and 2's ocean and target boards
    void renderBoards(Player &player1, Player &player2);
}


#endif