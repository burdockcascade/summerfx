#include "modules.h"

// GetRandomValue
// -- @function GetRandomValue
// -- @description Get a random value between min and max
// -- @param min The minimum value
// -- @param max The maximum value
// -- @returns The random value
int math_get_random_value(lua_State *L) {
    int min = luaL_checkinteger(L, 1);
    int max = luaL_checkinteger(L, 2);

    int result = GetRandomValue(min, max);

    lua_pushinteger(L, result);

    return 1;
}

void bind_math_module(lua_State *L) {

    // Create a table
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "RMath");

    // GetRandomValue
    lua_pushcfunction(L, math_get_random_value);
    lua_setfield(L, -2, "GetRandomValue");

}
