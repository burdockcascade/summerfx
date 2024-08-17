#include <iostream>
#include <string>

#include <raylib.h>
#include <lua.hpp>

#include "modules/color.hpp"
#include "modules/math.hpp"
#include "modules/window.hpp"
#include "modules/graphics2d.hpp"

int main(int argc, char** argv) {

    std::string executableName;
    std::string fileToLoad;

    switch (argc) {
        case 0:
            executableName = "tinyengine";
            fileToLoad = "main.lua";
            break;
        case 1:
            executableName = argv[0];
            fileToLoad = "main.lua";
            break;
        default:
            executableName = argv[0];
            fileToLoad = argv[1];
            break;
    }

    if (!FileExists(fileToLoad.c_str())) {
        std::cout << "Usage:" << std::endl << "    " << GetFileName(executableName.c_str()) << " myfile.lua" << std::endl << std::endl;
        std::cout << "Attempted file " << fileToLoad << " was not found." << std::endl;
        return 1;
    }

    if (!IsFileExtension(fileToLoad.c_str(), ".lua")) {
        std::cout << "Expected file to be a .lua file." << std::endl;
        return 1;
    }

    // Initialize Lua
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // Bind modules
    bind_color_module(L);
    bind_math_module(L);
    bind_window_module(L);
    bind_graphics2d_module(L);

    // Load and execute the Lua file
    if (luaL_dofile(L, fileToLoad.c_str())) {
        std::cerr << "Error loading file: " << lua_tostring(L, -1) << std::endl;
        lua_pop(L, 1);
    }

}
