#include "ship.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <string>

Ship::Ship(std::string newType, int newSize)
{
    type = newType;
    size = newSize;
}

int Ship::getSize()
{
    return size;
}

std::string& Ship::getType()
{
    return type;
}

std::vector<std::array<int, 2>>& Ship::getLocations()
{
    return locations;
}

void Ship::setLoc(int newCol, int newRow)
{
    loc[0] = newCol;
    loc[1] = newRow;
}

void Ship::setOrientation(char newOrientation)
{
    orientation = newOrientation;
}

bool Ship::shootAt(int shotCol, int shotRow)
{
    int col { loc[0] };
    if (orientation == 'h')
    {
        locations.erase(shotCol - loc[0] + locations.begin());
    }
    else if (orientation == 'v')
    {
        locations.erase(loc[1] - shotRow + locations.begin());
    }
    return false;
}

void Ship::updateLocations()
{
    locations.clear();
    int colOrigin { loc[0] };
    int rowOrigin { loc[1] };

    switch (orientation)
    {
        case 'h':
            for (int newCol{ colOrigin }; newCol < colOrigin + size; ++newCol)
            {
                locations.push_back({rowOrigin, newCol});
            }
            break;
        case 'v':
            for (int newRow{ rowOrigin }; newRow > rowOrigin - size; --newRow)
            {
                locations.push_back({colOrigin, newRow});
            }
            break;
    }
}
