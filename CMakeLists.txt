cmake_minimum_required(VERSION 3.26)

project(
    cpp_d3d12
    VERSION 1.0.0
    DESCRIPTION "cpp DirectX12 3D project"
    LANGUAGES CXX
)

add_library(
    d3d12_texture STATIC
    "src/D3D12HelloTexture.cpp"
    "src/DXSample.cpp"
    "src/stdafx.cpp"
    "src/Win32Application.cpp"
)
target_include_directories(
    d3d12_texture PUBLIC
    "./include"
    "D:/dev/DirectX-Headers/include"
    "D:/dev/DirectXTex/include"
)
target_link_directories(
    d3d12_texture PUBLIC
    "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um/x64"
)
target_link_libraries(
    d3d12_texture PUBLIC
    d3d12
    d3dcompiler
    dxgi
    dxguid
)

add_executable(main WIN32 main.cpp)
target_link_libraries(main PRIVATE d3d12_texture)