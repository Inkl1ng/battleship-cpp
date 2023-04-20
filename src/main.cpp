#include "player.hpp"
#include "render.hpp"
#include "ship.hpp"
#include <iostream>

bool checkInput(int input)
{
    if (input < 0 || input > 10)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void placeShips(Player &player, bool isPlayer2)
{
    std::array<Ship, 5> unplacedShips {
        Ship("carrier", 5),
        Ship("battleship", 4),
        Ship("destroyer", 3),
        Ship("submarine", 3),
        Ship("patrol boat", 2)
    };

    int rowInput{};
    int colInput{};
    char orientationInput{};
    bool validPlacement{ false };
    std::string placementMessage{};

    for (int i{ 0 }; i < 5; ++i)
    {
        // render board
        Render::renderBoard(player, isPlayer2);
        // get placements
        placementMessage = unplacedShips[i].getType() + " placement\n";
        Render::message(placementMessage, isPlayer2);
        while (!validPlacement)
        {
            rowInput = Render::ask<int>("Row (1-10): ", isPlayer2) - 1;
            colInput = Render::ask<int>("Column (1-10): ", isPlayer2) - 1;
            orientationInput = Render::ask<char>("Orientation ('h' or 'v'): ", isPlayer2);
            orientationInput = tolower(orientationInput);

            // validate placements
            // legal row/col
            validPlacement = checkInput(rowInput);
            // this repeated snippet breaks the loop is one of the inputs is bad
            if (!validPlacement) { std::cout << "Invalid inputs!\n"; continue; }
            validPlacement = checkInput(colInput);
            if (!validPlacement) { std::cout << "Invalid inputs!\n"; continue; }
            
            // valid orientation (either h or v)
            validPlacement = orientationInput == 'h' or orientationInput == 'v';
            if (!validPlacement) { std::cout << "Invalid inputs!\n"; continue; }
            
            // check if there are already ships there
            unplacedShips[i].setLoc(colInput, rowInput);
            unplacedShips[i].setOrientation(orientationInput);
            unplacedShips[i].updateLocations();

            for (std::array<int, 2> location : unplacedShips[i].getLocations())
            {
                validPlacement = player.getOceanPiece(location[0], location[1]) != '.';
                if (!validPlacement) { std::cout << "Invalid inputs!\n"; continue; }
            }
        }
    }
}

// handles main gameloop
bool playBattleship()
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

    // place ships
    placeShips(player1, false);
    placeShips(player2, true);

    // main game loop
    char row{};
    int col{};
    bool playing{ true };
    bool validInput{ false };
    while (playing)
    {
        // render
        Render::renderBoards(player1, player2);
        while (!validInput)
        {
            // get input
            std::cout << player1Text + " which row: ";
            std::cin >> row;
            // subtracting 97 to get the row number that the char corresponds with
            row = static_cast<int>(tolower(row)) - 97;
            std::cout << player1Text + " which col: ";
            std::cin >> col;
            col--; // rows go from 1-10 but array is 0-9

            // validate input for valid location
            validInput = checkInput(row);
            validInput = checkInput(col);

            // check if the player has already shot where they want to shoot
            if (player1.getTargetPiece(row, col) == '.')
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
    char playGame;
    std::cin >> playGame;
    playGame = tolower(playGame);
    bool keepPlaying{ true };

    while (keepPlaying)
    {
        if (tolower(playGame) == 'y')
        {
            keepPlaying = playBattleship();
        }
        else
        {
            keepPlaying = false;
        }
    }

    std::cout << "See you next time!\n";
    std::cout << "press ENTER to exit...\n";
    std::cin.ignore();
    return 0;
}
