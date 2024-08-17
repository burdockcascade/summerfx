add_requires("raylib 5.0", "lua 5.4.7")

add_rules("mode.debug", "mode.release")

set_languages("c++17")

target("summerfx")
    add_packages("raylib", "lua")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("src/modules/*.cpp")
