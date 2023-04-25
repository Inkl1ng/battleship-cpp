#include "player.hpp"
#include "render.hpp"
#include "ship.hpp"
#include <iostream>
#include <array>

bool validCoordinate(int row, int col)
{
    if (row < 0 || row > 9)
    {
        return false;
    }
    else if (col < 0 || row > 9)
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
    std::array<Ship, 5> unplacedShips
    {
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
            if (!validCoordinate(rowInput, colInput)) {--placementResult;}
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
        player.addShip(ship);
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
    char skipInit {};
    std::cout << "Quick init (Y/N): ";
    std::cin >> skipInit;
    if (skipInit == 'n')
    {
        placeShips(player1, false);
        placeShips(player2, true);
    }
    else
    {
        Ship testShip1("PatrolBoat", 2);
        Ship testShip2("PatrolBoat", 2);

        testShip1.setLoc(4, 4);
        testShip1.setOrientation('v');
        testShip1.updateLocations();

        testShip2.setLoc(4, 4);
        testShip2.setOrientation('v');
        testShip2.updateLocations();

        player1.addShip(testShip1);
        player2.addShip(testShip2);
    }

    // main game loop
    char rowInput {};
    int colInput {};
    bool playing { true };
    char shotResult {};
    int inputResult {};
    bool sunkShip {};
    std::string targetShipType {};
    Ship* targetShip;
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
            colInput = Render::ask<int>("Column (1-10): ", false);
            --colInput;
            rowInput = Render::ask<char>("Row (A-J): ", false);
            rowInput = static_cast<int>(tolower(rowInput)) - 97;

            // check input
            if (!validCoordinate(rowInput, colInput)) 
            {
                --inputResult;
            }
            if ((player2.getOceanPiece(rowInput, colInput) == '#' ||
                player2.getOceanPiece(rowInput, colInput) == 'o'))
            {
                std::cout << "???\n";
                --inputResult;
            }

            if (inputResult < 0)
            {
                Render::message("Invalid input\n", false);
                inputResult = 0;
            }
            else
            {
                ++inputResult;
            }
        }

        // process input
        player1.shoot(rowInput, colInput, player2, false);
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
