#include "ship.hpp"
#include <iostream>
#include <array>
#include <vector>

std::vector<std::array<int, 2>>& Ship::getLocations()
{
    return this->locations;
}

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

int main()
{
    std::cout << "Hello\n";
    Ship testShip ('c', {5, 5}, 'h', 3);
    std::cin.ignore();
    return 0;
}
