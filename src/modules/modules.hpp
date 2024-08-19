#include "structs.hpp"
#include "window.hpp"
#include "graphics2d.hpp"
#include "input.hpp"

void bind_modules(lua_State *L) {
    bind_structs(L);
    bind_input_module(L);
    bind_window_module(L);
    bind_graphics2d_module(L);
}