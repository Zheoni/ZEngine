//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#ifndef _VERTEXBUFFERLAYOUT_H_
#define _VERTEXBUFFERLAYOUT_H_

#include <vector>
#include "GLUtils.hpp"

namespace zen {
    struct VertexBufferElement {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        inline unsigned int GetSizeOfType() const {
            return GetSizeOfType(type);
        }

        static unsigned int GetSizeOfType(unsigned int type);
    };

    class VertexBufferLayout {
    public:
        inline VertexBufferLayout() : m_Elements(), m_Stride(0) {}

        inline void PushFloat(unsigned int count) {
            _push({GL_FLOAT, count, GL_FALSE});
        }

        inline void PushUInt(unsigned int count) {
            _push({GL_UNSIGNED_INT, count, GL_FALSE});
        }

        inline void PushUChar(unsigned int count) {
            _push({GL_UNSIGNED_BYTE, count, GL_TRUE});
        }

        inline const std::vector<VertexBufferElement>& GetElements() const {
            return m_Elements;
        }

        inline unsigned int GetStride() const {
            return m_Stride;
        }

    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

        void _push(const VertexBufferElement& element);
    };
}


#endif //_VERTEXBUFFERLAYOUT_H_
