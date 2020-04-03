//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#pragma once

#include <string>

namespace zen {

    class Texture {
    public:
        explicit Texture(const std::string &path);

        ~Texture();

        void Bind(unsigned int slot = 0) const;

        static void Unbind();

        inline int GetWidth() const { return m_Width; }

        inline int GetHeight() const { return m_Height; }

    private:
        unsigned int m_RendererID;
        std::string m_FilePath;
        unsigned char *m_LocalBuffer;
        int m_Width, m_Height, m_BPP;
    };

}
