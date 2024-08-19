#include "modules.hpp"

// =====================================================================
// Color

// Color
// -- @name Color
// -- @description Creates a new Color object.
// -- @param r int The red component of the color.
// -- @param g int The green component of the color.
// -- @param b int The blue component of the color.
// -- @param a int The alpha component of the color.
// -- @return Color
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

// Color table
// -- @table Color
// -- @field r number The red component of the color
// -- @field g number The green component of the color
// -- @field b number The blue component of the color
// -- @field a number The alpha component of the color
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

// =====================================================================
// Vector2

// Vetor2
// --@table Vector2
// --@desc A 2D vector
// --@field x number
// --@field y number
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

// =====================================================================
// Rectangle

// Rectangle
// --@table Rectangle
// --@field x number The x position of the rectangle
// --@field y number The y position of the rectangle
// --@field width number The width of the rectangle
// --@field height number The height of the rectangle
// --@return Rectangle
int l_Rectangle_constructor(lua_State *L) {

    // Create struct
    Rectangle s;
    s.x = luaL_checknumber(L, 1);
    s.y = luaL_checknumber(L, 2);
    s.width = luaL_checknumber(L, 3);
    s.height = luaL_checknumber(L, 4);

    // Push struct onto stack
    l_Rectangle_push(L, s);

    return 1;
}

int l_Rectangle_index(lua_State *L) {

    Rectangle *udata = (Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    const char *key = luaL_checkstring(L, 2);

    // Rectangle x component
    if (strcmp(key, "x") == 0) {
        lua_pushnumber(L, udata->x);
    } else if (strcmp(key, "y") == 0) {
        lua_pushnumber(L, udata->y);
    } else if (strcmp(key, "width") == 0) {
        lua_pushnumber(L, udata->width);
    } else if (strcmp(key, "height") == 0) {
        lua_pushnumber(L, udata->height);
    } else {
        luaL_error(L, "Unknown field '%s' on ", key);
    }

    return 1;
}

int l_Rectangle_newindex(lua_State *L) {

    Rectangle *udata = (Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    const char *key = luaL_checkstring(L, 2);

    if (strcmp(key, "x") == 0) {
        udata->x = luaL_checknumber(L, 1);
    } else if (strcmp(key, "y") == 0) {
        udata->y = luaL_checknumber(L, 2);
    } else if (strcmp(key, "width") == 0) {
        udata->width = luaL_checknumber(L, 3);
    } else if (strcmp(key, "height") == 0) {
        udata->height = luaL_checknumber(L, 4);
    } else {
        luaL_error(L, "Unknown field '%s' on ", key);
    }

    return 0;
}

void l_Rectangle_push(lua_State *L, const Rectangle &rectangle) {

    // Create new user data
    Rectangle *ud = (Rectangle*)lua_newuserdata(L, sizeof(Rectangle));
    *ud = rectangle;

    // Set metatable
    luaL_newmetatable(L, "Rectangle");

    // Set index function
    lua_pushcfunction(L, l_Rectangle_index);
    lua_setfield(L, -2, "__index");

    // Set newindex function
    lua_pushcfunction(L, l_Rectangle_newindex);
    lua_setfield(L, -2, "__newindex");

    lua_setmetatable(L, -2);
}

// =====================================================================
// Bindings

void bind_structs(lua_State *L) {
    lua_register(L, "Rectangle", l_Rectangle_constructor);
    lua_register(L, "Vector2", l_Vector2_constructor);
    lua_register(L, "Color", l_Color_constructor);
}