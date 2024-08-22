#include "modules.h"

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
    const int x = luaL_checkinteger(L, 2);
    const int y = luaL_checkinteger(L, 3);
    const int fontSize = luaL_checkinteger(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawText(text, x, y, fontSize, *c);
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
    const Font *font = luaL_checkudata(L, 1, "Font");
    const char *text = luaL_checkstring(L, 2);
    const Vector2 *position = luaL_checkudata(L, 3, "Vector2");
    const float fontSize = luaL_checknumber(L, 4);
    const float spacing = luaL_checknumber(L, 5);
    const Color *c = luaL_checkudata(L, 6, "Color");
    DrawTextEx(*font, text, *position, fontSize, spacing, *c);
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
    const Font *font = luaL_checkudata(L, 1, "Font");
    const char *text = luaL_checkstring(L, 2);
    const Vector2 *position = luaL_checkudata(L, 3, "Vector2");
    const Vector2 *origin = luaL_checkudata(L, 4, "Vector2");
    const float rotation = luaL_checknumber(L, 5);
    const float fontSize = luaL_checknumber(L, 6);
    const float spacing = luaL_checknumber(L, 7);
    const Color *c = luaL_checkudata(L, 8, "Color");
    DrawTextPro(*font, text, *position, *origin, rotation, fontSize, spacing, *c);
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
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const Color *c = luaL_checkudata(L, 3, "Color");
    DrawPixel(x, y, *c);
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
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const int width = luaL_checkinteger(L, 3);
    const int height = luaL_checkinteger(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawRectangle(x, y, width, height, *c);
    return 0;
}

// DrawRectangleLines
// -- @function DrawRectangleLines
// -- @description Draw a rectangle outline
// -- @param x int The x position of the rectangle
// -- @param y int The y position of the rectangle
// -- @param width int The width of the rectangle
// -- @param height int The height of the rectangle
// -- @param color Color The color of the rectangle
// -- @return void
int graphics2d_draw_rectangle_lines(lua_State *L) {
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const int width = luaL_checkinteger(L, 3);
    const int height = luaL_checkinteger(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawRectangleLines(x, y, width, height, *c);
    return 0;
}

// DrawRectangleRec
// -- @function DrawRectangleRec
// -- @description Draw a rectangle
// -- @param rectangle Rectangle The rectangle to draw
// -- @param color Color The color of the rectangle
// -- @return void
int graphics2d_draw_rectangle_rec(lua_State *L) {
    const Rectangle *r = luaL_checkudata(L, 1, "Rectangle");
    const Color *c = luaL_checkudata(L, 2, "Color");
    DrawRectangleRec(*r, *c);
    return 0;
}

// DrawRectangleLinesEx
// -- @function DrawRectangleLinesEx
// -- @description Draw a rectangle outline with extended parameters
// -- @param rectangle Rectangle The rectangle to draw
// -- @param lineThicknes int The thickness of the lines
// -- @param color Color The color of the lines
// -- @return void
int graphics2d_draw_rectangle_lines_ex(lua_State *L) {
    const Rectangle *r = luaL_checkudata(L, 1, "Rectangle");
    const int lineThickness = luaL_checkinteger(L, 2);
    const Color *c = luaL_checkudata(L, 3, "Color");
    DrawRectangleLinesEx(*r, lineThickness, *c);
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
    const Rectangle *r = luaL_checkudata(L, 1, "Rectangle");
    const float roundness = luaL_checknumber(L, 2);
    const int segments = luaL_checkinteger(L, 3);
    const Color *c = luaL_checkudata(L, 4, "Color");
    DrawRectangleRounded(*r, roundness, segments, *c);
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
    const  Rectangle *r = luaL_checkudata(L, 1, "Rectangle");
    const float roundness = luaL_checknumber(L, 2);
    const int segments = luaL_checkinteger(L, 3);
    const int lineThickness = luaL_checkinteger(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawRectangleRoundedLines(*r, roundness, segments, lineThickness, *c);
    return 0;
}

// DrawRectangleGradientV
// -- @function DrawRectangleGradientV
// -- @description Draw a rectangle with a vertical gradient
// -- @param x int The x position of the rectangle
// -- @param y int The y position of the rectangle
// -- @param width int The width of the rectangle
// -- @param height int The height of the rectangle
// -- @param color1 Color The first color of the gradient
// -- @param color2 Color The second color of the gradient
// -- @return void
int graphics2d_draw_rectangle_gradient_v(lua_State *L) {
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const int width = luaL_checkinteger(L, 3);
    const int height = luaL_checkinteger(L, 4);
    const Color *c1 = luaL_checkudata(L, 5, "Color");
    const Color *c2 = luaL_checkudata(L, 6, "Color");
    DrawRectangleGradientV(x, y, width, height, *c1, *c2);
    return 0;
}

// DrawRectangleGradientH
// -- @function DrawRectangleGradientH
// -- @description Draw a rectangle with a horizontal gradient
// -- @param x int The x position of the rectangle
// -- @param y int The y position of the rectangle
// -- @param width int The width of the rectangle
// -- @param height int The height of the rectangle
// -- @param color1 Color The first color of the gradient
// -- @param color2 Color The second color of the gradient
// -- @return void
int graphics2d_draw_rectangle_gradient_h(lua_State *L) {
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const int width = luaL_checkinteger(L, 3);
    const int height = luaL_checkinteger(L, 4);
    const Color *c1 = luaL_checkudata(L, 5, "Color");
    const Color *c2 = luaL_checkudata(L, 6, "Color");
    DrawRectangleGradientH(x, y, width, height, *c1, *c2);
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
    const Rectangle *r = luaL_checkudata(L, 1, "Rectangle");
    const Color *c1 = luaL_checkudata(L, 2, "Color");
    const Color *c2 = luaL_checkudata(L, 3, "Color");
    const Color *c3 = luaL_checkudata(L, 4, "Color");
    const Color *c4 = luaL_checkudata(L, 5, "Color");
    DrawRectangleGradientEx(*r, *c1, *c2, *c3, *c4);
    return 0;
}

// =====================================================================
// Polygons

// DrawPoly
// -- @function DrawPoly
// -- @description Draw a polygon
// -- @param Vector2 *position The position of the polygon
// -- @param sides int The number of sides of the polygon
// -- @param radius float The radius of the polygon
// -- @param rotation float The rotation of the polygon
// -- @param color Color The color of the polygon
// -- @return void
int graphics2d_draw_poly(lua_State *L) {
    const Vector2 *position = luaL_checkudata(L, 1, "Vector2");
    const int sides = luaL_checkinteger(L, 2);
    const float radius = luaL_checknumber(L, 3);
    const float rotation = luaL_checknumber(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawPoly(*position, sides, radius, rotation, *c);
    return 0;
}

// =====================================================================
// Lines

// Draw Line
// -- @function DrawLine
// -- @description Draw a line
// -- @param startX int The x position of the start of the line
// -- @param startY int The y position of the start of the line
// -- @param endX int The x position of the end of the line
// -- @param endY int The y position of the end of the line
// -- @param color Color The color of the line
// -- @return void
int graphics2d_draw_line(lua_State *L) {
    const int startX = luaL_checkinteger(L, 1);
    const int startY = luaL_checkinteger(L, 2);
    const int endX = luaL_checkinteger(L, 3);
    const int endY = luaL_checkinteger(L, 4);
    const Color *c = luaL_checkudata(L, 5, "Color");
    DrawLine(startX, startY, endX, endY, *c);
    return 0;
}

// Draw Line (Vector2)
// -- @function DrawLineV
// -- @description Draw a line
// -- @param start Vector2 The start position of the line
// -- @param end Vector2 The end position of the line
// -- @param color Color The color of the line
// -- @return void
int graphics2d_draw_linev(lua_State *L) {
    const Vector2 *start = luaL_checkudata(L, 1, "Vector2");
    const Vector2 *end = luaL_checkudata(L, 2, "Vector2");
    const Color *c = luaL_checkudata(L, 3, "Color");
    DrawLineV(*start, *end, *c);
    return 0;
}

// Draw Line (extended)
// -- @function DrawLineEx
// -- @description Draw a line with extended parameters
// -- @param start Vector2 The start position of the line
// -- @param end Vector2 The end position of the line
// -- @param thicknes float The thickness of the line
// -- @param color Color The color of the line
// -- @return void
int graphics2d_draw_line_ex(lua_State *L) {
    const Vector2 *start = luaL_checkudata(L, 1, "Vector2");
    const Vector2 *end = luaL_checkudata(L, 2, "Vector2");
    const float thickness = luaL_checknumber(L, 3);
    const Color *c = luaL_checkudata(L, 4, "Color");
    DrawLineEx(*start, *end, thickness, *c);
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
    const Vector2 *position = luaL_checkudata(L, 1, "Vector2");
    const float radius = luaL_checknumber(L, 2);
    const Color *c = luaL_checkudata(L, 3, "Color");
    DrawCircleV(*position, radius, *c);
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
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const float radius = luaL_checknumber(L, 3);
    const Color *c = luaL_checkudata(L, 4, "Color");
    DrawCircleLines(x, y, radius, *c);
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
    const Vector2 *position = luaL_checkudata(L, 1, "Vector2");
    const float radius = luaL_checknumber(L, 2);
    const int startAngle = luaL_checkinteger(L, 3);
    const int endAngle = luaL_checkinteger(L, 4);
    const int segments = luaL_checkinteger(L, 5);
    const Color *c = luaL_checkudata(L, 6, "Color");
    DrawCircleSector(*position, radius, startAngle, endAngle, segments, *c);
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
    const Vector2 *position = luaL_checkudata(L, 1, "Vector2");
    const float radius = luaL_checknumber(L, 2);
    const int startAngle = luaL_checkinteger(L, 3);
    const int endAngle = luaL_checkinteger(L, 4);
    const int segments = luaL_checkinteger(L, 5);
    const Color *c = luaL_checkudata(L, 6, "Color");
    DrawCircleSectorLines(*position, radius, startAngle, endAngle, segments, *c);
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
    const int x = luaL_checkinteger(L, 1);
    const int y = luaL_checkinteger(L, 2);
    const float radius = luaL_checknumber(L, 3);
    const Color *c1 = luaL_checkudata(L, 4, "Color");
    const Color *c2 = luaL_checkudata(L, 5, "Color");
    DrawCircleGradient(x, y, radius, *c1, *c2);
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

    lua_pushcfunction(L, graphics2d_draw_rectangle_rec);
    lua_setfield(L, -2, "DrawRectangleRec");

    lua_pushcfunction(L, graphics2d_draw_rectangle_lines);
    lua_setfield(L, -2, "DrawRectangleLines");

    lua_pushcfunction(L, graphics2d_draw_rectangle_rounded);
    lua_setfield(L, -2, "DrawRectangleRounded");

    lua_pushcfunction(L, graphics2d_draw_rectangle_rounded_lines);
    lua_setfield(L, -2, "DrawRectangleRoundedLines");

    lua_pushcfunction(L, graphics2d_draw_rectangle_gradient_v);
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
