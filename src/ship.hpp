#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <array>
#include <vector>
#include <string>

class Ship
{
    public:
        // ship class constructor
        Ship(std::string type, int size);

        std::vector<std::array<int, 2>>& getLocations();
        // returns true if ship was sunk by shot
        bool shootAt(int col, int row);
        void setLoc(int col, int row);
        void setOrientation(char newOreination);
        std::string& getType();
        void updateLocations();;

    private:
        std::string type {0, 0};
        std::array<int, 2> loc {}; // (x, y) or (col, row)
        char orientation {'h'}; // 'h' for horizontal, 'v' for vertical
        int size {};

        std::vector<std::array<int, 2>> locations{};
};

#endif