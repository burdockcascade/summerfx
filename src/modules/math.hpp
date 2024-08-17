#include <lua.hpp>
#include <raylib.h>
#include <string.h>

void bind_math_module(lua_State *L);
void l_Vector2_push(lua_State *L, const Vector2 &vector2);