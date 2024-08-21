
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include <string.h>

void bind_constants(lua_State *L);
void bind_structs(lua_State *L);
void bind_input_module(lua_State *L);
void bind_window_module(lua_State *L);
void bind_graphics2d_module(lua_State *L);

void l_Vector2_push(lua_State *L, Vector2 vector2);
void l_Vector3_push(lua_State *L, Vector3 vector3);
void l_Vector4_push(lua_State *L, Vector4 vector4);
void l_Matrix_push(lua_State *L, Matrix matrix);
void l_Rectangle_push(lua_State *L, Rectangle rectangle);
void l_Color_push(lua_State *L, Color color);
void l_Camera2D_push(lua_State *L, Camera2D camera2d);
