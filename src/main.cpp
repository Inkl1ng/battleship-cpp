#include "player.hpp"
#include "render.hpp"
#include "ship.hpp"
#include <iostream>
#include <array>

void placeShips(Player &player, bool isPlayer2)
{
    std::array<Ship, 5> unplacedShips {
        Ship("Carrier", 5),
        Ship("Destroyer", 4),
        Ship("Battleship", 3),
        Ship("Submarine", 3),
        Ship("PatrolBoat", 2)
    };

    int rowInput;
    int colInput;
    int row {};
    int col {};
    char orientationInput {};
    // initialized at zero, decremented if there's issues with placement, 
    // incremented if placement works
    int placementResult {};
    for (Ship ship : unplacedShips)
    {
        placementResult = 0;

        // render board
        Render::renderBoard(player, isPlayer2);
        std::cout << '\n';
        // converts size (int) of ship to a character for message
        char convertedSize = static_cast<char>(ship.getSize() + 48);
        // [Ship type] (Size: x) placement
        Render::message(ship.getType() + " (size: " + convertedSize + 
            ") placement\n", isPlayer2);

        while (placementResult == 0)
        {
            // get inputs
            colInput = Render::ask<int>("Column (1-10): ", isPlayer2);
            --colInput; // board arrays go from 0-9 not 1-10
            rowInput = Render::ask<char>("Row (A-J): ", isPlayer2);

            // gets the corresponding row for a character
            rowInput = static_cast<int>(tolower(rowInput)) - 97;
            orientationInput = Render::ask<char>("Orientation (h or v): ",
                isPlayer2);
            orientationInput = tolower(orientationInput);

            // update ship locations
            ship.setLoc(colInput, rowInput);
            ship.setOrientation(orientationInput);
            ship.updateLocations();

            // check if the inputs are valid
            std::cout << rowInput << ' ' << colInput << ' ' << orientationInput
                << '\n';
            if (rowInput < 0 || rowInput > 9) {--placementResult;}
            if (colInput < 0 || colInput > 9) {--placementResult;}
            if (!(orientationInput == 'h' || orientationInput == 'v'))
                {--placementResult;}

            // check if there will be ships in the way or 
            // if the ship will extend out of the board
            for (std::array<int, 2> location : ship.getLocations())
            {
                row = location[1];
                col = location[0];
                if (player.getOceanPiece(col, row) != '.')
                {
                    --placementResult;

                }
                else if (row < 0 || col > 10)
                {
                    --placementResult;
                }
            }
            
            std::cout << placementResult << '\n';
            if (placementResult < 0)
            {
                Render::message("Invalid input!\n", isPlayer2);
                placementResult = 0; // resets to keep the while loop going
            }
            else
            {
                ++placementResult;
            }
        }
        // place ships onto oceanBoard
        for (std::array<int, 2> location : ship.getLocations())
        {
            row = location[1];
            col = location[0];
            player.setOceanPiece(col, row, ship.getType()[0]);
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
    char rowInput {};
    int colInput {};
    bool playing { true };
    int inputResult {};
    // 0 gets converted to false
    // 1 gets converted to true
    int turn { 0 };

    // a lot of the following code is similar to the code in placeShips()
    // refer to line 7-100 (wow long function!) in this file
    while (playing)
    {
        // render
        inputResult = 0;
        Render::renderBoards(player1, player2);
        
        while (inputResult == 0)
        {
            // get input
            colInput = Render::ask<int>("Column (1-10): ", turn);
            --colInput;
            rowInput = Render::ask<int>("Row (A-J): ", turn);
            rowInput = static_cast<int>(tolower(rowInput)) - 97;

            // check input
            if (rowInput < 0 || rowInput > 9) {--inputResult;}
            if (colInput < 0 || colInput > 9) {--inputResult;}

            if (player1.getOceanPiece(colInput, rowInput) != '.') {--inputResult;}

            if (inputResult < 0)
            {
                Render::message("Invalid input\n", turn);
            }
            else
            {
                ++inputResult;
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
    bool keepPlaying { true };

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
