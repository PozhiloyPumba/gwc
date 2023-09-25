#ifndef __SHADER_HPP__
#define __SHADER_HPP__

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace Graphic_core {

class Shader final {
private:
    unsigned ID_;

    enum class CHECK_COMPILE_ERROR_TYPE { PROGRAM, VERT_SHADER, FRAG_SHADER };
    const char *enum_to_string(CHECK_COMPILE_ERROR_TYPE type) const {
        switch (type) {
        case Shader::CHECK_COMPILE_ERROR_TYPE::PROGRAM:
            return "program";
        case Shader::CHECK_COMPILE_ERROR_TYPE::VERT_SHADER:
            return "vertex";
        case Shader::CHECK_COMPILE_ERROR_TYPE::FRAG_SHADER:
            return "fragment";
        default:
            return "type_error";
        }
    }

    void checkCompileErrors(const int id,
                            const CHECK_COMPILE_ERROR_TYPE type) const;
    void init(const char *vertShaderCode, const char *fragShaderCode);

public:
    Shader() = default;
    Shader(const Shader &) = default;            // copy ctor
    Shader &operator=(const Shader &) = default; // copy assignment
    Shader(Shader &&) = default;                 // move ctor
    Shader &operator=(Shader &&) = default;      // move assignment

    Shader(const std::string &, const std::string &);

    ~Shader() {}

    inline void use() const { glUseProgram(ID_); }

    inline unsigned getID() const { return ID_; }

    template <typename T>
    void setUniform(const std::string &name, const T &var) const;
};

} // namespace MSG

#endif