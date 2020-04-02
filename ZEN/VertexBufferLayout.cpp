//
// Created by Francisco José Sánchez Moreno on 29/03/2020.
//

#include "VertexBufferLayout.hpp"
#include "GLUtils.hpp"

namespace zen {
    unsigned int VertexBufferElement::GetSizeOfType(unsigned int type) {
        switch(type) {
            case GL_FLOAT:          return sizeof(GLfloat);
            case GL_UNSIGNED_INT:   return sizeof(GLuint);
            case GL_UNSIGNED_BYTE:  return sizeof(GLubyte);
        }
        ASSERT(false);
        return 0;
    }

    void VertexBufferLayout::_push(const VertexBufferElement& element) {
        m_Elements.push_back(element);
        m_Stride += element.GetSizeOfType() * element.count;
    }
}
