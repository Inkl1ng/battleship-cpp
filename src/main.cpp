#include "player.hpp"
#include "render.hpp"
#include <iostream>

// handles main gameloop
bool play_battleship()
{
    // ask for names
    std::cout << "Player 1, enter your name: ";
    std::string player1Name {};
    std::cin >> player1Name;
    std::cout << "Player 2, enter your name: ";
    std::string player2Name {};
    std::cin >> player2Name;

    const std::string player1Text = "[" + player1Name + "]";
    const std::string player2Text = "[" + player2Name + "]";

    // create players
    Player player1(player1Name);
    Player player2(player2Name);

    // main game loop
    char row {};
    int col {};
    bool playing { true };
    bool validInput { false };
    while (playing)
    {
        // render 
        Render::renderBoards(player1, player2);
        while (!validInput)
        {
            // get input
            std::cout << player1Text + " which row: ";
            std::cin >> row;
            row = static_cast<int>(tolower(row)) - 97; // subtracting 97 to get the row number that the char corresponds with
            std::cout << player1Text + " which col: ";
            std::cin >> col;
            col--; // rows go from 1-10 but array is 0-9
            // validate input
            if (row < 0 || row > 9)
            {
                validInput = false;
            }
            else if (col < 0 || col > 9)
            {
                validInput = false;
            }
            else
            {
                validInput = true;
            }
        }
        // process input

        // check if the game has ended

        // repeat
    }
    
    std::cout << "Keep playing (Y/N)?: ";
    char keepPlaying {};
    std::cin >> keepPlaying;

    if (tolower(keepPlaying) == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::cout << "Battleship!\n\n";
    std::cout << "Play game (Y/N)?: ";
    char play_game;
    std::cin >> play_game;

    bool keepPlaying { true };

    while (keepPlaying)
    {
        if (tolower(play_game) == 'y')
        {
            keepPlaying = play_battleship();
        }
    }

    std::cout << "See you next time!\n";
    std::cout << "press ENTER to exit...\n";
    std::cin.ignore();
    return 0;
}
