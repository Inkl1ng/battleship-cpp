#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <array>

class Ship
{
    public:
        // ship class constructor
        Ship(char type, std::array<int, 2> loc, char orientation, int size);
    private:
        char type {};
        std::array<int, 2> loc {};
        char orientation {}; // 'h' for horizontal, 'v' for vertical

};

#endif