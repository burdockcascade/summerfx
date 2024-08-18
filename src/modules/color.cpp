#include "color.hpp"

// Color
// --@function Color
// --@description Creates a new Color object.
// --@param r int The red component of the color.
// --@param g int The green component of the color.
// --@param b int The blue component of the color.
// --@param a int The alpha component of the color.
// --@return Color
int l_Color_constructor(lua_State *L) {

	Color s;
	s.r = luaL_checkinteger(L, 1);
	s.g = luaL_checkinteger(L, 2);
	s.b = luaL_checkinteger(L, 3);
	s.a = luaL_checkinteger(L, 4);

	l_Color_push(L, s);

	return 1;
}

int l_Color_index(lua_State *L) {

	Color *udata = (Color*)luaL_checkudata(L, 1, "Color");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "r") == 0) {
		lua_pushinteger(L, udata->r);
	} else if (strcmp(key, "g") == 0) {
		lua_pushinteger(L, udata->g);
	} else if (strcmp(key, "b") == 0) {
		lua_pushinteger(L, udata->b);
	} else if (strcmp(key, "a") == 0) {
		lua_pushinteger(L, udata->a);
	} else {
        luaL_error(L, "Unknown field '%s' on ", key);
    }

	return 1;
}

int l_Color_newindex(lua_State *L) {

	Color *udata = (Color*)luaL_checkudata(L, 1, "Color");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "r") == 0) {
		udata->r = luaL_checkinteger(L, 1);
	} else if (strcmp(key, "g") == 0) {
		udata->g = luaL_checkinteger(L, 2);
	} else if (strcmp(key, "b") == 0) {
		udata->b = luaL_checkinteger(L, 3);
	} else if (strcmp(key, "a") == 0) {
		udata->a = luaL_checkinteger(L, 4);
	} else {
        luaL_error(L, "Unknown field '%s' on ", key);
    }

	return 0;
}

void l_Color_push(lua_State *L, const Color &color) {

	// Create new user data
	Color *ud = (Color*)lua_newuserdata(L, sizeof(Color));
	*ud = color;

	// Set metatable
	luaL_newmetatable(L, "Color");

	// Set index function
	lua_pushcfunction(L, l_Color_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Color_newindex);
	lua_setfield(L, -2, "__newindex");

	lua_setmetatable(L, -2);

}

void bind_color_module(lua_State *L) {

    lua_register(L, "Color", l_Color_constructor);

}