#include "graphics2d.hpp"

// Draw Text
// --@function DrawText
// --@description Draw text using font inside rectangle limits
// --@param string text The text to draw
// --@param vector2 position The position of the text
// --@param int fontSize The font size of the text
// --@param Color color The color of the text
// --@return void
int graphics2d_draw_text(lua_State *L) {
    const char* text = luaL_checkstring(L, 1);
    Vector2 position = *(Vector2*)luaL_checkudata(L, 2, "Vector2");
    int fontSize = luaL_checkinteger(L, 3);
    Color c = *(Color*)luaL_checkudata(L, 4, "Color");
    DrawText(text, position.x, position.y, fontSize, c);
    return 0;
}

// DrawRectangle
// --@function DrawRectangle
// --@description Draw a rectangle
// --@param rectangle rectangle The rectangle to draw
// --@param Color color The color of the rectangle
// --@return void
int graphics2d_draw_rectangle(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c = *(Color*)luaL_checkudata(L, 2, "Color");
    DrawRectangle(r.x, r.y, r.width, r.height, c);
    return 0;
}

// DrawRectangleLinesV
// --@function DrawRectangleLines
// --@description Draw a rectangle outline
// --@param rectangle rectangle The rectangle to draw
// --@param int lineThickness The thickness of the lines
// --@param Color color The color of the lines
// --@return void
int graphics2d_draw_rectangle_lines(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    int lineThickness = luaL_checkinteger(L, 2);
    Color c = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleLines(r.x, r.y, r.width, r.height, c);
    return 0;
}

// DrawRectangleRounded
// --@function DrawRectangleRounded
// --@description Draw a rectangle with rounded edges
// --@param rectangle rectangle The rectangle to draw
// --@param float roundness The roundness of the edges
// --@param int segments The number of segments to use
// --@param Color color The color of the rectangle
// --@return void
int graphics2d_draw_rectangle_rounded(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    float roundness = luaL_checknumber(L, 2);
    int segments = luaL_checkinteger(L, 3);
    Color c = *(Color*)luaL_checkudata(L, 4, "Color");
    DrawRectangleRounded(r, roundness, segments, c);
    return 0;
}

// DrawRectangleRoundedLines
// --@function DrawRectangleRoundedLines
// --@description Draw a rectangle with rounded edges
// --@param rectangle rectangle The rectangle to draw
// --@param float roundness The roundness of the edges
// --@param int segments The number of segments to use
// --@param int lineThickness The thickness of the lines
// --@param Color color The color of the lines
// --@return void
int graphics2d_draw_rectangle_rounded_lines(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    float roundness = luaL_checknumber(L, 2);
    int segments = luaL_checkinteger(L, 3);
    int lineThickness = luaL_checkinteger(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawRectangleRoundedLines(r, roundness, segments, lineThickness, c);
    return 0;
}

// DrawRectangleGradientV
// --@function DrawRectangleGradientV
// --@description Draw a rectangle with a vertical gradient
// --@param rectangle rectangle The rectangle to draw
// --@param Color color1 The first color of the gradient
// --@param Color color2 The second color of the gradient
// --@return void
int graphics2d_draw_rectangle_gradient(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleGradientV(r.x, r.y, r.width, r.height, c1, c2);
    return 0;
}

// DrawRectangleGradientH
// --@function DrawRectangleGradientH
// --@description Draw a rectangle with a horizontal gradient
// --@param rectangle rectangle The rectangle to draw
// --@param Color color1 The first color of the gradient
// --@param Color color2 The second color of the gradient
// --@return void
int graphics2d_draw_rectangle_gradient_h(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleGradientH(r.x, r.y, r.width, r.height, c1, c2);
    return 0;
}

// DrawRectangleGradientEx
// --@function DrawRectangleGradientEx
// --@description Draw a rectangle with a gradient
// --@param rectangle rectangle The rectangle to draw
// --@param Color color1 The first color of the gradient
// --@param Color color2 The second color of the gradient
// --@param Color color3 The third color of the gradient
// --@param Color color4 The fourth color of the gradient
// --@return void
int graphics2d_draw_rectangle_gradient_ex(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    Color c3 = *(Color*)luaL_checkudata(L, 4, "Color");
    Color c4 = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawRectangleGradientEx(r, c1, c2, c3, c4);
    return 0;
}

// DrawPoly
// --@function DrawPoly
// --@description Draw a polygon
// --@param vector2 position The position of the polygon
// --@param int sides The number of sides of the polygon
// --@param float radius The radius of the polygon
// --@param float rotation The rotation of the polygon
// --@param Color color The color of the polygon
// --@return void
int graphics2d_draw_poly(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    int sides = luaL_checkinteger(L, 2);
    float radius = luaL_checknumber(L, 3);
    float rotation = luaL_checknumber(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawPoly(position, sides, radius, rotation, c);
    return 0;
}

// Bind Graphics2D module
void bind_graphics2d_module(lua_State *L) {

    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Graphics2D");

    lua_pushcfunction(L, graphics2d_draw_text);
    lua_setfield(L, -2, "DrawText");

    lua_pushcfunction(L, graphics2d_draw_rectangle);
    lua_setfield(L, -2, "DrawRectangle");

    lua_pushcfunction(L, graphics2d_draw_rectangle_lines);
    lua_setfield(L, -2, "DrawRectangleLines");

    lua_pushcfunction(L, graphics2d_draw_rectangle_rounded);
    lua_setfield(L, -2, "DrawRectangleRounded");

    lua_pushcfunction(L, graphics2d_draw_rectangle_rounded_lines);
    lua_setfield(L, -2, "DrawRectangleRoundedLines");

    lua_pushcfunction(L, graphics2d_draw_rectangle_gradient);
    lua_setfield(L, -2, "DrawRectangleGradientV");

    lua_pushcfunction(L, graphics2d_draw_rectangle_gradient_h);
    lua_setfield(L, -2, "DrawRectangleGradientH");

    lua_pushcfunction(L, graphics2d_draw_rectangle_gradient_ex);
    lua_setfield(L, -2, "DrawRectangleGradientEx");

    lua_pushcfunction(L, graphics2d_draw_poly);
    lua_setfield(L, -2, "DrawPoly");

}