#include "window.hpp"

// Open Window
// --@function Open
// --@description Open a window with the specified title, width, and height.
// --@param title string The title of the window.   
// --@param width int The width of the window.
// --@param height int The height of the window.
// --@return void 
int window_open(lua_State *L) {
    const char* title = luaL_checkstring(L, 1);
    int width = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    
    InitWindow(width, height, title);
    SetTargetFPS(60);

    return 0;
}

// IsWindowReady
// --@function IsWindowReady
// --@description Check if the window is ready.
// --@return bool If the window is ready.
int window_is_ready(lua_State *L) {
    lua_pushboolean(L, IsWindowReady());
    return 1;
}

// Set Target FPS
// --@function SetTargetFPS
// --@description Set the target FPS of the window.
// --@param fps int The target FPS.
// --@return void
int window_set_target_fps(lua_State *L) {
    int fps = luaL_checkinteger(L, 1);
    SetTargetFPS(fps);
    return 0;
}

// Set Title
// --@function SetTitle
// --@description Set the title of the window.
// --@param title string The title of the window.
// --@return void
int window_set_title(lua_State *L) {
    const char* title = luaL_checkstring(L, 1);
    SetWindowTitle(title);
    return 0;
}

// IsOpen
// --@function IsOpen
// --@description Check if the window is open.
// --@return bool If the window is open.
int window_is_open(lua_State *L) {
    lua_pushboolean(L, !WindowShouldClose());
    return 1;
}

// Clear Background
// --@function ClearBackground
// --@description Clear the background with the specified color.
// --@param color Color The color to clear the background with.
// --@return void
int window_clear_background(lua_State *L) {
    Color c = *(Color*)luaL_checkudata(L, 1, "Color");
    ClearBackground(c);
    return 0;
}

// Draw FPS
// --@function DrawFPS
// --@description Draw the FPS at the specified position.
// --@param x int The x position to draw the FPS.
// --@param y int The y position to draw the FPS.
// --@return void
int window_draw_fps(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    DrawFPS(x, y);
    return 0;
}

// Begin Drawing
// --@function BeginDrawing
// --@description Begin drawing to the window.
// --@return void
int window_begin_drawing(lua_State *L) {
    BeginDrawing();
    return 0;
}

// End Drawing
// --@function EndDrawing
// --@description End drawing to the window.
// --@return void
int window_end_drawing(lua_State *L) {
    EndDrawing();
    return 0;
}

// GetWidth
// --@function GetWidth
// --@description Get the width of the window.
// --@return int The width of the window.
int window_get_width(lua_State *L) {
    lua_pushinteger(L, GetScreenWidth());
    return 1;
}

// GetHeight
// --@function GetHeight
// --@description Get the height of the window.
// --@return int The height of the window.
int window_get_height(lua_State *L) {
    lua_pushinteger(L, GetScreenHeight());
    return 1;
}

// IsWindowFullscreen
// --@function IsFullscreen
// --@description Check if the window is fullscreen.
// --@return bool If the window is fullscreen.
int window_is_fullscreen(lua_State *L) {
    lua_pushboolean(L, IsWindowFullscreen());
    return 1;
}

// IsWindowFocused
// --@function IsFocused
// --@description Check if the window is focused.
// --@return bool If the window is focused.
int window_is_focused(lua_State *L) {
    lua_pushboolean(L, IsWindowFocused());
    return 1;
}

// Minimize Window
// --@function Minimize
// --@description Minimize the window.
// --@return void
int window_minimize(lua_State *L) {
    MinimizeWindow();
    return 0;
}

// Maximize Window
// --@function Maximize
// --@description Maximize the window.
// --@return void
int window_maximize(lua_State *L) {
    MaximizeWindow();
    return 0;
}

// Get Window Position
// --@function GetPosition
// --@description Get the position of the window.
// --@return Vector2 The position of the window.
int window_get_position(lua_State *L) {
    Vector2 v;
    v.x = GetWindowPosition().x;
    v.y = GetWindowPosition().y;
    l_Vector2_push(L, v);
    return 1;
}

// Mouse Position
// --@function GetPosition
// --@description Returns the current mouse position
// --@return Vector2 The current mouse position 
static int mouse_get_position(lua_State *L) {
    Vector2 result = GetMousePosition();
    l_Vector2_push(L, result);
    return 1;
}

// Close Window
// --@function Close
// --@description Close the window.
// --@return void
int window_close(lua_State *L) {
    CloseWindow();
    return 0;
}

void bind_window_module(lua_State *L) {
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Window");

    lua_pushcfunction(L, window_open);
    lua_setfield(L, -2, "Open");

    lua_pushcfunction(L, window_is_ready);
    lua_setfield(L, -2, "IsReady");

    lua_pushcfunction(L, window_set_target_fps);
    lua_setfield(L, -2, "SetTargetFPS");

    lua_pushcfunction(L, window_set_title);
    lua_setfield(L, -2, "SetTitle");

    lua_pushcfunction(L, window_is_open);
    lua_setfield(L, -2, "IsOpen");

    lua_pushcfunction(L, window_draw_fps);
    lua_setfield(L, -2, "DrawFPS");

    lua_pushcfunction(L, window_clear_background);
    lua_setfield(L, -2, "ClearBackground");

    lua_pushcfunction(L, window_begin_drawing);
    lua_setfield(L, -2, "BeginDrawing");

    lua_pushcfunction(L, window_end_drawing);
    lua_setfield(L, -2, "EndDrawing");

    lua_pushcfunction(L, window_get_width);
    lua_setfield(L, -2, "GetWidth");

    lua_pushcfunction(L, window_get_height);
    lua_setfield(L, -2, "GetHeight");

    lua_pushcfunction(L, window_is_fullscreen);
    lua_setfield(L, -2, "IsFullscreen");

    lua_pushcfunction(L, window_is_focused);
    lua_setfield(L, -2, "IsFocused");

    lua_pushcfunction(L, window_minimize);
    lua_setfield(L, -2, "Minimize");

    lua_pushcfunction(L, window_maximize);
    lua_setfield(L, -2, "Maximize");

    lua_pushcfunction(L, window_get_position);
    lua_setfield(L, -2, "GetPosition");

    lua_pushcfunction(L, window_close);
    lua_setfield(L, -2, "Close");

    lua_pushcfunction(L, mouse_get_position);
    lua_setfield(L, -2, "GetMousePosition");

}