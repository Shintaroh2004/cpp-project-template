cmake_minimum_required(VERSION 3.26)

# project setting
project(
    cpp_learning
    VERSION 1.0.0
    DESCRIPTION "cpp template project"
    LANGUAGES CXX
)

# DLL file list
set(DLL_FILES  ./thirdparty/SDL/build/Debug/SDL3.dll)

# import thirdparty lib
add_subdirectory(thirdparty)

# build User lib
add_library(
    lib STATIC 
    ./src/lib.cpp
)
target_compile_features(lib PRIVATE cxx_std_20)
target_include_directories(
    lib PUBLIC 
    ./include
    ./thirdparty/imgui
    ./thirdparty/imgui/backends
)

# build exe file
add_executable(main main.cpp)
target_include_directories(
    main PRIVATE
    ./thirdparty/imgui
    ./thirdparty/imgui/backends
    ./thirdparty/SDL/include
)
target_link_directories(main PRIVATE ./thirdparty/SDL/build/Debug)
target_link_libraries(main lib imgui SDL3)

# export DLL files to bin directory
file(COPY ${DLL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)