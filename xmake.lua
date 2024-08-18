set_description("SummerFX")
set_version("0.1.0")

add_requires("raylib 5.0", "lua 5.4.7")

add_rules("mode.debug", "mode.release")

set_languages("c++17")

-- run doc generation on build
before_build(function(target)
    os.exec("lua docs/parse_lua_functions.lua")
end)

target("summerfx")
    add_packages("raylib", "lua")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/modules/*.cpp")
