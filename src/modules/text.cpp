#include "modules.hpp"

// =====================================================================
// Strings

// Text Format
// -- @function TextFormat
// -- @description Format text with variables
// -- @param format The format string
// -- @param ... The variables to format
// -- @returns The formatted string
int l_TextFormat(lua_State *L) {
    const char* format = luaL_checkstring(L, 1);

    // Get the number of arguments
    int n = lua_gettop(L);
    

}
