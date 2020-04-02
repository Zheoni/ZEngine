//
// Created by Francisco J. Sanchez on 01/04/2020.
//

#ifndef _DEMOTRIANGLE_HPP_
#define _DEMOTRIANGLE_HPP_

#include "Sandbox/Scene.hpp"
#include "ZEN/zen.h"
#include <glm/glm.hpp>

namespace Sandbox {
    class DemoTriangle : public Scene {
    public:
        DemoTriangle();

        void OnRender() override;

        void OnImGuiRender() override;

    private:
        int m_Width, m_Height;

        float m_Color[4];

        zen::VertexArray m_va;
        zen::IndexBuffer m_ib;
        zen::VertexBuffer m_vb;

        glm::vec3 m_Translation;
        glm::vec3 m_Scale;
        float m_Rotation;
        glm::mat4 m_Proj, m_View, m_Model;

        zen::Shader m_Shader;

        zen::Renderer m_Renderer;
    };
}


#endif // _DEMOTRIANGLE_HPP_
