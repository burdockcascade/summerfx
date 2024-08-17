#include "window.hpp"

// Open Window
static int window_open(lua_State *L) {
    const char* title = luaL_checkstring(L, 1);
    int width = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    
    InitWindow(width, height, title);
    SetTargetFPS(60);

    return 0;
}

// IsOpen
static int window_is_open(lua_State *L) {
    lua_pushboolean(L, !WindowShouldClose());
    return 1;
}

// Close Window
static int window_close(lua_State *L) {
    CloseWindow();
    return 0;
}

void bind_window_module(lua_State *L) {
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Window");

    lua_pushcfunction(L, window_open);
    lua_setfield(L, -2, "Open");

    lua_pushcfunction(L, window_is_open);
    lua_setfield(L, -2, "IsOpen");

    lua_pushcfunction(L, window_close);
    lua_setfield(L, -2, "Close");

}