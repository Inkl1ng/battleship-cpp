#include "ship.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <string>

Ship::Ship(std::string type, int size)
{
    this->type = type;
    this->size = size;
}

std::vector<std::array<int, 2>>& Ship::getLocations()
{
    return this->locations;
}

bool Ship::shootAt(int col, int row)
{
    return false;
}

void Ship::setLoc(int col, int row)
{
    this->loc[0] = col;
    this->loc[1] = row;
}

void Ship::setOrientation(char newOrientation)
{
    this->orientation = newOrientation;
}

std::string& Ship::getType()
{
    return this->type;
}

void Ship::updateLocations()
{
    this->locations.clear();
    int colOrigin{ loc[0] };
    int rowOrigin{ loc[1] };

    switch (orientation)
    {
        case 'h':
            for (int row{ rowOrigin }; row < rowOrigin + this->size; ++row)
            {
                this->locations.push_back({ colOrigin, row });
            }
            break;
        case 'v':
            for (int col{ colOrigin }; col < colOrigin + this->size; ++col)
            {
                this->locations.push_back({ col, rowOrigin });
            }
            break;
    }
}
