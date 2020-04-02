//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <initializer_list>
#include <unordered_map>
#include <glm/detail/type_mat4x4.hpp>

namespace zen {
    class Shader {
    public:
        struct ShaderProgramSource {
            std::string VertexSource;
            std::string FragmentSource;
        };

        explicit Shader(const ShaderProgramSource& source);
        inline explicit Shader(const std::string& filepath) : Shader(ParseShader(filepath)) {
            m_FilePath = filepath;
        };
        ~Shader();

        void Bind() const;
        static void Unbind();

        inline const std::string& GetFilePath() const {
            return m_FilePath;
        }

        // Set uniforms
        void SetUniformNf(const std::string& name, std::initializer_list<float> values);
        void SetUniformNi(const std::string& name, std::initializer_list<int> values);

        void SetUniformMat4f(const std::string& name, const glm::mat4& mat);

    private:
        unsigned int m_RendererID;
        std::string m_FilePath;

        std::unordered_map<std::string, int> m_UniformLocationCache;

        static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

        static ShaderProgramSource ParseShader(const std::string& filepath);
        static unsigned int CompileShader(unsigned int type, const std::string& source);

        int GetUniformLocation(const std::string& name);
    };
}


#endif //_SHADER_H_
