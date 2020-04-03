//
// Created by Francisco José Sánchez Moreno on 31/03/2020.
//

#pragma once

#include "Sandbox/Scene.hpp"

namespace Sandbox {
    class DemoClearColor : public Scene {
    public:
        inline DemoClearColor() : m_ClearColor{0.0f, 0.0f, 0.0f, 1.0f} {};
        ~DemoClearColor() override;

        void OnRender() override;
        void OnImGuiRender() override;

    private:
        float m_ClearColor[4];
    };
}
