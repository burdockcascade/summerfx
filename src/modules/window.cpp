#include "modules.hpp"

// =====================================================================
// Lifecycle

// Initialize Window
// -- @function Init
// -- @description Open a window with the specified title, width, and height.
// -- @usage Window.Init("My Game", 800, 600)
// -- @param title string The title of the window.   
// -- @param width int The width of the window.
// -- @param height int The height of the window.
// -- @return void 
int window_init(lua_State *L) {
    const char* title = luaL_checkstring(L, 1);
    int width = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    
    InitWindow(width, height, title);
    SetTargetFPS(60);

    return 0;
}

// Close Window
// -- @function Close
// -- @description Close the window.
// -- @usage Window.Close()
// -- @return void
int window_close(lua_State *L) {
    CloseWindow();
    return 0;
}

// IsWindowReady
// -- @function IsWindowReady
// -- @description Check if the window is ready.
// -- @usage if Window.IsReady() then Window.SetTargetFPS(60) end
// -- @return bool If the window is ready.
int window_is_ready(lua_State *L) {
    lua_pushboolean(L, IsWindowReady());
    return 1;
}

// Should Close
// -- @function ShouldClose
// -- @description Check if the window should close.
// -- @usage if Window.ShouldClose() then Window.Close() end
// -- @return bool If the window should close.
int window_should_close(lua_State *L) {
    lua_pushboolean(L, WindowShouldClose());
    return 1;
}

// Set Target FPS
// -- @function SetTargetFPS
// -- @description Set the target FPS of the window.
// -- @usage Window.SetTargetFPS(60)
// -- @param fps int The target FPS.
// -- @return void
int window_set_target_fps(lua_State *L) {
    int fps = luaL_checkinteger(L, 1);
    SetTargetFPS(fps);
    return 0;
}

// =====================================================================
// Setters

// Set Title
// -- @function SetTitle
// -- @description Set the title of the window.
// -- @usage Window.SetTitle("My Game")
// -- @param title string The title of the window.
// -- @return void
int window_set_title(lua_State *L) {
    const char* title = luaL_checkstring(L, 1);
    SetWindowTitle(title);
    return 0;
}

// Clear Background
// -- @function ClearBackground
// -- @description Clear the background with the specified color.
// -- @usage Window.ClearBackground(Color(255, 255, 255, 255))
// -- @param color Color The color to clear the background with.
// -- @return void
int window_clear_background(lua_State *L) {
    Color c = *(Color*)luaL_checkudata(L, 1, "Color");
    ClearBackground(c);
    return 0;
}

// =====================================================================
// Drawing

// Begin Drawing
// -- @function BeginDrawing
// -- @description Begin drawing to the window.
// -- @usage Window.BeginDrawing()
// -- @return void
int window_begin_drawing(lua_State *L) {
    BeginDrawing();
    return 0;
}

// End Drawing
// -- @function EndDrawing
// -- @description End drawing to the window.
// -- @usage Window.EndDrawing()
// -- @return void
int window_end_drawing(lua_State *L) {
    EndDrawing();
    return 0;
}

// =====================================================================
// Window

// GetWidth
// -- @function GetWidth
// -- @description Get the width of the window.
// -- @usage Window.GetWidth()
// -- @return int The width of the window.
int window_get_width(lua_State *L) {
    lua_pushinteger(L, GetScreenWidth());
    return 1;
}

// GetHeight
// -- @function GetHeight
// -- @description Get the height of the window.
// -- @usage Window.GetHeight()
// -- @return int The height of the window.
int window_get_height(lua_State *L) {
    lua_pushinteger(L, GetScreenHeight());
    return 1;
}

// IsWindowFullscreen
// -- @function IsFullscreen
// -- @description Check if the window is fullscreen.
// -- @usage Window.IsFullscreen()
// -- @return bool If the window is fullscreen.
int window_is_fullscreen(lua_State *L) {
    lua_pushboolean(L, IsWindowFullscreen());
    return 1;
}

// IsWindowFocused
// -- @function IsFocused
// -- @description Check if the window is focused.
// -- @usage Window.IsFocused()
// -- @return bool If the window is focused.
int window_is_focused(lua_State *L) {
    lua_pushboolean(L, IsWindowFocused());
    return 1;
}

// Is Hidden
// -- @function IsHidden
// -- @description Check if the window is hidden.
// -- @usage Window.IsHidden()
// -- @return bool If the window is hidden.
int window_is_hidden(lua_State *L) {
    lua_pushboolean(L, IsWindowHidden());
    return 1;
}

// Is Minimized
// -- @function IsMinimized
// -- @description Check if the window is minimized.
// -- @usage Window.IsMinimized()
// -- @return bool If the window is minimized.
int window_is_minimized(lua_State *L) {
    lua_pushboolean(L, IsWindowMinimized());
    return 1;
}

// Is Maximized
// -- @function IsMaximized
// -- @description Check if the window is maximized.
// -- @usage Window.IsMaximized()
// -- @return bool If the window is maximized.
int window_is_maximized(lua_State *L) {
    lua_pushboolean(L, IsWindowMaximized());
    return 1;
}

// Minimize Window
// -- @function Minimize
// -- @description Minimize the window.
// -- @usage Window.Minimize()
// -- @return void
int window_minimize(lua_State *L) {
    MinimizeWindow();
    return 0;
}

// Maximize Window
// -- @function Maximize
// -- @description Maximize the window.
// -- @usage Window.Maximize()
// -- @return void
int window_maximize(lua_State *L) {
    MaximizeWindow();
    return 0;
}

// Get Window Position
// -- @function GetPosition
// -- @description Get the position of the window.
// -- @usage Window.GetPosition()
// -- @return Vector2 The position of the window.
int window_get_position(lua_State *L) {
    Vector2 v;
    v.x = GetWindowPosition().x;
    v.y = GetWindowPosition().y;
    l_Vector2_push(L, v);
    return 1;
}

// Take Screenshot
// -- @function TakeScreenshot
// -- @description Take a screenshot of the window.
// -- @usage Window.TakeScreenshot("screenshot.png")
// -- @param filename string The filename to save the screenshot to.
// -- @return void
int window_take_screenshot(lua_State *L) {
    const char* filename = luaL_checkstring(L, 1);
    TakeScreenshot(filename);
    return 0;
}

// =====================================================================
// Time

// Get Elapsed Time
// -- @function GetElapsedTime
// -- @description Returns the elapsed time in seconds since the window was opened.
// -- @usage Window.GetElapsedTime()
// -- @return number The elapsed time in seconds.
int window_get_elapsed_time(lua_State *L) {
    lua_pushnumber(L, GetTime());
    return 1;
}

// Get Frame Time
// -- @function GetFrameTime
// -- @description Returns the time in seconds since the last frame.
// -- @usage Window.GetFrameTime()
// -- @return number The time in seconds since the last frame.
int window_get_frame_time(lua_State *L) {
    lua_pushnumber(L, GetFrameTime());
    return 1;
}

// Get FPS
// -- @function GetFPS
// -- @description Returns the current FPS.
// -- @usage Window.GetFPS()
// -- @return number The current FPS.
int window_get_fps(lua_State *L) {
    lua_pushnumber(L, GetFPS());
    return 1;
}

// =====================================================================
// Cursor

// Show Cursor
// -- @function ShowCursor
// -- @description Show the cursor.
// -- @usage Window.ShowCursor()
// -- @return void
int window_show_cursor(lua_State *L) {
    ShowCursor();
    return 0;
}

// Hide Cursor
// -- @function HideCursor
// -- @description Hide the cursor.
// -- @usage Window.HideCursor()
// -- @return void
int window_hide_cursor(lua_State *L) {
    HideCursor();
    return 0;
}

// Is Cursor Hidden
// -- @function IsCursorHidden
// -- @description Check if the cursor is hidden.
// -- @usage Window.IsCursorHidden()
// -- @return bool If the cursor is hidden.
int window_is_cursor_hidden(lua_State *L) {
    lua_pushboolean(L, IsCursorHidden());
    return 1;
}

// Enable Cursor
// -- @function EnableCursor
// -- @description Enable the cursor.
// -- @usage Window.EnableCursor()
// -- @return void
int window_enable_cursor(lua_State *L) {
    EnableCursor();
    return 0;
}

// Disable Cursor
// -- @function DisableCursor
// -- @description Disable the cursor.
// -- @usage Window.DisableCursor()
// -- @return void
int window_disable_cursor(lua_State *L) {
    DisableCursor();
    return 0;
}

// Is Cursor On Screen
// -- @function IsCursorOnScreen
// -- @description Check if the cursor is on the screen.
// -- @usage Window.IsCursorOnScreen()
// -- @return bool If the cursor is on the screen.
int window_is_cursor_on_screen(lua_State *L) {
    lua_pushboolean(L, IsCursorOnScreen());
    return 1;
}

// =====================================================================
// Bindings

void bind_window_module(lua_State *L) {
    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Window");

    lua_pushcfunction(L, window_init);
    lua_setfield(L, -2, "Init");

    lua_pushcfunction(L, window_is_ready);
    lua_setfield(L, -2, "IsReady");

    lua_pushcfunction(L, window_set_target_fps);
    lua_setfield(L, -2, "SetTargetFPS");

    lua_pushcfunction(L, window_set_title);
    lua_setfield(L, -2, "SetTitle");

    lua_pushcfunction(L, window_should_close);
    lua_setfield(L, -2, "ShouldClose");

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

    lua_pushcfunction(L, window_is_hidden);
    lua_setfield(L, -2, "IsHidden");

    lua_pushcfunction(L, window_is_minimized);
    lua_setfield(L, -2, "IsMinimized");

    lua_pushcfunction(L, window_is_maximized);
    lua_setfield(L, -2, "IsMaximized");

    lua_pushcfunction(L, window_minimize);
    lua_setfield(L, -2, "Minimize");

    lua_pushcfunction(L, window_maximize);
    lua_setfield(L, -2, "Maximize");

    lua_pushcfunction(L, window_get_position);
    lua_setfield(L, -2, "GetPosition");

    lua_pushcfunction(L, window_get_elapsed_time);
    lua_setfield(L, -2, "GetElapsedTime");

    lua_pushcfunction(L, window_get_frame_time);
    lua_setfield(L, -2, "GetFrameTime");

    lua_pushcfunction(L, window_get_fps);
    lua_setfield(L, -2, "GetFPS");

    lua_pushcfunction(L, window_take_screenshot);
    lua_setfield(L, -2, "TakeScreenshot");

    lua_pushcfunction(L, window_show_cursor);
    lua_setfield(L, -2, "ShowCursor");

    lua_pushcfunction(L, window_hide_cursor);
    lua_setfield(L, -2, "HideCursor");

    lua_pushcfunction(L, window_is_cursor_hidden);
    lua_setfield(L, -2, "IsCursorHidden");

    lua_pushcfunction(L, window_enable_cursor);
    lua_setfield(L, -2, "EnableCursor");

    lua_pushcfunction(L, window_disable_cursor);
    lua_setfield(L, -2, "DisableCursor");

    lua_pushcfunction(L, window_is_cursor_on_screen);
    lua_setfield(L, -2, "IsCursorOnScreen");

    lua_pushcfunction(L, window_close);
    lua_setfield(L, -2, "Close");

    lua_pop(L, 1);
}