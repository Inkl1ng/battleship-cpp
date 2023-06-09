#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ship.hpp"
#include <iostream>
#include <string>
#include <array>
#include <vector>

// class to represent players
// contains name, boards, and ships
class Player
{
    public:
        // Player class constructor
        Player(const std::string &playerName);

        // returns reference to the player's name
        std::string & getName();

        // get piece at (row, col) in oceanBorad
        char getOceanPiece(int col, int row);

        // get piece at (row, col) in targetBoard
        char getTargetPiece(int col, int row);
        
        // gets a specific ship given the fist character of the ships's type
        std::vector<Ship>& getShips();

        void setOceanPiece(int col, int row, char piece);
        void setTargetPiece(int col, int row, char piece);

        // gets and validates shot inputs
        std::array<int, 2> shotInput(Player &target, bool isPlayer2);
        // hanldes shooting, player that is shooting will call this method,
        // will shoot at target
        void shoot(int col, int row, Player &target, bool isPlayer2);

        void addShip(Ship& newShip);
        void removeShip(Ship& targetShip);


    private:
        std::string name {};

        // represents where the player has placed their ships and where the
        // ships have been hit
        std::array<std::array<char, 10>, 10> oceanBoard {};

        // represents where the player has shot, hit, and missed
        std::array<std::array<char, 10>, 10> targetBoard {};

        std::vector<Ship> ships {};
};

#endif