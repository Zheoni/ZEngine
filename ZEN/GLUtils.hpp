//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#ifndef _GLUTILS_HPP_
#define _GLUTILS_HPP_

#include <glad/glad.h>

#include <csignal>
#include <cstdio>

#define ASSERT(x) if (!(x)) std::raise(SIGTRAP)
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

#endif //_GLUTILS_HPP_
