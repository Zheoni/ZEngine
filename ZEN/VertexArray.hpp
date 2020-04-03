//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#ifndef _VERTEXARRAY_H_
#define _VERTEXARRAY_H_

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

namespace zen {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

        void Bind() const;
        static void Unbind();
    private:
        unsigned int m_RendererID;
    };
}

#endif //_VERTEXARRAY_H_
