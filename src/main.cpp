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

    // create players
    Player player1(player1Name);
    Player player2(player2Name);

    // main game loop
    bool playing { true };
    while (playing)
    {
        // render 
        
        // get input

        // validate input

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