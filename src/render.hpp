#ifndef RENDER_HPP
#define RENDER_HPP

#include "player.hpp"
#include <iostream>
#include <string>

// contains functions to render the game
namespace Render
{
    // number of spaces from start of terminal column to start of p2 board
    const int player2Whitespace { 68 };

    // string containing all the letters of the alphabet
    const std::string ALPHABET { "abcdefghijklmnopqrstuvwxyz" };

    void message(const std::string &message, const bool isPlayer2);
    
    template <typename T>
    T ask(const std::string& message, const bool isPlayer2)
    {
        if (isPlayer2)
        {
            renderWhitespace(player2Whitespace);
        }
        std::cout << message;
        T input{};
        std::cin >> input;
        return input;
    }
    
    // prints out [amount] number of whitespaces
    void renderWhitespace(int amount);
    
    // prints out numbers (1-10)
    void renderNumberRow();
    
    // prints out row of a board ('o' for ocean, 't' for target)
    void renderBoardRow(Player &player, char type, int row);
    
    // renders a single ocean board
    void renderBoard(Player& player, bool isPlayer2);

    // prints out player 1 and 2's ocean and target boards
    void renderBoards(Player &player1, Player &player2);    
}

#endif
