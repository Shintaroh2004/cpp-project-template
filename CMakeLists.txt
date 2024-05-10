cmake_minimum_required(VERSION 3.26)

project(
    cpp_learning
    VERSION 0.0.0
    DESCRIPTION "cpp template project"
    LANGUAGES CXX
)

#Windows向けの設定
if (WIN32)
  #ビルド対象のWindowsの最低バージョン (WIN7)
  add_definitions(-D_WIN32_WINNT=0x0601)
endif()

#Boost用の設定
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS) #プレースホルダーがうるさいのでおまじない
set (BOOST_ROOT "C:/dev")
find_package(Boost REQUIRED COMPONENTS headers)

#ライブラリビルドとか，インクルードディレクトリとか
add_library(lib STATIC ./src/lib.cpp)
target_compile_features(lib PRIVATE cxx_std_20)
target_include_directories(lib PUBLIC ./include ./thirdparty/fast-cpp-csv-parser)
target_link_libraries(lib Boost::headers)

#実行ファイル生成と，ライブラリリンク
add_executable(uutil main.cpp)
target_link_libraries(uutil lib Boost::headers)