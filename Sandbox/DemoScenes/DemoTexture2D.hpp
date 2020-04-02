//
// Created by Francisco J. Sanchez on 02/04/2020.
//

#ifndef _DEMOTEXTURE2D_HPP_
#define _DEMOTEXTURE2D_HPP_

#include "Sandbox/Scene.hpp"
#include "ZEN/zen.h"

namespace Sandbox {

    class DemoTexture2D : public Scene {
    public:
        DemoTexture2D();

        void OnRender() override;

        void OnImGuiRender() override;
    private:
        int m_Width, m_Height;

        zen::VertexArray m_va;
        zen::IndexBuffer m_ib;
        zen::VertexBuffer m_vb;

        glm::vec3 m_Translation;
        glm::vec3 m_Scale;
        float m_Rotation;
        glm::mat4 m_Proj, m_View, m_Model;

        zen::Shader m_Shader;
        zen::Texture m_Texture;

        zen::Renderer m_Renderer;
    };

}


#endif // _DEMOTEXTURE2D_HPP_
