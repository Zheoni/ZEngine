//
// Created by Francisco J. Sanchez on 03/04/2020.
//

#include "DemoRainbowTriangle.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>
#include <GLFW/glfw3.h>

namespace Sandbox {

    void DemoRainbowTriangle::OnRender() {
        Scene::OnRender();
        m_Model = glm::mat4(1.0f);
        m_Model = glm::translate(m_Model, m_Translation);
        if (m_EnableRotation) m_Model = glm::rotate(m_Model, m_Rotation, glm::vec3(0, 0, 1));
        m_Model = glm::scale(m_Model, m_Scale);

        glm::mat4 MVP = m_Proj * m_View * m_Model;

        m_Shader.Bind();
        m_Shader.SetUniformMat4f("u_MVP", MVP);

        m_Renderer.Draw(m_va, m_ib, m_Shader);
    }

    void DemoRainbowTriangle::OnImGuiRender() {
        Scene::OnImGuiRender();
        ImGui::SliderFloat2("Translation", &m_Translation.x, 0.0f, (float) (m_Width > m_Height ? m_Width : m_Height));
        ImGui::SliderFloat2("Scale", &m_Scale.x, 1.0f, 1000);
        ImGui::Checkbox("Rotate", &m_EnableRotation);
        ImGui::Separator();
        if (ImGui::Button("Reset")) {
            m_Translation = glm::vec3((float) m_Width / 2, (float) m_Height / 2, 0.0f);
            m_Scale = glm::vec3(300, 300, 1);
            m_Rotation = 0.0f;
        }
    }

    DemoRainbowTriangle::DemoRainbowTriangle()
            :
            m_Width(),
            m_Height(),
            m_va(),
            m_ib({0, 1, 2}),
            m_vb({-0.5f, -1.0f / (2.0f * sqrtf(3.0f)),      1.0f, 0.0f, 0.0f,
                  0.5f, -1.0f / (2.0f * sqrtf(3.0f)),       0.0f, 1.0f, 0.0f,
                  0.0f, 1.0f / sqrtf(3.0f),                 0.0f, 0.0f, 1.0f
                 }),
            m_Translation(),
            m_EnableRotation(true),
            m_Rotation(0.0f),
            m_Scale(300.0f, 300.0f, 1.0f),
            m_Proj(),
            m_View(glm::mat4(1.0f)),
            m_Model(glm::mat4(1.0f)),
            m_Shader("res/shaders/BasicColoredVertex.shader"),
            m_Renderer() {

        glfwGetWindowSize(glfwGetCurrentContext(), &m_Width, &m_Height);

        m_Translation = glm::vec3((float) m_Width / 2, (float) m_Height / 2, 0);
        m_Proj = glm::ortho(0.0f, (float) m_Width, 0.0f, (float) m_Height, -1.0f, 1.0f);

        zen::VertexBufferLayout layout;
        layout.PushFloat(2);
        layout.PushFloat(3);
        m_va.AddBuffer(m_vb, layout);
    }

    void DemoRainbowTriangle::OnUpdate(float deltaTime) {
        Scene::OnUpdate(deltaTime);
        m_Rotation = deltaTime;
    }
}