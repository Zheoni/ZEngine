cmake_minimum_required(VERSION 3.15)

add_library(zen GLUtils.cpp IndexBuffer.cpp Renderer.cpp Shader.cpp Texture.cpp VertexArray.cpp VertexBuffer.cpp VertexBufferLayout.cpp)
target_link_libraries(zen glad)
target_link_libraries(zen glfw)
target_link_libraries(zen stb_image)
target_link_libraries(zen glm)


target_include_directories(zen INTERFACE ../ZEN/)