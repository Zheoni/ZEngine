//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#include "VertexArray.hpp"

#include "GLUtils.hpp"

namespace zen {
    VertexArray::VertexArray() : m_RendererID(0) {
        GLCall(glGenVertexArrays(1, &m_RendererID));
    }

    VertexArray::~VertexArray() {
        GLCall(glDeleteVertexArrays(1, &m_RendererID));
    }

    void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
        Bind();
        vb.Bind();
        const std::vector<VertexBufferElement>& elements = layout.GetElements();
        unsigned int offset = 0;
        for (unsigned int i = 0; i < elements.size(); ++i) {
            const auto& element = elements[i];

            GLCall(glEnableVertexAttribArray(i));
            // The casting may raise a warning... but it has to be like this
            GLCall(glVertexAttribPointer(i, element.count, element.type,
                    element.normalized, layout.GetStride(), (const void*) offset));

            offset += element.count * element.GetSizeOfType();

        }
    }

    void VertexArray::Bind() const {
        GLCall(glBindVertexArray(m_RendererID));
    }

    void VertexArray::Unbind() {
        GLCall(glBindVertexArray(0));
    }
}