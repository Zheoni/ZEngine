cmake_minimum_required(VERSION 3.15)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

include_directories(vendor/ ./)

add_subdirectory(vendor/glfw/)
add_subdirectory(vendor/glad/)
add_subdirectory(vendor/stb_image/)
add_subdirectory(vendor/glm/)
add_subdirectory(vendor/imgui/)
add_subdirectory(ZEN/)

add_executable(OpenGL main.cpp Sandbox/Scene.hpp Sandbox/DemoScenes/DemoClearColor.cpp Sandbox/DemoScenes/DemoClearColor.hpp Sandbox/DemoScenes/DemoTriangle.cpp Sandbox/DemoScenes/DemoTriangle.hpp Sandbox/DemoScenes/DemoTexture2D.cpp Sandbox/DemoScenes/DemoTexture2D.hpp Sandbox/DemoScenes/DemoRainbowTriangle.cpp Sandbox/DemoScenes/DemoRainbowTriangle.hpp)
target_link_libraries(OpenGL glfw)
target_link_libraries(OpenGL glad)
target_link_libraries(OpenGL stb_image)
target_link_libraries(OpenGL glm)
target_link_libraries(OpenGL imgui)
target_link_libraries(OpenGL zen)