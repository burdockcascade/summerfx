#include "modules.h"

// =====================================================================
// Strings

// Text Format
// -- @function TextFormat
// -- @description Format text with variables
// -- @param format The format string
// -- @param ... The variables to format
// -- @returns The formatted string
int text_format(lua_State *L) {
    const char* format = luaL_checkstring(L, 1);
    int nargs = lua_gettop(L) - 1;

    const char *result;

    switch (nargs) {
        case 0:
            result = TextFormat(format);
            break;
        case 1:
            result = TextFormat(format, luaL_checkinteger(L, 2));
            break;
        case 2:
            result = TextFormat(format, luaL_checkstring(L, 2), luaL_checkstring(L, 3));
            break;
        case 3:
            result = TextFormat(format, luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkstring(L, 4));
            break;
        case 4:
            result = TextFormat(format, luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkstring(L, 4), luaL_checkstring(L, 5));
            break;
        case 5:
            result = TextFormat(format, luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkstring(L, 4), luaL_checkstring(L, 5), luaL_checkstring(L, 6));
            break;
        case 6:
            result = TextFormat(format, luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkstring(L, 4), luaL_checkstring(L, 5), luaL_checkstring(L, 6), luaL_checkstring(L, 7));
            break;
        default:
            luaL_error(L, "Too many arguments to Text.Format");
            break;
    }

    // Push the result to the stack
    lua_pushstring(L, result);

    return 1;

}

void bind_text_module(lua_State *L) {

    // Create a table
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Text");

    // Text Format
    lua_pushcfunction(L, text_format);
    lua_setfield(L, -2, "Format");

    // pop
    lua_pop(L, 1);
}
