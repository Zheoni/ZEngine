cmake_minimum_required(VERSION 3.15)

add_library(stb_image src/stb_image.cpp)
link_libraries(stb_image glad)

target_include_directories(stb_image INTERFACE include/)