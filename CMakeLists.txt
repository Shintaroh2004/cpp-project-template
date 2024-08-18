cmake_minimum_required(VERSION 3.26)

project( 
	outopp
	VERSION 0.0.0
)

set(oatpp_DIR D:/dev/oatpp/lib/cmake/oatpp-1.3.0)
find_package(oatpp REQUIRED CONFIG)

add_executable(
	App
	"App.cpp" 
)
target_compile_features(App PRIVATE cxx_std_20)

target_include_directories(
	App PRIVATE
	${oatpp_INCLUDE_DIRS}
)
target_include_directories(
	App PRIVATE
	./include
)

target_link_directories(App PRIVATE ${oatpp_LIBRARIES_DIRS})

if(WIN32)
	target_link_libraries(App oatpp oatpp-test ws2_32)
else()
	target_link_libraries(App oatpp oatpp-test)
endif()
