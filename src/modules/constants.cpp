#include "modules.hpp"

// Add predefined colors to Color table
void bind_constants(lua_State *L) {

    // -- @constant RAYLIB_VERSION
    // -- @description The version of Raylib
    lua_pushstring(L, RAYLIB_VERSION);
    lua_setglobal(L, "RAYLIB_VERSION");

    // --- @constant LUA_VERSION
    // --- @description The version of Lua
    lua_pushstring(L, LUA_VERSION);
    lua_setglobal(L, "LUA_VERSION");

	// -- @constant COLOR_LIGHTGRAY Color(200, 200, 200, 255)
	// -- @desecription A light gray color
	l_Color_push(L, LIGHTGRAY);
	lua_setglobal(L, "COLOR_LIGHTGRAY");

	// -- @constant COLOR_GRAY Color(130, 130, 130, 255)
	// -- @description A gray color
	l_Color_push(L, GRAY);
	lua_setglobal(L, "COLOR_GRAY");

	// -- @constant COLOR_DARKGRAY Color(80, 80, 80, 255)
	// -- @description A dark gray color
	l_Color_push(L, DARKGRAY);
	lua_setglobal(L, "COLOR_DARKGRAY");

	// -- @constant COLOR_YELLOW Color(253, 249, 0, 255)
	// -- @description A yellow color
	l_Color_push(L, YELLOW);
	lua_setglobal(L, "COLOR_YELLOW");

	// -- @constant COLOR_GOLD Color(255, 203, 0, 255)
	// -- @description A gold color
	l_Color_push(L, GOLD);
	lua_setglobal(L, "COLOR_GOLD");

	// -- @constant COLOR_ORANGE Color(255, 161, 0, 255)
	// -- @description An orange color
	l_Color_push(L, ORANGE);
	lua_setglobal(L, "COLOR_ORANGE");

	// -- @constant COLOR_PINK Color(255, 109, 194, 255)
	// -- @description A pink color
	l_Color_push(L, PINK);
	lua_setglobal(L, "COLOR_PINK");

	// -- @constant COLOR_RED Color(230, 41, 55, 255)
	// -- @description A red color
	l_Color_push(L, RED);
	lua_setglobal(L, "COLOR_RED");

	// -- @constant COLOR_MAROON Color(190, 33, 55, 255)
	// -- @description A maroon color
	l_Color_push(L, MAROON);
	lua_setglobal(L, "COLOR_MAROON");

	// -- @constant COLOR_GREEN Color(0, 228, 48, 255)
	// -- @description A green color
	l_Color_push(L, GREEN);
	lua_setglobal(L, "COLOR_GREEN");

	// -- @constant COLOR_LIME Color(0, 158, 47, 255)
	// -- @description A lime color
	l_Color_push(L, LIME);
	lua_setglobal(L, "COLOR_LIME");

	// -- @constant COLOR_DARKGREEN Color(0, 117, 44, 255)
	// -- @description A dark green color
	l_Color_push(L, DARKGREEN);
	lua_setglobal(L, "COLOR_DARKGREEN");

	// -- @constant COLOR_SKYBLUE Color(102, 191, 255, 255)
	// -- @description A sky blue color
	l_Color_push(L, SKYBLUE);
	lua_setglobal(L, "COLOR_SKYBLUE");

	// -- @constant COLOR_BLUE Color(0, 121, 241, 255)
	// -- @description A blue color
	l_Color_push(L, BLUE);
	lua_setglobal(L, "COLOR_BLUE");

	// -- @constant COLOR_DARKBLUE Color(0, 82, 172, 255)
	// -- @description A dark blue color
	l_Color_push(L, DARKBLUE);
	lua_setglobal(L, "COLOR_DARKBLUE");

	// -- @constant COLOR_PURPLE Color(200, 122, 255, 255)
	// -- @description A purple color
	l_Color_push(L, PURPLE);
	lua_setglobal(L, "COLOR_PURPLE");

	// -- @constant COLOR_VIOLET Color(135, 60, 190, 255)
	// -- @description A violet color
	l_Color_push(L, VIOLET);
	lua_setglobal(L, "COLOR_VIOLET");

	// -- @constant COLOR_DARKPURPLE Color(112, 31, 126, 255)
	// -- @description A dark purple color
	l_Color_push(L, DARKPURPLE);
	lua_setglobal(L, "COLOR_DARKPURPLE");

	// -- @constant COLOR_BEIGE Color(211, 176, 131, 255)
	// -- @description A beige color
	l_Color_push(L, BEIGE);
	lua_setglobal(L, "COLOR_BEIGE");

	// -- @constant COLOR_BROWN Color(127, 106, 79, 255)
	// -- @description A brown color
	l_Color_push(L, BROWN);
	lua_setglobal(L, "COLOR_BROWN");	

	// -- @constant COLOR_DARKBROWN Color(76, 63, 47, 255)
	// -- @description A dark brown color
	l_Color_push(L, DARKBROWN);
	lua_setglobal(L, "COLOR_DARKBROWN");

	// -- @constant COLOR_WHITE Color(255, 255, 255, 255)
	// -- @description A white color
	l_Color_push(L, WHITE);
	lua_setglobal(L, "COLOR_WHITE");

	// -- @constant COLOR_BLACK Color(0, 0, 0, 255)
	// -- @description A black color
	l_Color_push(L, BLACK);
	lua_setglobal(L, "COLOR_BLACK");

	// -- @constant COLOR_BLANK Color(0, 0, 0, 0)
	// -- @description A blank color
	l_Color_push(L, BLANK);
	lua_setglobal(L, "COLOR_BLANK");

	// -- @constant COLOR_MAGENTA Color(255, 0, 255, 255)
	// -- @description A magenta color
	l_Color_push(L, MAGENTA);
	lua_setglobal(L, "COLOR_MAGENTA");

	// -- @constant COLOR_RAYWHITE Color(245, 245, 245, 255)
	// -- @description A ray white color
	l_Color_push(L, RAYWHITE);
	lua_setglobal(L, "COLOR_RAYWHITE");

}