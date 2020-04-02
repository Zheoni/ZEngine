cmake_minimum_required(VERSION 3.15)

add_library(imgui imgui.cpp imgui_demo.cpp imgui_draw.cpp imgui_impl_glfw.cpp imgui_impl_opengl3.cpp imgui_widgets.cpp)
target_link_libraries(imgui glfw)
target_link_libraries(imgui glad)

target_include_directories(imgui INTERFACE ${CMAKE_SOURCE_DIR})