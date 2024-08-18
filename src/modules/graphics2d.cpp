#include "graphics2d.hpp"

// Draw Text
// --@function DrawText
// --@description Draw text using font inside rectangle limits
// --@param string text The text to draw
// --@param int X The x position
// --@param int Y The y position
// --@param int FontSize The font size
// --@param Color Color The color of the text
// --@return void
static int graphics2d_draw_text(lua_State *L) {
    const char* text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    int size = luaL_checkinteger(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawText(text, x, y, size, c);
    return 0;
}

void bind_graphics2d_module(lua_State *L) {

    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Graphics2D");

    lua_pushcfunction(L, graphics2d_draw_text);
    lua_setfield(L, -2, "DrawText");

}