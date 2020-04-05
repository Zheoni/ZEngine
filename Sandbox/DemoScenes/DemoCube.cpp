//
// Created by Francisco J. Sanchez on 03/04/2020.
//

#include "DemoCube.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace Sandbox {

    void DemoCube::OnRender(float deltaTime) {
        Scene::OnRender(deltaTime);

        glm::mat4 MVP = m_Proj * m_View * m_Model;

        m_Shader.Bind();
        m_Shader.SetUniformNf("u_Color", {m_Color[0], m_Color[1], m_Color[2], m_Color[3]});
        m_Shader.SetUniformMat4f("u_MVP", MVP);

        m_Renderer.Draw(m_va, m_ib, m_Shader);
    }

    void DemoCube::OnImGuiRender() {
        Scene::OnImGuiRender();
    }

    DemoCube::DemoCube()
            :
            m_vb({
                         -0.5f, -0.5f, -0.5f,
                         0.5f, -0.5f, -0.5f,
                         0.5f,  0.5f, -0.5f,
                         -0.5f,  0.5f, -0.5f,

                         -0.5f, -0.5f, 0.5f,
                         0.5f, -0.5f, 0.5f,
                         0.5f,  0.5f, 0.5f,
                         -0.5f,  0.5f, 0.5f,
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
            m_Proj(1.0f),
            m_View(1.0f),
            m_Model(1.0f),
            m_Shader("res/shaders/Basic.shader"),
            m_Color{0.8f, 0.2f, 0.3f, 1.0f} {
        zen::VertexBufferLayout layout;
        layout.PushFloat(3);
        m_va.AddBuffer(m_vb, layout);
        GLCall(glClearColor(0.4f, 0.4f, 0.4f, 0.5f));
        //glClearDepth(1.0f);                   // Set background depth to farthest
        //glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
        //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
        //glShadeModel(GL_SMOOTH);

        //m_Proj = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f, -4.0f, 4.0f);
        m_Model = glm::rotate(m_Model, glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));
        m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -3.0f));
        m_Proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    }

    DemoCube::~DemoCube() {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
    }

}
