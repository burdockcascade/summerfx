#include <lua.hpp>
#include <raylib.h>
#include <string.h>

void bind_structs(lua_State *L);

void l_Vector2_push(lua_State *L, const Vector2 &vector2);
void l_Rectangle_push(lua_State *L, const Rectangle &rectangle);
void l_Color_push(lua_State *L, const Color &color);