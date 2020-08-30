cmake_minimum_required(VERSION 3.17)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 14)
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/lib/glad)
set(GLEW_DIR ${CMAKE_SOURCE_DIR}/lib/glew)

add_executable(opengl_tutorial src/main.cpp src/shader.h src/shader.cpp)


# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL  "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/glfw)
include_directories(${CMAKE_SOURCE_DIR}/lib/glfw/include)

#glad
add_library(glad ${GLAD_DIR}/src/glad.c)
target_include_directories(glad PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)

#glew
#add_subdirectory(${GLEW_DIR}/build/cmake)
#target_include_directories(glew PRIVATE ${GLEW_DIR}/include)
#target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_DIR}/include)

target_link_libraries(opengl_tutorial glfw glad)
