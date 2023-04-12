#include "ship.hpp"
#include <iostream>

Ship::Ship(char type, std::array<int, 2> loc, char orientation, int size)
{
    this->type = type;
    this->loc = loc;
    this->orientation = orientation;
    // this->size = size;
}