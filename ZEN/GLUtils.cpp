//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#include "GLUtils.hpp"

#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
    if (GLenum error = glGetError()) {
        std::cerr << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << '\n';
        return false;
    } else {
        return true;
    }
}