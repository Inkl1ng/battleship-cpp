#ifndef SHIP_HPP
#define SHIP_HPP

#include "types.hpp"
#include <iostream>
#include <array>
#include <vector>

class Ship
{
    public:
        // ship class constructor
        Ship(char type, std::array<int, 2> loc, char orientation, int size);

        std::vector<std::array<int, 2>>& getLocations();
        // returns true if ship was sunk by shot
        bool shootAt(Point);
    private:
        char type {};
        Point loc {}; // (x, y) or (col, row)
        char orientation {}; // 'h' for horizontal, 'v' for vertical
        int size {};

        std::vector<Point> locations {};
};

#endif