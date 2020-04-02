//
// Created by Francisco José Sánchez Moreno on 30/03/2020.
//

#include "Shader.hpp"

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <glm/glm.hpp>

#include "GLUtils.hpp"

namespace zen {

    Shader::Shader(const Shader::ShaderProgramSource &source) : m_RendererID(0), m_FilePath() {
        m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
    }

    Shader::~Shader() {
        GLCall(glDeleteProgram(m_RendererID));
    }

    void Shader::Bind() const {
        GLCall(glUseProgram(m_RendererID));
    }

    void Shader::Unbind() {
        GLCall(glUseProgram(0));
    }

    int Shader::GetUniformLocation(const std::string& name) {
        auto pos = m_UniformLocationCache.find(name);
        if (pos != m_UniformLocationCache.end()) {
            return pos->second;
        } else {
            GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));

            if (location == -1)
                std::cout << "Warning: uniform '" << name << "' does not exist.\n";

            m_UniformLocationCache[name] = location;

            return location;
        }
    }

    void Shader::SetUniformNf(const std::string& name, std::initializer_list<float> values) {
        int location = GetUniformLocation(name);

        std::vector<float> vals(values);

        switch(values.size()) {
            case 1:
                GLCall(glUniform1f(location, vals[0]));
                break;
            case 2:
                GLCall(glUniform2f(location, vals[0], vals[1]));
                break;
            case 3:
                GLCall(glUniform3f(location, vals[0], vals[1], vals[2]));
                break;
            case 4:
                GLCall(glUniform4f(location, vals[0], vals[1], vals[2], vals[3]));
                break;
            default:
                ASSERT(false);
                break;
        }
    }

    void Shader::SetUniformNi(const std::string& name, std::initializer_list<int> values) {
        int location = GetUniformLocation(name);

        std::vector<int> vals(values);

        switch(values.size()) {
            case 1:
            GLCall(glUniform1i(location, vals[0]));
                break;
            case 2:
            GLCall(glUniform2i(location, vals[0], vals[1]));
                break;
            case 3:
            GLCall(glUniform3i(location, vals[0], vals[1], vals[2]));
                break;
            case 4:
            GLCall(glUniform4i(location, vals[0], vals[1], vals[2], vals[3]));
                break;
            default:
                ASSERT(false);
                break;
        }
    }

    void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& mat) {
        GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat[0][0]));
    }

    Shader::ShaderProgramSource Shader::ParseShader(const std::string& filepath) {
        enum ShaderType {
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };

        std::ifstream file(filepath);

        std::string line;
        std::stringstream ss[2];
        ShaderType type = ShaderType::NONE;
        while (getline(file, line)) {
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType ::FRAGMENT;
            } else {
                ss[(int)type] << line << '\n';
            }
        }

        return { ss[0].str(), ss[1].str() };
    }

    unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
        const unsigned int program = glCreateProgram();
        const unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
        const unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE) {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*) alloca(length * sizeof(char)); // Allocate in the stack, not in the heap
            glGetShaderInfoLog(id, length, &length, message);
            std::cerr << "Failed to compile shader!\n" << message << std::endl;

            glDeleteShader(id);
            return 0;
        }

        return id;
    }
}