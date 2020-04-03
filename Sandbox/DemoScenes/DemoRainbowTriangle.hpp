//
// Created by Francisco J. Sanchez on 03/04/2020.
//

#ifndef _DEMORAINBOWTRIANGLE_HPP_
#define _DEMORAINBOWTRIANGLE_HPP_

#include "Sandbox/Scene.hpp"
#include "ZEN/zen.h"
#include <glm/glm.hpp>

namespace Sandbox {
    class DemoRainbowTriangle : public Scene {
    public:
        DemoRainbowTriangle();

        void OnRender() override;

        void OnUpdate(float deltaTime) override;

        void OnImGuiRender() override;

    private:
        int m_Width, m_Height;

        zen::VertexArray m_va;
        zen::IndexBuffer m_ib;
        zen::VertexBuffer m_vb;

        glm::vec3 m_Translation;
        glm::vec3 m_Scale;
        bool m_EnableRotation;
        float m_Rotation;
        glm::mat4 m_Proj, m_View, m_Model;

        zen::Shader m_Shader;

        zen::Renderer m_Renderer;
    };
}

#endif // _DEMORAINBOWTRIANGLE_HPP_
