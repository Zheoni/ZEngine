//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#pragma once

#include <csignal>

#define ASSERT(x) if (!(x)) std::raise(SIGTRAP)
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
