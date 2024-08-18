#include "structs.hpp"
#include "window.hpp"
#include "graphics2d.hpp"
#include "shapes.hpp"
#include "color.hpp"
#include "math.hpp"

void bind_modules(lua_State *L) {
    bind_structs(L);
    bind_window_module(L);
    bind_graphics2d_module(L);
    bind_color_module(L);
}