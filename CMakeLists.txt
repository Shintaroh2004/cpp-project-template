cmake_minimum_required(VERSION 3.26)

project(
    cpp_learning
    VERSION 1.0.0
    DESCRIPTION "cpp template project"
    LANGUAGES CXX
)

include_directories(
    ./include
    ./thirdparty/eigen
)

add_library(lib STATIC 
    ./src/lib.cpp
    ./src/work2.cpp
    ./src/work3.cpp
    ./src/work4.cpp
    ./src/work5.cpp
    ./src/work6.cpp
    ./src/work7.cpp
    ./src/work8.cpp
    ./src/work9.cpp
)

add_executable(main main.cpp)
target_compile_features(main PUBLIC cxx_std_20)
target_link_libraries(main lib)