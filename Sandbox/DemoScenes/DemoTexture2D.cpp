//
// Created by Francisco J. Sanchez on 02/04/2020.
//

#include "DemoTexture2D.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

namespace Sandbox {

    void DemoTexture2D::OnRender(float deltaTime) {
        Scene::OnRender(deltaTime);
        m_Model = glm::mat4(1.0f);
        m_Model = glm::translate(m_Model, m_Translation);
        m_Model = glm::rotate(m_Model, m_Rotation, glm::vec3(0, 0, 1));
        m_Model = glm::scale(m_Model, m_Scale);

        glm::mat4 MVP = m_Proj * m_View * m_Model;
        m_Shader.Bind();
        m_Shader.SetUniformMat4f("u_MVP", MVP);

        m_Renderer.Draw(m_va, m_ib, m_Shader);
    }

    void DemoTexture2D::OnImGuiRender() {
        Scene::OnImGuiRender();
        ImGui::SliderFloat2("Translation", &m_Translation.x, 0.0f, (float) (m_Width > m_Height ? m_Width : m_Height));
        ImGui::SliderFloat2("Scale", &m_Scale.x, 1.0f, 1000);
        ImGui::SliderAngle("Rotation", &m_Rotation, 0.0f, 360.0f);
        ImGui::Separator();
        if (ImGui::Button("Reset")) {
            m_Translation = glm::vec3((float) m_Width / 2, (float) m_Height / 2, 0.0f);
            m_Scale = glm::vec3(300, 300, 1);
            m_Rotation = 0.0f;
        }
    }

    DemoTexture2D::DemoTexture2D()
        :
        m_Width(), m_Height(),
        m_va(),
        m_ib({0, 1, 2}),
        // Positions of the equilateral triangle and its mapped positions in the texture
        m_vb({
            -0.5f, -1.0f / (2.0f * sqrtf(3.0f)),     0.0f, 0.0f,
             0.5f, -1.0f / (2.0f * sqrtf(3.0f)),     1.0f, 0.0f,
             0.0f,  1.0f / sqrtf(3.0f),              1.0f, 1.0f
             }),
         m_Translation(), m_Scale(300, 300, 300), m_Rotation(0.0f),
         m_Proj(1.0f), m_View(1.0f), m_Model(1.0f),
         m_Shader("res/shaders/Texture.shader"),
         m_Texture("res/textures/texture1.png"),
         m_Renderer()
    {
        glfwGetWindowSize(glfwGetCurrentContext(), &m_Width, &m_Height);

        m_Translation = glm::vec3((float) m_Width / 2, (float) m_Height / 2, 0);
        m_Proj = glm::ortho(0.0f, (float) m_Width, 0.0f, (float) m_Height, -1.0f, 1.0f);

        zen::VertexBufferLayout layout;
        layout.PushFloat(2);
        layout.PushFloat(2);
        m_va.AddBuffer(m_vb, layout);

        m_Shader.Bind();
        m_Texture.Bind(0);
        m_Shader.SetUniformNi("u_Texture", { 0 });
    }

}



