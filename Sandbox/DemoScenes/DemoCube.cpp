//
// Created by Francisco J. Sanchez on 03/04/2020.
//

#include "DemoCube.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui/imgui.h>

namespace Sandbox {

    void DemoCube::OnRender(float deltaTime) {
        Scene::OnRender(deltaTime);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_Model = glm::mat4(1.0f);
        for (int i = 0; i < 3; ++i) {
            if (m_RotateSpeed[i] > 0.0f) {
                m_Model = glm::rotate(m_Model, deltaTime * m_RotateSpeed[i], glm::vec3(0==i,1==i, 2==i));
            }
        }

        glm::mat4 MVP = m_Proj * m_View * m_Model;

        m_Shader.Bind();
        m_Shader.SetUniformMat4f("u_MVP", MVP);

        m_Renderer.Draw(m_va, m_ib, m_Shader);

        if (m_ShowWireFrame) {
            m_Shader2.Bind();
            m_Shader2.SetUniformMat4f("u_MVP", MVP);
            m_Shader2.SetUniformNf("u_Color", {m_Color[0], m_Color[1], m_Color[2], m_Color[3]});
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            m_Renderer.Draw(m_va, m_ib, m_Shader2);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    }

    void DemoCube::OnImGuiRender() {
        Scene::OnImGuiRender();

        ImGui::Checkbox("Show wire frame", &m_ShowWireFrame);
        ImGui::SliderFloat3("Rotate", m_RotateSpeed, 0.0f, 1.0f);
        ImGui::Separator();
        if (ImGui::Button("Reset")) {
            m_ShowWireFrame = true;
            m_RotateSpeed[0] = 0.0f;
            m_RotateSpeed[1] = 1.0f;
            m_RotateSpeed[2] = 0.5f;
        }
    }

    DemoCube::DemoCube()
            :
            m_vb({
                         -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, 0.0f, 1.0f,
                         0.5f, -0.5f, -0.5f,        0.3333333333333333f, 0.2549019607843137f, 0.37254901960784315f, 1.0f,
                         0.5f,  0.5f, -0.5f,        0.39215686274509803f, 0.4117647058823529f, 0.39215686274509803f, 1.0f,
                         -0.5f,  0.5f, -0.5f,       0.8431372549019608f, 0.45098039215686275f, 0.3333333333333333f, 1.0f,

                         -0.5f, -0.5f, 0.5f,        0.3137254901960784f, 0.5490196078431373f, 0.8431372549019608f, 1.0f,
                         0.5f, -0.5f, 0.5f,         0.39215686274509803f, 0.7254901960784313f, 0.39215686274509803f, 1.0f,
                         0.5f,  0.5f, 0.5f,         0.9019607843137255f, 0.7843137254901961f, 0.43137254901960786f, 1.0f,
                         -0.5f,  0.5f, 0.5f,        0.8627450980392157f, 0.9607843137254902f, 1.0f, 1.0f
                 }),
            m_ib({
                         // front
                         0, 1, 2,
                         2, 0, 3,
                         // right
                         1, 5, 6,
                         6, 2, 1,
                         // back
                         7, 6, 5,
                         5, 4, 7,
                         // left
                         4, 0, 3,
                         3, 7, 4,
                         // bottom
                         4, 5, 1,
                         1, 0, 4,
                         // top
                         3, 2, 6,
                         6, 7, 3
                 }),
            m_va(),
            m_Proj(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f)),
            m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f))),
            m_Model(1.0f),
            m_Shader("res/shaders/BasicColoredVertex.shader"),
            m_Shader2("res/shaders/Basic.shader"),
            m_ShowWireFrame(true),
            m_RotateSpeed{0.0f, 1.0f, 0.5f},
            m_Color{0.8f, 0.2f, 0.3f, 1.0f} {
        zen::VertexBufferLayout layout;
        layout.PushFloat(3);
        layout.PushFloat(4);
        m_va.AddBuffer(m_vb, layout);

        GLCall(glClearColor(0.4f, 0.4f, 0.4f, 0.5f));
        GLCall(glEnable(GL_DEPTH_TEST));   // Enable depth testing for z-culling
        GLCall(glDepthFunc(GL_LESS));    // Set the type of depth-test
    }

    DemoCube::~DemoCube() {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
        GLCall(glDisable(GL_DEPTH_TEST));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

}
