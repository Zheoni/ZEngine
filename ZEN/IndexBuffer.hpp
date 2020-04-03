//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#pragma once

#include <initializer_list>

namespace zen {
    class IndexBuffer {
    public:
        inline IndexBuffer(std::initializer_list<unsigned int> data) : IndexBuffer(data.begin(), data.size()) {}
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        static void Unbind();

        inline unsigned int GetCount() const { return m_Count; }

    private:
        unsigned int m_RendererId{};
        unsigned int m_Count;
    };
}
