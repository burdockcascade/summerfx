#include "modules.hpp"

// =====================================================================
// Text

// Draw Text (basic)
// -- @function DrawText
// -- @description Draw text at the specified position
// -- @param text string The text to draw
// -- @param x int The x position to draw the text
// -- @param y int The y position to draw the text
// -- @param fontSize int The size of the font
// -- @param color Color The color of the text
// -- @return void
int graphics2d_draw_text(lua_State *L) {
    const char *text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);
    int fontSize = luaL_checkinteger(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawText(text, x, y, fontSize, c);
    return 0;
}

// Draw Text (Extended)
// -- @function DrawTextEx
// -- @description Draw text at the specified position
// -- @param font Font The font to use
// -- @param text string The text to draw
// -- @param position Vector2 The position to draw the text
// -- @param fontSize float The size of the font
// -- @param spacing float The spacing of the font
// -- @param tint Color The color of the text
// -- @return void
int graphics2d_draw_text_ex(lua_State *L) {
    Font font = *(Font*)luaL_checkudata(L, 1, "Font");
    const char *text = luaL_checkstring(L, 2);
    Vector2 position = *(Vector2*)luaL_checkudata(L, 3, "Vector2");
    float fontSize = luaL_checknumber(L, 4);
    float spacing = luaL_checknumber(L, 5);
    Color c = *(Color*)luaL_checkudata(L, 6, "Color");
    DrawTextEx(font, text, position, fontSize, spacing, c);
    return 0;
}

// Draw Text (Pro)
// -- @function DrawTextPro
// -- @description Draw text at the specified position
// -- @param font Font The font to use
// -- @param text string The text to draw
// -- @param position Vector2 The position to draw the text
// -- @param origin Vector2 The origin of the text
// -- @param rotation float The rotation of the text
// -- @param fontSize float The size of the font
// -- @param spacing float The spacing of the font
// -- @param tint Color The color of the text
// -- @return void
int graphics2d_draw_text_pro(lua_State *L) {
    Font font = *(Font*)luaL_checkudata(L, 1, "Font");
    const char *text = luaL_checkstring(L, 2);
    Vector2 position = *(Vector2*)luaL_checkudata(L, 3, "Vector2");
    Vector2 origin = *(Vector2*)luaL_checkudata(L, 4, "Vector2");
    float rotation = luaL_checknumber(L, 5);
    float fontSize = luaL_checknumber(L, 6);
    float spacing = luaL_checknumber(L, 7);
    Color c = *(Color*)luaL_checkudata(L, 8, "Color");
    DrawTextPro(font, text, position, origin, rotation, fontSize, spacing, c);
    return 0;
}

// Draw FPS
// -- @function DrawFPS
// -- @description Draw the FPS at the specified position.
// -- @param x int The x position to draw the FPS.
// -- @param y int The y position to draw the FPS.
// -- @return void
int graphics2d_draw_fps(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    DrawFPS(x, y);
    return 0;
}

// =====================================================================
// Pixels

// DrawPixel
// -- @function DrawPixel
// -- @description Draw a pixel
// -- @param position Vector2 The position of the pixel
// -- @param color Color The color of the pixel
// -- @return void
int graphics2d_draw_pixel(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    Color c = *(Color*)luaL_checkudata(L, 2, "Color");
    DrawPixelV(position, c);
    return 0;
}

// =====================================================================
// Rectangle

// DrawRectangle
// -- @function DrawRectangle
// -- @description Draw a rectangle
// -- @param x int The x position of the rectangle
// -- @param y int The y position of the rectangle
// -- @param width int The width of the rectangle
// -- @param height int The height of the rectangle
// -- @param color Color The color of the rectangle
// -- @return void
int graphics2d_draw_rectangle(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    int width = luaL_checkinteger(L, 3);
    int height = luaL_checkinteger(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawRectangle(x, y, width, height, c);
    return 0;
}

// DrawRectangleLinesV
// -- @function DrawRectangleLines
// -- @description Draw a rectangle outline
// -- @param rectangle rectangle The rectangle to draw
// -- @param int lineThickness The thickness of the lines
// -- @param Color color The color of the lines
// -- @return void
int graphics2d_draw_rectangle_lines(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    int lineThickness = luaL_checkinteger(L, 2);
    Color c = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleLines(r.x, r.y, r.width, r.height, c);
    return 0;
}

// DrawRectangleRounded
// -- @function DrawRectangleRounded
// -- @description Draw a rectangle with rounded edges
// -- @param rectangle rectangle The rectangle to draw
// -- @param roundness float The roundness of the edges
// -- @param segments int The number of segments to use
// -- @param color Color The color of the rectangle
// -- @return void
int graphics2d_draw_rectangle_rounded(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    float roundness = luaL_checknumber(L, 2);
    int segments = luaL_checkinteger(L, 3);
    Color c = *(Color*)luaL_checkudata(L, 4, "Color");
    DrawRectangleRounded(r, roundness, segments, c);
    return 0;
}

// DrawRectangleRoundedLines
// -- @function DrawRectangleRoundedLines
// -- @description Draw a rectangle with rounded edges
// -- @param rectangle Rectangle The rectangle to draw
// -- @param roundness float The roundness of the edges
// -- @param segments int The number of segments to use
// -- @param lineThickness int The thickness of the lines
// -- @param color Color The color of the lines
// -- @return void
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
// -- @function DrawRectangleGradientV
// -- @description Draw a rectangle with a vertical gradient
// -- @param rectangle Rectangle The rectangle to draw
// -- @param c1 Color The first color of the gradient
// -- @param c2 Color The second color of the gradient
// -- @return void
int graphics2d_draw_rectangle_gradient(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleGradientV(r.x, r.y, r.width, r.height, c1, c2);
    return 0;
}

// DrawRectangleGradientH
// -- @function DrawRectangleGradientH
// -- @description Draw a rectangle with a horizontal gradient
// -- @param rectangle Rectangle The rectangle to draw
// -- @param color1 Color The first color of the gradient
// -- @param color2 Color The second color of the gradient
// -- @return void
int graphics2d_draw_rectangle_gradient_h(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawRectangleGradientH(r.x, r.y, r.width, r.height, c1, c2);
    return 0;
}

// DrawRectangleGradientEx
// -- @function DrawRectangleGradientEx
// -- @description Draw a rectangle with a gradient
// -- @param rectangle rectangle The rectangle to draw
// -- @param c1 Color The first color of the gradient
// -- @param c2 Color The second color of the gradient
// -- @param c3 Color The third color of the gradient
// -- @param c4 Color The fourth color of the gradient
// -- @return void
int graphics2d_draw_rectangle_gradient_ex(lua_State *L) {
    Rectangle r = *(Rectangle*)luaL_checkudata(L, 1, "Rectangle");
    Color c1 = *(Color*)luaL_checkudata(L, 2, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 3, "Color");
    Color c3 = *(Color*)luaL_checkudata(L, 4, "Color");
    Color c4 = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawRectangleGradientEx(r, c1, c2, c3, c4);
    return 0;
}

// =====================================================================
// Polygons

// DrawPoly
// -- @function DrawPoly
// -- @description Draw a polygon
// -- @param Vector2 position The position of the polygon
// -- @param sides int The number of sides of the polygon
// -- @param radius float The radius of the polygon
// -- @param rotation float The rotation of the polygon
// -- @param color Color The color of the polygon
// -- @return void
int graphics2d_draw_poly(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    int sides = luaL_checkinteger(L, 2);
    float radius = luaL_checknumber(L, 3);
    float rotation = luaL_checknumber(L, 4);
    Color c = *(Color*)luaL_checkudata(L, 5, "Color");
    DrawPoly(position, sides, radius, rotation, c);
    return 0;
}

// =====================================================================
// Lines

// Draw Line
// -- @function DrawLine
// -- @description Draw a line
// -- @param start Vector2 The start position of the line
// -- @param end Vector2 The end position of the line
// -- @param color Color The color of the line
// -- @return void
int graphics2d_draw_line(lua_State *L) {
    Vector2 start = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    Vector2 end = *(Vector2*)luaL_checkudata(L, 2, "Vector2");
    Color c = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawLine(start.x, start.y, end.x, end.y, c);
    return 0;
}

// =====================================================================
// Circles

// Draw Circle (Vector2)
// -- @function DrawCircle
// -- @description Draw a circle
// -- @param position Vector2 The position of the circle
// -- @param radius float The radius of the circle
// -- @param color Color The color of the circle
// -- @return void
int graphics2d_draw_circlev(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    float radius = luaL_checknumber(L, 2);
    Color c = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawCircleV(position, radius, c);
    return 0;
}

// Draw Circle Lines
// -- @function DrawCircleLines
// -- @description Draw a circle outline
// -- @param position Vector2 The position of the circle
// -- @param radius float The radius of the circle
// -- @param color Color The color of the circle
// -- @return void
int graphics2d_draw_circle_lines(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    float radius = luaL_checknumber(L, 2);
    Color c = *(Color*)luaL_checkudata(L, 3, "Color");
    DrawCircleLines(position.x, position.y, radius, c);
    return 0;
}

// Draw Cirlce Sector
// -- @function DrawCircleSector
// -- @description Draw a circle sector
// -- @param position Vector2 The position of the circle
// -- @param radius float The radius of the circle
// -- @param startAngle int The start angle of the sector
// -- @param endAngle int The end angle of the sector
// -- @param segments int The number of segments to use
// -- @param color Color The color of the circle
// -- @return void
int graphics2d_draw_circle_sector(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    float radius = luaL_checknumber(L, 2);
    int startAngle = luaL_checkinteger(L, 3);
    int endAngle = luaL_checkinteger(L, 4);
    int segments = luaL_checkinteger(L, 5);
    Color c = *(Color*)luaL_checkudata(L, 6, "Color");
    DrawCircleSector(position, radius, startAngle, endAngle, segments, c);
    return 0;
}

// Draw Circle Sector Lines
// -- @function DrawCircleSectorLines
// -- @description Draw a circle sector outline
// -- @param position Vector2 The position of the circle
// -- @param radius float The radius of the circle
// -- @param startAngle int The start angle of the sector
// -- @param endAngle int The end angle of the sector
// -- @param segments int The number of segments to use
// -- @param color Color The color of the circle
// -- @return void
int graphics2d_draw_circle_sector_lines(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    float radius = luaL_checknumber(L, 2);
    int startAngle = luaL_checkinteger(L, 3);
    int endAngle = luaL_checkinteger(L, 4);
    int segments = luaL_checkinteger(L, 5);
    Color c = *(Color*)luaL_checkudata(L, 6, "Color");
    DrawCircleSectorLines(position, radius, startAngle, endAngle, segments, c);
    return 0;
}

// Draw Circle Gradient
// -- @function DrawCircleGradient
// -- @description Draw a circle with a gradient
// -- @param positionVector2 The position of the circle
// -- @param radius float The radius of the circle
// -- @param c1 Color The first color of the gradient
// -- @param c2 Color The second color of the gradient
// -- @return void
int graphics2d_draw_circle_gradient(lua_State *L) {
    Vector2 position = *(Vector2*)luaL_checkudata(L, 1, "Vector2");
    float radius = luaL_checknumber(L, 2);
    Color c1 = *(Color*)luaL_checkudata(L, 3, "Color");
    Color c2 = *(Color*)luaL_checkudata(L, 4, "Color");
    DrawCircleGradient(position.x, position.y, radius, c1, c2);
    return 0;
}

// =====================================================================
// Bindings

void bind_graphics2d_module(lua_State *L) {

    lua_newtable(L);
    lua_pushvalue(L, -1);
    lua_setglobal(L, "Graphics2D");

    lua_pushcfunction(L, graphics2d_draw_text);
    lua_setfield(L, -2, "DrawText");

    lua_pushcfunction(L, graphics2d_draw_fps);
    lua_setfield(L, -2, "DrawFPS");

    lua_pushcfunction(L, graphics2d_draw_pixel);
    lua_setfield(L, -2, "DrawPixel");

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

    lua_pushcfunction(L, graphics2d_draw_line);
    lua_setfield(L, -2, "DrawLine");

    lua_pushcfunction(L, graphics2d_draw_circlev);
    lua_setfield(L, -2, "DrawCircleV");

    lua_pushcfunction(L, graphics2d_draw_circle_lines);
    lua_setfield(L, -2, "DrawCircleLines");

    lua_pushcfunction(L, graphics2d_draw_circle_sector);
    lua_setfield(L, -2, "DrawCircleSector");

    lua_pushcfunction(L, graphics2d_draw_circle_sector_lines);
    lua_setfield(L, -2, "DrawCircleSectorLines");

    lua_pushcfunction(L, graphics2d_draw_circle_gradient);
    lua_setfield(L, -2, "DrawCircleGradient");

    lua_pop(L, 1);
}
