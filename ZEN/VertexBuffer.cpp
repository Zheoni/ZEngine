//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#include "VertexBuffer.hpp"

#include "GLUtils.hpp"

namespace zen {
    VertexBuffer::VertexBuffer(const void *data, unsigned int size) : m_RendererId(0) {
        GLCall(glGenBuffers(1, &m_RendererId));
        Bind();
        GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));    }

    VertexBuffer::~VertexBuffer() {
        GLCall(glDeleteBuffers(1, &m_RendererId));
    }

    void VertexBuffer::Bind() const {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
    }

    void VertexBuffer::Unbind() {
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
}
