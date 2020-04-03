//
// Created by Francisco José Sánchez Moreno on 31/03/2020.
//

#include "DemoClearColor.hpp"

#include "ZEN/GLUtils.hpp"
#include <imgui/imgui.h>
#include <glad/glad.h>

namespace Sandbox {
    DemoClearColor::~DemoClearColor() {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    }

    void DemoClearColor::OnRender() {
        GLCall(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
    }

    void DemoClearColor::OnImGuiRender() {
        ImGui::ColorEdit4("Clear color", m_ClearColor);
    }
}
