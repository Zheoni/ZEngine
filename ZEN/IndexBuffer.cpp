//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#include "GLUtils.hpp"
#include "IndexBuffer.hpp"

namespace zen {
    IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : m_RendererId(0), m_Count(count) {
        ASSERT(sizeof(unsigned int) == sizeof(GLuint));
        GLCall(glGenBuffers(1, &m_RendererId));
        Bind();
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    }

    IndexBuffer::~IndexBuffer() {
        GLCall(glDeleteBuffers(1, &m_RendererId));
    }

    void IndexBuffer::Bind() const {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
    }

    void IndexBuffer::Unbind() {
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
}