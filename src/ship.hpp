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
        Ship(std::string newType, int newSize);

        int getSize();
        std::string& getType();
        std::vector<std::array<int, 2>>& getLocations();

        void setLoc(int col, int row);
        void setOrientation(char newOreination);

        // returns true if ship was sunk by shot        
        bool shootAt(int shotCol, int shotRow);
        void updateLocations();

    private:
        std::string type {};
        std::array<int, 2> loc {0, 0}; // (x, y) or (col, row)
        char orientation {'h'}; // 'h' for horizontal, 'v' for vertical
        int size {};
        std::vector<std::array<int, 2>> locations{};
};

#endif