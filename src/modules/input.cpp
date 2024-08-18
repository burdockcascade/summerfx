#include "input.hpp"

// Is Key Pressed
// --@function IsKeyPressed
// --@description Check if a key has been pressed once
// --@param key int The key to check
// --@return bool If the key has been pressed
int input_is_key_pressed(lua_State *L) {
    int key = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsKeyPressed(key));
    return 1;
}

// Is Key Pressed Repeat
// --@function IsKeyPressedRepeat
// --@description Check if a key has been pressed and is being held down
// --@param key int The key to check
// --@return bool If the key has been pressed and is being held down
int input_is_key_pressed_repeat(lua_State *L) {
    int key = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsKeyDown(key));
    return 1;
}

// Is Key Down
// --@function IsKeyDown
// --@description Check if a key is being held down
// --@param key int The key to check
// --@return bool If the key is being held down
int input_is_key_down(lua_State *L) {
    int key = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsKeyDown(key));
    return 1;
}

// Is Key Released
// --@function IsKeyReleased
// --@description Check if a key has been released
// --@param key int The key to check
// --@return bool If the key has been released
int input_is_key_released(lua_State *L) {
    int key = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsKeyReleased(key));
    return 1;
}

// Is Key Up
// --@function IsKeyUp
// --@description Check if a key is not being held down
// --@param key int The key to check
// --@return bool If the key is not being held down
int input_is_key_up(lua_State *L) {
    int key = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsKeyUp(key));
    return 1;
}

// Get Key Pressed
// --@function GetKeyPressed
// --@description Get the last key pressed
// --@return int The last key pressed
int input_get_key_pressed(lua_State *L) {
    lua_pushinteger(L, GetKeyPressed());
    return 1;
}

// Get Char Pressed
// --@function GetCharPressed
// --@description Get the last char pressed
// --@return int The last char pressed
int input_get_char_pressed(lua_State *L) {
    lua_pushinteger(L, GetCharPressed());
    return 1;
}

// Is Mouse Button Pressed
// --@function IsMouseButtonPressed
// --@description Check if a mouse button has been pressed once
// --@param button int The button to check
// --@return bool If the button has been pressed
int input_is_mouse_button_pressed(lua_State *L) {
    int button = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsMouseButtonPressed(button));
    return 1;
}

// Is Mouse Button Down
// --@function IsMouseButtonDown
// --@description Check if a mouse button is being held down    
// --@param button int The button to check
// --@return bool If the button is being held down
int input_is_mouse_button_down(lua_State *L) {
    int button = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsMouseButtonDown(button));
    return 1;
}

// Is Mouse Button Released
// --@function IsMouseButtonReleased
// --@description Check if a mouse button has been released
// --@param button int The button to check
// --@return bool If the button has been released
int input_is_mouse_button_released(lua_State *L) {
    int button = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsMouseButtonReleased(button));
    return 1;
}

// Is Mouse Button Up
// --@function IsMouseButtonUp
// --@description Check if a mouse button is not being held down
// --@param button int The button to check
// --@return bool If the button is not being held down
int input_is_mouse_button_up(lua_State *L) {
    int button = luaL_checkinteger(L, 1);
    lua_pushboolean(L, IsMouseButtonUp(button));
    return 1;
}

// Get Mouse X
// --@function GetMouseX
// --@description Get the x position of the mouse
// --@return int The x position of the mouse
int input_get_mouse_x(lua_State *L) {
    lua_pushinteger(L, GetMouseX());
    return 1;
}

// Get Mouse Y
// --@function GetMouseY
// --@description Get the y position of the mouse
// --@return int The y position of the mouse
int input_get_mouse_y(lua_State *L) {
    lua_pushinteger(L, GetMouseY());
    return 1;
}

// Get Mouse Position
// --@function GetMousePosition
// --@description Get the position of the mouse
// --@return Vector2 The position of the mouse
int input_get_mouse_position(lua_State *L) {
    Vector2 v = GetMousePosition();
    l_Vector2_push(L, v);
    return 1;
}

// Set Mouse Position
// --@function SetMousePosition
// --@description Set the position of the mouse
// --@param x int The x position of the mouse
// --@param y int The y position of the mouse
// --@return void
int input_set_mouse_position(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    SetMousePosition(x, y);
    return 0;
}

// Set Mouse Offset
// --@function SetMouseOffset
// --@description Set the offset of the mouse
// --@param x int The x offset of the mouse
// --@param y int The y offset of the mouse
// --@return void
int input_set_mouse_offset(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    SetMouseOffset(x, y);
    return 0;
}

// Set Mouse Scale
// --@function SetMouseScale
// --@description Set the scale of the mouse
// --@param x int The x scale of the mouse
// --@param y int The y scale of the mouse
// --@return void
int input_set_mouse_scale(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    SetMouseScale(x, y);
    return 0;
}

// Get Mouse Wheel Move
// --@function GetMouseWheelMove
// --@description Get the amount the mouse wheel has moved
// --@return int The amount the mouse wheel has moved
int input_get_mouse_wheel_move(lua_State *L) {
    lua_pushinteger(L, GetMouseWheelMove());
    return 1;
}

// Get Mouse Wheel Move
// --@function GetMouseWheelMoveV
// --@description Get the amount the mouse wheel has moved
// --@return Vector2 The amount the mouse wheel has moved
int input_get_mouse_wheel_move_v(lua_State *L) {
    Vector2 v = GetMouseWheelMoveV();
    l_Vector2_push(L, v);
    return 1;
}

// Set Mouse Cursor
// --@function SetMouseCursor
// --@description Set the mouse cursor
// --@param cursor int The cursor to set
// --@return void
int input_set_mouse_cursor(lua_State *L) {
    int cursor = luaL_checkinteger(L, 1);
    SetMouseCursor(cursor);
    return 0;
}

// Get Touch X
// --@function GetTouchX
// --@description Get the x position of a touc
// --@return int The x position of the touch
int input_get_touch_x(lua_State *L) {
    lua_pushinteger(L, GetTouchX());
    return 1;
}

// Get Touch Y
// --@function GetTouchY
// --@description Get the y position of a touch
// --@return int The y position of the touch
int input_get_touch_y(lua_State *L) {
    lua_pushinteger(L, GetTouchY());
    return 1;
}

// Get Touch Position
// --@function GetTouchPosition
// --@description Get the position of a touch
// --@param touch int The touch to get the position of
// --@return Vector2 The position of the touch
int input_get_touch_position(lua_State *L) {
    int touch = luaL_checkinteger(L, 1);
    Vector2 v = GetTouchPosition(touch);
    l_Vector2_push(L, v);
    return 1;
}

// Get Touch Point Id
// --@function GetTouchPointId
// --@description Get the id of a touch point
// --@param index int The index of the touch point
// --@return int The id of the touch point
int input_get_touch_point_id(lua_State *L) {
    int index = luaL_checkinteger(L, 1);
    lua_pushinteger(L, GetTouchPointId(index));
    return 1;
}

// Get Touch Point Count
// --@function GetTouchPointCount
// --@description Get the number of touch points
// --@return int The number of touch points
int input_get_touch_point_count(lua_State *L) {
    lua_pushinteger(L, GetTouchPointCount());
    return 1;
}

// Bindings
void bind_input_module(lua_State *L) {

    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Input");

    lua_pushcfunction(L, input_is_key_pressed);
    lua_setfield(L, -2, "IsKeyPressed");

    lua_pushcfunction(L, input_is_key_pressed_repeat);
    lua_setfield(L, -2, "IsKeyPressedRepeat");

    lua_pushcfunction(L, input_is_key_down);
    lua_setfield(L, -2, "IsKeyDown");

    lua_pushcfunction(L, input_is_key_released);
    lua_setfield(L, -2, "IsKeyReleased");

    lua_pushcfunction(L, input_is_key_up);
    lua_setfield(L, -2, "IsKeyUp");

    lua_pushcfunction(L, input_get_key_pressed);
    lua_setfield(L, -2, "GetKeyPressed");

    lua_pushcfunction(L, input_get_char_pressed);
    lua_setfield(L, -2, "GetCharPressed");

    lua_pushcfunction(L, input_is_mouse_button_pressed);
    lua_setfield(L, -2, "IsMouseButtonPressed");

    lua_pushcfunction(L, input_is_mouse_button_down);
    lua_setfield(L, -2, "IsMouseButtonDown");

    lua_pushcfunction(L, input_is_mouse_button_released);
    lua_setfield(L, -2, "IsMouseButtonReleased");

    lua_pushcfunction(L, input_is_mouse_button_up);
    lua_setfield(L, -2, "IsMouseButtonUp");

    lua_pushcfunction(L, input_get_mouse_x);
    lua_setfield(L, -2, "GetMouseX");

    lua_pushcfunction(L, input_get_mouse_y);
    lua_setfield(L, -2, "GetMouseY");

    lua_pushcfunction(L, input_get_mouse_position);
    lua_setfield(L, -2, "GetMousePosition");

    lua_pushcfunction(L, input_set_mouse_position);
    lua_setfield(L, -2, "SetMousePosition");

    lua_pushcfunction(L, input_set_mouse_offset);
    lua_setfield(L, -2, "SetMouseOffset");

    lua_pushcfunction(L, input_set_mouse_scale);
    lua_setfield(L, -2, "SetMouseScale");

    lua_pushcfunction(L, input_get_mouse_wheel_move);
    lua_setfield(L, -2, "GetMouseWheelMove");

    lua_pushcfunction(L, input_get_mouse_wheel_move_v);
    lua_setfield(L, -2, "GetMouseWheelMoveV");

    lua_pushcfunction(L, input_set_mouse_cursor);
    lua_setfield(L, -2, "SetMouseCursor");

    lua_pushcfunction(L, input_get_touch_x);
    lua_setfield(L, -2, "GetTouchX");

    lua_pushcfunction(L, input_get_touch_y);
    lua_setfield(L, -2, "GetTouchY");

    lua_pushcfunction(L, input_get_touch_position);
    lua_setfield(L, -2, "GetTouchPosition");

    lua_pushcfunction(L, input_get_touch_point_id);
    lua_setfield(L, -2, "GetTouchPointId");

    lua_pushcfunction(L, input_get_touch_point_count);
    lua_setfield(L, -2, "GetTouchPointCount");

    lua_pop(L, 1);

}