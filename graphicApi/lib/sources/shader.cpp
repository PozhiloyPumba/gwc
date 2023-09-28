#include <shader.hpp>

namespace Graphic_core {

void Shader::checkCompileErrors(const int id,
                                const CHECK_COMPILE_ERROR_TYPE type) const {
    int success;
    constexpr int LENGTH_OF_LOG = 1024;
    char infoLog[LENGTH_OF_LOG];
    switch (type) {
    case CHECK_COMPILE_ERROR_TYPE::PROGRAM: {
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, LENGTH_OF_LOG, NULL, infoLog);
            std::cout
                << "ERROR::PROGRAM_LINKING_ERROR of type: "
                << enum_to_string(type) << "\n"
                << infoLog
                << "\n -- --------------------------------------------------- "
                   "-- "
                << std::endl;
        }
        break;
    }
    case CHECK_COMPILE_ERROR_TYPE::VERT_SHADER:
    case CHECK_COMPILE_ERROR_TYPE::FRAG_SHADER: {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, LENGTH_OF_LOG, NULL, infoLog);
            std::cout
                << "ERROR::SHADER_COMPILATION_ERROR of type: "
                << enum_to_string(type) << "\n"
                << infoLog
                << "\n -- --------------------------------------------------- "
                   "-- "
                << std::endl;
        }
        break;
    }
    default:
        std::cout << "Unknown type of object" << std::endl;
    }
}

void Shader::init(const char *vertShaderCode, const char *fragShaderCode) {
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertShaderCode, NULL);
    glCompileShader(vertexShader);

    checkCompileErrors(vertexShader, CHECK_COMPILE_ERROR_TYPE::VERT_SHADER);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragShaderCode, NULL);
    glCompileShader(fragmentShader);

    checkCompileErrors(fragmentShader, CHECK_COMPILE_ERROR_TYPE::FRAG_SHADER);

    ID_ = glCreateProgram();
    glAttachShader(ID_, vertexShader);
    glAttachShader(ID_, fragmentShader);
    glLinkProgram(ID_);

    checkCompileErrors(ID_, CHECK_COMPILE_ERROR_TYPE::PROGRAM);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::Shader(const std::string &vertShaderData,
               const std::string &fragShaderData) {

    std::string vertShaderCode;
    std::string fragShaderCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        vShaderFile.open(vertShaderData);
        fShaderFile.open(fragShaderData);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertShaderCode = vShaderStream.str();
        fragShaderCode = fShaderStream.str();
    } catch (std::ifstream::failure &e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: "
                    << e.what() << std::endl;
    }
    init(vertShaderCode.c_str(), fragShaderCode.c_str());
}

template <>
void Shader::setUniform(const std::string &name, const int &var) const {
    glUniform1i(glGetUniformLocation(ID_, name.c_str()), var);
}
template <>
void Shader::setUniform(const std::string &name, const float &var) const {
    glUniform1f(glGetUniformLocation(ID_, name.c_str()), var);
}
} // namespace MSG