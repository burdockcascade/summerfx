#include <raylib.h>
#include <lua.h>

#include "modules/modules.h"

int main(int argc, char** argv) {

    const char* fileToLoad = argv[1];

    if (!FileExists(fileToLoad)) {
        TraceLog(LOG_ERROR, "File not found: %s", fileToLoad);
        return 1;
    }

    if (!IsFileExtension(fileToLoad, ".lua")) {
        TraceLog(LOG_ERROR, "File is not a Lua file: %s", fileToLoad);
        return 1;
    }

    // Initialize Lua
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    // Bind modules
    bind_constants(L);
    bind_structs(L);
    bind_input_module(L);
    bind_window_module(L);
    bind_graphics2d_module(L);

    // Load and execute the Lua file
    if (luaL_dofile(L, fileToLoad)) {
        TraceLog(LOG_ERROR, "Error loading file: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
    }

    return 0;

}
