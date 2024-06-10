cmake_minimum_required(VERSION 3.26)

# build imgui lib
add_library(
    imgui STATIC
    ./imgui/imgui.cpp 
    ./imgui/imgui_tables.cpp
    ./imgui/imgui_draw.cpp
    ./imgui/imgui_widgets.cpp
    ./imgui/imgui_demo.cpp
    ./imgui/backends/imgui_impl_sdlrenderer3.cpp
    ./imgui/backends/imgui_impl_sdl3.cpp
)

# set include dir
target_include_directories(
    imgui PRIVATE
    ./imgui
    ./imgui/backends
    ./SDL/include
)