#ifndef TYPES_HPP
#define TYPES_HPP

#include <array>

// a single point on a 2d grid
using Point = std::array<int, 2>;
// 2d std::array of ints
using Board = std::array<std::array<char, 10>, 10>;

#endif