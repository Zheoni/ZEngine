//
// Created by Francisco José Sánchez Moreno on 31/03/2020.
//

#pragma once

namespace Sandbox {

    class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void OnUpdate(float deltaTime) {}
        virtual void OnRender() {}
        virtual void OnImGuiRender() {};
    };

}
