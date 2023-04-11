#include "player.hpp"
#include <iostream>

Player::Player(std::string playerName)
{
    this->name = playerName;

    for (int row { 0 }; row < 10; ++row)
    {
        for (int col { 0 }; col < 10; ++col)
        {
            this->targetBoard[row][col] = '-';
            this->oceanBoard[row][col] = '-';
        }
    }
}

// returns reference to oceanBoard
std::array<std::array<char, 10>,  10> & Player::getOceanBoard()
{
    return this->oceanBoard;
}

// returns reference to oceanBoard
std::array<std::array<char, 10>, 10> & Player::getTargetBoard()
{
    return this->targetBoard;
}

std::string& Player::getName()
{
    return this->name;
}

// testing Player class methods
int main()
{
    Player testPlayer("John");
    
    int a { 5 };
    std::array<std::array<char, 10>, 10> board = testPlayer.getOceanBoard();
    
    for (int row { 0 }; row < 10; ++row)
    {
        for (int col { 0 }; col < 10; ++col)
        {
            std::cout << board[row][col] << ' ';
        }
        std::cout << '\n';
    }
}
