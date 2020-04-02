//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#include "Renderer.hpp"
#include <iostream>

namespace zen {
    void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const {
        shader.Bind();
        va.Bind();
        ib.Bind();
        GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
    }

    void Renderer::Clear() const {
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }
}