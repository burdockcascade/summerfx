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
	} else if (strcmp(key, "y") == 0) {
		udata->y = luaL_checknumber(L, 2);
	} else {
		luaL_error(L, "Unknown field '%s' on Vector2", key);
	}

	return 0;
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
// Vector3

// Vector3
// --@table Vector3
// --@desc A 3D vector
// --@field x number
// --@field y number
// --@field z number
int l_Vector3_constructor(lua_State *L) {

	// Create struct
	Vector3 s;
	s.x = luaL_checknumber(L, 1);
	s.y = luaL_checknumber(L, 2);
	s.z = luaL_checknumber(L, 3);

	// Push struct onto stack
	l_Vector3_push(L, s);

	return 1;
}

int l_Vector3_index(lua_State *L) {

	Vector3 *udata = (Vector3*)luaL_checkudata(L, 1, "Vector3");
	const char *key = luaL_checkstring(L, 2);

	// Vector x component
	if (strcmp(key, "x") == 0) {
		lua_pushnumber(L, udata->x);
	} else if (strcmp(key, "y") == 0) {
		lua_pushnumber(L, udata->y);
	} else if (strcmp(key, "z") == 0) {
		lua_pushnumber(L, udata->z);
	} else {
		luaL_error(L, "Unknown field '%s' on ", key);
	}

	return 1;
}

int l_Vector3_newindex(lua_State *L) {

	Vector3 *udata = (Vector3*)luaL_checkudata(L, 1, "Vector3");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "x") == 0) {
		udata->x = luaL_checknumber(L, 1);
	}else if (strcmp(key, "y") == 0) {
		udata->y = luaL_checknumber(L, 2);
	} else if (strcmp(key, "z") == 0) {
		udata->z = luaL_checknumber(L, 3);
	} else {
		luaL_error(L, "Unknown field '%s' on Vector3", key);
	}

	return 0;
}

void l_Vector3_push(lua_State *L, const Vector3 &vector3) {

	// Create new user data
	Vector3 *ud = (Vector3*)lua_newuserdata(L, sizeof(Vector3));
	*ud = vector3;

	// Set metatable
	luaL_newmetatable(L, "Vector3");

	// Set index function
	lua_pushcfunction(L, l_Vector3_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Vector3_newindex);
	lua_setfield(L, -2, "__newindex");

	lua_setmetatable(L, -2);

}

// =====================================================================
// Vector4

// Vector4
// --@table Vector4
// --@desc A 4D vector
// --@field x number
// --@field y number
// --@field z number
// --@field w number
int l_Vector4_constructor(lua_State *L) {

	// Create struct
	Vector4 s;
	s.x = luaL_checknumber(L, 1);
	s.y = luaL_checknumber(L, 2);
	s.z = luaL_checknumber(L, 3);
	s.w = luaL_checknumber(L, 4);

	// Push struct onto stack
	l_Vector4_push(L, s);

	return 1;
}

// Vector4 field getter
int l_Vector4_index(lua_State *L) {

	Vector4 *udata = (Vector4*)luaL_checkudata(L, 1, "Vector4");
	const char *key = luaL_checkstring(L, 2);

	// Vector x component
	if (strcmp(key, "x") == 0) {
		lua_pushnumber(L, udata->x);
	} else if (strcmp(key, "y") == 0) {
		lua_pushnumber(L, udata->y);
	} else if (strcmp(key, "z") == 0) {
		lua_pushnumber(L, udata->z);
	} else if (strcmp(key, "w") == 0) {
		lua_pushnumber(L, udata->w);
	} else {
		luaL_error(L, "Unknown field '%s' on Vector4", key);
	}

	return 1;
}

// Vector4 field setter
int l_Vector4_newindex(lua_State *L) {

	Vector4 *udata = (Vector4*)luaL_checkudata(L, 1, "Vector4");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "x") == 0) {
		udata->x = luaL_checknumber(L, 1);
	} else if (strcmp(key, "y") == 0) {
		udata->y = luaL_checknumber(L, 2);
	} else if (strcmp(key, "z") == 0) {
		udata->z = luaL_checknumber(L, 3);
	} else if (strcmp(key, "w") == 0) {
		udata->w = luaL_checknumber(L, 4);
	} else {
		luaL_error(L, "Unknown field '%s' on Vector4", key);
	}

	return 0;
}

// Pushes a Vector4 onto the stack
void l_Vector4_push(lua_State *L, const Vector4 &vector4) {

	// Create new user data
	Vector4 *ud = (Vector4*)lua_newuserdata(L, sizeof(Vector4));
	*ud = vector4;

	// Set metatable
	luaL_newmetatable(L, "Vector4");

	// Set index function
	lua_pushcfunction(L, l_Vector4_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Vector4_newindex);
	lua_setfield(L, -2, "__newindex");

	lua_setmetatable(L, -2);

}

// =====================================================================
// Matrix

// Matrix
// --@table Matrix
// --@desc A 4x4 matrix
// --@field m0 number
// --@field m1 number
// --@field m2 number
// --@field m3 number
// --@field m4 number
// --@field m5 number
// --@field m6 number
// --@field m7 number
// --@field m8 number
// --@field m9 number
// --@field m10 number
// --@field m11 number
// --@field m12 number
// --@field m13 number
// --@field m14 number
// --@field m15 number
int l_Matrix_constructor(lua_State *L) {

	// Create struct
	Matrix s;
	s.m0 = luaL_checknumber(L, 1);
	s.m1 = luaL_checknumber(L, 2);
	s.m2 = luaL_checknumber(L, 3);
	s.m3 = luaL_checknumber(L, 4);
	s.m4 = luaL_checknumber(L, 5);
	s.m5 = luaL_checknumber(L, 6);
	s.m6 = luaL_checknumber(L, 7);
	s.m7 = luaL_checknumber(L, 8);
	s.m8 = luaL_checknumber(L, 9);
	s.m9 = luaL_checknumber(L, 10);
	s.m10 = luaL_checknumber(L, 11);
	s.m11 = luaL_checknumber(L, 12);
	s.m12 = luaL_checknumber(L, 13);
	s.m13 = luaL_checknumber(L, 14);
	s.m14 = luaL_checknumber(L, 15);
	s.m15 = luaL_checknumber(L, 16);

	// Push struct onto stack
	l_Matrix_push(L, s);

	return 1;
}

// Matrix field getter
int l_Matrix_index(lua_State *L) {

	Matrix *udata = (Matrix*)luaL_checkudata(L, 1, "Matrix");
	const char *key = luaL_checkstring(L, 2);

	// Matrix x component
	if (strcmp(key, "m0") == 0) {
		lua_pushnumber(L, udata->m0);
	} else if (strcmp(key, "m1") == 0) {
		lua_pushnumber(L, udata->m1);
	} else if (strcmp(key, "m2") == 0) {
		lua_pushnumber(L, udata->m2);
	} else if (strcmp(key, "m3") == 0) {
		lua_pushnumber(L, udata->m3);
	} else if (strcmp(key, "m4") == 0) {
		lua_pushnumber(L, udata->m4);
	} else if (strcmp(key, "m5") == 0) {
		lua_pushnumber(L, udata->m5);
	} else if (strcmp(key, "m6") == 0) {
		lua_pushnumber(L, udata->m6);
	} else if (strcmp(key, "m7") == 0) {
		lua_pushnumber(L, udata->m7);
	} else if (strcmp(key, "m8") == 0) {
		lua_pushnumber(L, udata->m8);
	} else if (strcmp(key, "m9") == 0) {
		lua_pushnumber(L, udata->m9);
	} else if (strcmp(key, "m10") == 0) {
		lua_pushnumber(L, udata->m10);
	} else if (strcmp(key, "m11") == 0) {
		lua_pushnumber(L, udata->m11);
	} else if (strcmp(key, "m12") == 0) {
		lua_pushnumber(L, udata->m12);
	} else if (strcmp(key, "m13") == 0) {
		lua_pushnumber(L, udata->m13);
	} else if (strcmp(key, "m14") == 0) {
		lua_pushnumber(L, udata->m14);
	} else if (strcmp(key, "m15") == 0) {
		lua_pushnumber(L, udata->m15);
	} else {
		luaL_error(L, "Unknown field '%s' on Matrix", key);
	}

	return 1;
}

// Matrix field setter
int l_Matrix_newindex(lua_State *L) {

	Matrix *udata = (Matrix*)luaL_checkudata(L, 1, "Matrix");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "m0") == 0) {
		udata->m0 = luaL_checknumber(L, 1);
	} else if (strcmp(key, "m1") == 0) {
		udata->m1 = luaL_checknumber(L, 2);
	} else if (strcmp(key, "m2") == 0) {
		udata->m2 = luaL_checknumber(L, 3);
	} else if (strcmp(key, "m3") == 0) {
		udata->m3 = luaL_checknumber(L, 4);
	} else if (strcmp(key, "m4") == 0) {
		udata->m4 = luaL_checknumber(L, 5);
	} else if (strcmp(key, "m5") == 0) {
		udata->m5 = luaL_checknumber(L, 6);
	} else if (strcmp(key, "m6") == 0) {
		udata->m6 = luaL_checknumber(L, 7);
	} else if (strcmp(key, "m7") == 0) {
		udata->m7 = luaL_checknumber(L, 8);
	} else if (strcmp(key, "m8") == 0) {
		udata->m8 = luaL_checknumber(L, 9);
	} else if (strcmp(key, "m9") == 0) {
		udata->m9 = luaL_checknumber(L, 10);
	} else if (strcmp(key, "m10") == 0) {
		udata->m10 = luaL_checknumber(L, 11);
	} else if (strcmp(key, "m11") == 0) {
		udata->m11 = luaL_checknumber(L, 12);
	} else if (strcmp(key, "m12") == 0) {
		udata->m12 = luaL_checknumber(L, 13);
	} else if (strcmp(key, "m13") == 0) {
		udata->m13 = luaL_checknumber(L, 14);
	} else if (strcmp(key, "m14") == 0) {
		udata->m14 = luaL_checknumber(L, 15);
	} else if (strcmp(key, "m15") == 0) {
		udata->m15 = luaL_checknumber(L, 16);
	} else {
		luaL_error(L, "Unknown field '%s' on Matrix", key);
	}

	return 0;
}

// Pushes a Matrix onto the stack
void l_Matrix_push(lua_State *L, const Matrix &matrix) {

	// Create new user data
	Matrix *ud = (Matrix*)lua_newuserdata(L, sizeof(Matrix));
	*ud = matrix;

	// Set metatable
	luaL_newmetatable(L, "Matrix");

	// Set index function
	lua_pushcfunction(L, l_Matrix_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Matrix_newindex);
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
// Camera2D

// Camera2D
// --@table Camera2D
// --@desc A 2D camera
// --@field target Vector2 The target of the camera
// --@field offset Vector2 The offset of the camera
// --@field rotation number The rotation of the camera
// --@field zoom number The zoom of the camera
// --@return Camera2D
int l_Camera2D_constructor(lua_State *L) {

	// Create struct
	Camera2D s;
	s.target = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
	s.offset = *(Vector2*)luaL_checkudata(L, 2, "Vector2");
	s.rotation = luaL_checknumber(L, 3);
	s.zoom = luaL_checknumber(L, 4);

	// Push struct onto stack
	l_Camera2D_push(L, s);

	return 1;
}

// Camera2D field getter
int l_Camera2D_index(lua_State *L) {

	Camera2D *udata = (Camera2D*)luaL_checkudata(L, 1, "Camera2D");
	const char *key = luaL_checkstring(L, 2);

	// Camera2D x component
	if (strcmp(key, "target") == 0) {
		l_Vector2_push(L, udata->target);
	} else if (strcmp(key, "offset") == 0) {
		l_Vector2_push(L, udata->offset);
	} else if (strcmp(key, "rotation") == 0) {
		lua_pushnumber(L, udata->rotation);
	} else if (strcmp(key, "zoom") == 0) {
		lua_pushnumber(L, udata->zoom);
	} else {
		luaL_error(L, "Unknown field '%s' on Camera2D", key);
	}

	return 1;
}

// Camera2D field setter
int l_Camera2D_newindex(lua_State *L) {

	Camera2D *udata = (Camera2D*)luaL_checkudata(L, 1, "Camera2D");
	const char *key = luaL_checkstring(L, 2);

	if (strcmp(key, "target") == 0) {
		udata->target = *(Vector2*)luaL_checkudata(L, 3, "Vector2");
	} else if (strcmp(key, "offset") == 0) {
		udata->offset = *(Vector2*)luaL_checkudata(L, 3, "Vector2");
	} else if (strcmp(key, "rotation") == 0) {
		udata->rotation = luaL_checknumber(L, 3);
	} else if (strcmp(key, "zoom") == 0) {
		udata->zoom = luaL_checknumber(L, 3);
	} else {
		luaL_error(L, "Unknown field '%s' on Camera2D", key);
	}

	return 0;
}

// Pushes a Camera2D onto the stack
void l_Camera2D_push(lua_State *L, const Camera2D &camera2d) {

	// Create new user data
	Camera2D *ud = (Camera2D*)lua_newuserdata(L, sizeof(Camera2D));
	*ud = camera2d;

	// Set metatable
	luaL_newmetatable(L, "Camera2D");

	// Set index function
	lua_pushcfunction(L, l_Camera2D_index);
	lua_setfield(L, -2, "__index");

	// Set newindex function
	lua_pushcfunction(L, l_Camera2D_newindex);
	lua_setfield(L, -2, "__newindex");

	lua_setmetatable(L, -2);

}

// =====================================================================
// Bindings

void bind_structs(lua_State *L) {
    lua_register(L, "Rectangle", l_Rectangle_constructor);
    lua_register(L, "Vector2", l_Vector2_constructor);
	lua_register(L, "Vector3", l_Vector3_constructor);
	lua_register(L, "Vector4", l_Vector4_constructor);
	lua_register(L, "Matrix", l_Matrix_constructor);
    lua_register(L, "Color", l_Color_constructor);
	lua_register(L, "Camera2D", l_Camera2D_constructor);
}