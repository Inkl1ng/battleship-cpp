# battleship-cpp
a battleship game in C++

My introductory CS teacher had our class make a battleship game in Python. He provided some starting code so we didn't have to write the whole thing ourselves but it was still fun nevertheless. I'm looking to use C++ to try out some game development (Raylib in particular) so I thought it would be good practice to recreate this battleship game I did in Python in C++ to get a hold of the language. This is also some practice with working with git and github writing good commit messages which I'll use who knows when.

## Building and Running (I think?)
I've been primarily using VSCode for writing this project so I'm also using the integrated commands to build and run this project. In the `tasks.json` file for specifying commands I put the following text under the `"args"` flag. I don't know if this is the best way to do this but as of writing this this isn't a big enough concern to me to go through configuring CMake and all the other stuff.

If you just want to build/compile the project without running you can use the shortcut `CTRL+SHIFT+B` (in VSCode).

For Windows:
```
"-fdiagnostics-color=always",
"-g",
"${workspaceFolder}\\src\\*.cpp",
"-o",
"${workspaceFolder}\\bin\\battleship.exe"
```

For other:
```
"-fdiagnostics-color=always",
"-g",
"${workspaceFolder}/src/*.cpp",
"-o",
"${workspaceFolder}/bin/battleship.exe"
```
It's the same text but the slashes are different because windows uses backslashes while other OS's use forwardslashes.

If you want to use CMake then just run `cmake ..` and then `make` in your terminal in the `/build/` folder. The resulting `battleship` program will be outputted in the `/bin/` folder. It will use the `CMakeLists.txt` file. IDK if its good but this is my first time using CMake.
