cmake_minimum_required(VERSION 3.10)

project(battleship-cpp VERSION 1.0)

add_executable(battleship-cpp
    "src/main.cpp"
    "src/player.cpp"
    "src/render.cpp"
    "src/ship.cpp")

set(EXECUTABLE_OUTPUT_PATH ../bin)
