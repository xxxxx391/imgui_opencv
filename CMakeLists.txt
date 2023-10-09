cmake_minimum_required(VERSION 2.8)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17) 
project(imgui_opencv)

add_definitions(-DNOMINMAX)
include_directories(include)

file(GLOB ADD_HEADERS "./include/*.h*")
SET(HEADERS ${HEADERS} ${ADD_HEADERS})

SET(SOURCE
src/glad.c
)
file(GLOB ADD_SOURCE "./src/*.cpp*")
SET(SOURCE ${SOURCE} ${ADD_SOURCE})

# SOURCE_GROUP("Source Files" FILES ${SOURCE})
# SOURCE_GROUP("Header Files" FILES ${HEADERS})
add_executable(imgui_opencv 
main.cpp
${SOURCE}
${HEADERS})

set(glfw_include "dependencies/glfw-3.3.8/include")
set(glfw_lib_path "dependencies/glfw-3.3.8/build/src/Debug")
set(glfw_lib "glfw3")
include_directories(${glfw_include})
target_link_directories(imgui_opencv PUBLIC ${glfw_lib_path})

target_link_libraries(imgui_opencv 
opengl32.lib
${glfw_lib})

set(glad_include "dependencies/GLAD/include")
include_directories(${glad_include})
# message(STATUS "-------SOURCE--------")
# message(STATUS "${SOURCE}")
# message(STATUS "-------HEADERS--------")
# message(STATUS "${HEADERS}")



