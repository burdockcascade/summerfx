#include "math.hpp"

int l_Vector2_constructor(lua_State *L) {

	// Create struct
	Vector2 s;
	s.x = luaL_checknumber(L, 1);
	s.y = luaL_checknumber(L, 2);

	// Push struct onto stack
	l_Vector2_push(L, s);

	return 1;
}

int l_Vector2_index(lua_State *L) {

	Vector2 *udata = (Vector2*)luaL_checkudata(L, 1, "Vector2");
	const char *key = luaL_checkstring(L, 2);

	// Vector x component
	if (strcmp(key, "x") == 0) {
		lua_pushnumber(L, udata->x);
	} else if (strcmp(key, "y") == 0) {
		lua_pushnumber(L, udata->y);
	} else {
        luaL_error(L, "Unknown field '%s' on ", key);
    }

	return 1;
}

int l_Vector2_newindex(lua_State *L) {

	Vector2 *udata = (Vector2*)luaL_checkudata(L, 1, "Vector2");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "x") == 0) {
		udata->x = luaL_checknumber(L, 1);
		return 0;
	}
	if (strcmp(key, "y") == 0) {
		udata->y = luaL_checknumber(L, 2);
		return 0;
	}

	return 1;
}

void l_Vector2_push(lua_State *L, const Vector2 &vector2) {

	// Create new user data
	Vector2 *ud = (Vector2*)lua_newuserdata(L, sizeof(Vector2));
	*ud = vector2;

	// Set metatable
	luaL_newmetatable(L, "Vector2");

	// Set index function
	lua_pushcfunction(L, l_Vector2_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Vector2_newindex);
	lua_setfield(L, -2, "__newindex");

	lua_setmetatable(L, -2);

}

void bind_math_module(lua_State *L) {

    lua_register(L, "Vector2", l_Vector2_constructor);

}