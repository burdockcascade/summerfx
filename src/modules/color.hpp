#include <lua.hpp>
#include <raylib.h>
#include <string.h>

void bind_color_module(lua_State *L);
void l_Color_push(lua_State *L, const Color &color);