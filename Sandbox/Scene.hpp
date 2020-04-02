//
// Created by Francisco José Sánchez Moreno on 31/03/2020.
//

#ifndef _DEMOSCENE_HPP_
#define _DEMOSCENE_HPP_

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

#endif //_DEMOSCENE_HPP_
