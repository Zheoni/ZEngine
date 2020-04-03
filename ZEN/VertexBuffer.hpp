//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#pragma once

#include <initializer_list>

namespace zen {
    class VertexBuffer {
    public:
        template<typename T>
        inline VertexBuffer(std::initializer_list<T> data) : VertexBuffer(data.begin(), data.size() * sizeof(T)) {}
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        static void Unbind();
    private:
        unsigned int m_RendererId{};
    };
}
