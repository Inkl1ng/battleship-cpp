#include "render.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

void Render::message(const std::string &message, const bool isPlayer2)
{
    if (isPlayer2)
    {
        Render::renderWhitespace(Render::player2Whitespace);
    }
    std::cout<< message;
}

void Render::renderWhitespace(int amount)
{
    for (int x { 0 }; x < amount; ++x)
    {
        std::cout << ' ';
    }
}

void Render::renderNumberRow()
{
    for (int num { 1 }; num < 11; ++num)
    {
        std::cout << num << ' ';
    }
}

void Render::renderBoardRow(Player &player, char type, int row)
{
    char tile {};
    int castedTile {};
    // prints out letters on side
    std::cout << Render::ALPHABET[row] << ' ';
    for (int col { 0 }; col < 10; ++col)
    {
        if (type == 'o')
        {
            tile = player.getOceanPiece(row, col);

            if (isupper(tile) || tile == '.' || tile == 'o')
            {
                std::cout << tile;
            }
            else
            {
                std::cout << '#';
            }
        }
        else if (type == 't')
        {
            std::cout << player.getTargetPiece(row, col);
        }
        std::cout << ' ';
    }
}

/*
Board layout

Ocean
  1 2 3 4 5 6 7 8 9 10
a - - - - - - - - - -
b - - - - - - - - - -
c - - - - - - - - - -
d - - - - - - - - - -
e - - - - - - - - - -
f - - - - - - - - - -
g - - - - - - - - - -
h - - - - - - - - - -
i - - - - - - - - - -
j - - - - - - - - - -
*/

void Render::renderBoard(Player& player, bool isPlayer2)
{
    // print out ocean text
    // following snippet prints makes all the text be printed on p2's side 
    // when needed
    if (isPlayer2) { Render::renderWhitespace(Render::player2Whitespace); }
    Render::message("Ocean\n", isPlayer2);

    // print out number row
    if (isPlayer2) { Render::renderWhitespace(Render::player2Whitespace); }
    Render::renderWhitespace(2);
    Render::renderNumberRow();
    std::cout << '\n';
    
    for (int row{ 0 }; row < 10; ++row)
    {
        if (isPlayer2) { Render::renderWhitespace(Render::player2Whitespace); }
        renderBoardRow(player, 'o', row);
        std::cout << '\n';
    }
}

/*
board layout
[player 1 name]                                                     [player 2 name]
Ocean                     Target                                    Ocean                     Target
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

    // print out player names
    std::cout << player1Name;
    Render::renderWhitespace(68 - player1Name.length());
    std::cout << player2Name << '\n';
    std::cout << ' ' << ' '; // prints out 2 whitesapces to create indent
    
    // render board titles
    std::cout << "Ocean";
    Render::renderWhitespace(21);
    std::cout << "Target";
    Render::renderWhitespace(36);
    std::cout << "Ocean";
    Render::renderWhitespace(21);
    std::cout << "Target\n";

    // render numbers
    Render::renderWhitespace(2);
    Render::renderNumberRow();
    Render::renderWhitespace(5);
    Render::renderNumberRow();
    Render::renderWhitespace(21);
    Render::renderNumberRow();
    Render::renderWhitespace(5);
    Render::renderNumberRow();
    std::cout << '\n';


    // render rows
    int col {};
    for (int row{ 0 }; row < 10; ++row)
    {
        // player 1 ocean
        Render::renderBoardRow(player1, 'o', row);
        // player 1 target
        Render::renderWhitespace(4);
        Render::renderBoardRow(player1, 't', row);
        // player 2 ocean
        Render::renderWhitespace(20);
        Render::renderBoardRow(player2, 'o', row);
        // player 2 target
        Render::renderWhitespace(4);
        Render::renderBoardRow(player2, 't', row);
        std::cout << '\n';
    }
}
