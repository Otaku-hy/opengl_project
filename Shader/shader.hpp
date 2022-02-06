#ifndef OPENGL_TEST_SHADER_SHADER_H
#define OPENGL_TEST_SHADER_SHADER_H

#include <variant>
#include <string>
#include <vector>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader_data_process.hpp>
#include <Mesh/vertex_object.hpp>

namespace OpenGL_TEST
{

    class Shader
    {
    public:
        Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path);
        Shader(const Shader &other) = delete;
        Shader(Shader &&other);
        ~Shader();

        Shader &operator=(const Shader &other) = delete;
        Shader &operator=(Shader &&other);

        glm::mat4 model_mat();

        void BindShader();
        void SetUniform(const std::string &variable_name, int variable);
        void SetUniform(const std::string &variable_name, float variable);
        void SetUniform(const std::string &variable_name, glm::vec3 variable);
        void SetUniform(const std::string &variable_name, glm::mat4 variable);
        void SetUniforms(std::vector<Uniform> uniforms);
        void BindObjectToShader(std::shared_ptr<VertexObject> object_ptr);
        void DrawObjects();

    private:
        std::vector<Uniform> uniforms_;
        std::shared_ptr<VertexObject> object_ptr_;
        GLuint shader_;
    };

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_SHADER_SHADER_H