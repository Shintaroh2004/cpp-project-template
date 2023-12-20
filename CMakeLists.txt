cmake_minimum_required(VERSION 3.26)

project(
    cpp_learning
    VERSION 1.0.0
    DESCRIPTION "cpp template project"
    LANGUAGES CXX
)

add_library(lib STATIC ./src/lib.cpp)
target_compile_features(lib PRIVATE cxx_std_20)
target_include_directories(lib PUBLIC ./include)

add_executable(main main.cpp)
target_link_libraries(main lib)