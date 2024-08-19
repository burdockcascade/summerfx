set_description("SummerFX")
set_version("0.1.0")

add_requires("raylib 5.0", "raygui 4.0", "lua 5.4.7", "tbox 1.7.5")

add_rules("mode.debug", "mode.release")

-- run doc generation on build
before_build(function(target)
    os.exec("lua docs/parse_lua_functions.lua")
end)

target("summerfx")
    set_languages("cxx17")
    add_packages("raylib", "lua", "raygui", "tbox")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/modules/*.cpp")
