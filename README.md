# battleship-cpp
a battleship game in C++

My introductory CS teacher had our class make a battleship game in Python. He provided some starting code so we didn't have to write the whole thing ourselves but it was still fun nevertheless. I'm looking to use C++ to try out some game development (Raylib in particular) so I thought it would be good practice to recreate this battleship game I did in Python in C++ to get a hold of the language. This is also some practice with working with git and github writing good commit messages which I'll use who knows when.

## Building and Running (I think?)
I've been primarily using VSCode for writing this project so I'm also using the integrated commands to build and run this project. In the `tasks.json` file for specifying commands I put the following text under the ```"args"``` flag. I don't know if this is the best way to do this but as of writing this this isn't a big enough concern to me to go through configuring CMake and all the other stuff
```
"-fdiagnostics-color=always",
"-g",
"${workspaceFolder}\\src\\*.cpp",
"-o",
"${workspaceFolder}\\bin\\battleship.exe"
```
