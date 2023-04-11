#include "render.h"
#include "player.h"
#include <iostream>
#include <string>

// prints out [amount] number of whitespaces
void Render::whitespace(int amount)
{
    std::cout << ' ';
}

// prints out player 1 and 2's ocean and target boards
/*
board layout
[player 1 name]                                                     [player 2 name]
  1 2 3 4 5 6 7 8 9 10      1 2 3 4 5 6 7 8 9 10                      1 2 3 4 5 6 7 8 9 10      1 2 3 4 5 6 7 8 9 10
a - - - - - - - - - -     a - - - - - - - - - -                     a - - - - - - - - - -     a - - - - - - - - - -
b - - - - - - - - - -     b - - - - - - - - - -                     b - - - - - - - - - -     b - - - - - - - - - -
c - - - - - - - - - -     c - - - - - - - - - -                     c - - - - - - - - - -     c - - - - - - - - - - 
d - - - - - - - - - -     d - - - - - - - - - -                     d - - - - - - - - - -     d - - - - - - - - - - 
e - - - - - - - - - -     e - - - - - - - - - -                     e - - - - - - - - - -     e - - - - - - - - - - 
f - - - - - - - - - -     f - - - - - - - - - -                     f - - - - - - - - - -     f - - - - - - - - - - 
g - - - - - - - - - -     g - - - - - - - - - -                     g - - - - - - - - - -     g - - - - - - - - - - 
h - - - - - - - - - -     h - - - - - - - - - -                     h - - - - - - - - - -     h - - - - - - - - - - 
i - - - - - - - - - -     i - - - - - - - - - -                     i - - - - - - - - - -     i - - - - - - - - - -
j - - - - - - - - - -     j - - - - - - - - - -                     j - - - - - - - - - -     j - - - - - - - - - - 
                      ^^^                            ^^^
                      4 whitespaces                 20 whitespaces
1 player's side takes up 48 spaces
total = 2(48) + 20 = 116
player 1 name to player 2 name = 68 - player 1 name
*/
void Render::renderBoards(Player &player1, Player &player2)
{
    // gets data requried to render board
    std::string player1Name { player1.getName() };
    std::string player2Name { player2.getName() };
    
    std::array<std::array<char, 10>, 10> player1Ocean { player1.getOceanBoard() };
    std::array<std::array<char, 10>, 10> player1Target { player1.getTargetBoard() };
    std::array<std::array<char, 10>, 10> player2Ocean { player1.getOceanBoard() };
    std::array<std::array<char, 10>, 10> player2Target { player1.getTargetBoard() };

    // print out player names
    std::cout << player1Name;
    Render::whitespace(68 - player1Name.length());
    std::cout << player2Name;
    std::cout << '\n';
    std::cout << '  '; // prints out 2 whitesapces to create indent
    
    // render numbers
    int num {}; // using num twice for both loops
    for (num = 1; num < 11; ++num) // player 1 side numbers
    {
        std::cout << num << ' '; // whitespace after for spacing (looks better and less cramped)
    }
    Render::whitespace(20);
    for (num = 1; num < 11; ++num) // player 2 side numbers
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    // render rows
}