//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

namespace zen {
    class Renderer {
    public:
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
        void Clear() const;
    };
}

#endif //_RENDERER_HPP_
