#ifndef OPENGL_TEST_SHADER_SHADER_DATA_PROCESS_H_
#define OPENGL_TEST_SHADER_SHADER_DATA_PROCESS_H_

#include <variant>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <optional>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL_TEST
{
    struct Uniform
    {
        std::variant<int, float, glm::vec3, glm::mat4> variable;
        std::string name;
        GLuint location;
    };

    void ShaderUniformProcess(const std::string &filename, const GLuint &shader, std::vector<Uniform> &uniforms);
    void TypeProcess(const std::string &type_name, Uniform &uniform_variable);

    std::optional<size_t> FindUniform(const std::string &variable_name, const std::vector<Uniform> &uniforms);
    std::string ShaderSource(const std::string &filename);

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_SHADER_SHADER_DATA_PROCESS_H_