#include "ship.hpp"
#include "types.hpp"
#include <iostream>
#include <array>
#include <vector>

Ship::Ship(char type, std::array<int, 2> loc, char orientation, int size)
{
    this->type = type;
    this->loc = loc;
    this->orientation = orientation;
    this->size = size;

    // calculate locations
    int colOrigin { loc[0] };
    int rowOrigin { loc[1] };
    switch (orientation)
    {
        case 'h':
            for (int row { rowOrigin }; row < rowOrigin + this->size; ++row)
            {
                this->locations.push_back({row, colOrigin});
            }
            break;
        case 'v':
            for (int col { colOrigin}; col < colOrigin + this->size; ++col)
            {
                this->locations.push_back({col, rowOrigin});
            }
            break;
    }
}

std::vector<std::array<int, 2>>& Ship::getLocations()
{
    return this->locations;
}

bool Ship::shootAt(Point shot)
{
    // update locations
    for (int index { 0 }; index < this->locations.size(); ++index)
    {
        if (shot == this->locations[index])
        {
            locations.erase(index + this->locations.begin());
        }
    }

    // checck if all the locations are sunk
    if (sizeof(this->locations) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}