//
// Created by Francisco J. Sanchez on 03/04/2020.
//

#pragma once

#include "Sandbox/Scene.hpp"
#include "ZEN/zen.h"

namespace Sandbox {

    class DemoCube : public Scene {
    public:
        DemoCube();

        ~DemoCube() override;

        void OnRender(float deltaTime) override;

        void OnImGuiRender() override;

    private:
        zen::VertexBuffer m_vb;
        zen::IndexBuffer m_ib;
        zen::VertexArray m_va;

        glm::mat4 m_Proj, m_View, m_Model;

        zen::Shader m_Shader;
        zen::Renderer m_Renderer;

        float m_Color[4];
    };

}
