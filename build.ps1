cmake -S . -B build -DCMAKE_BUILD_TYPE="Debug"
cmake --build build
cmake -S . -B build -DCMAKE_BUILD_TYPE="Release"
cmake --build build
