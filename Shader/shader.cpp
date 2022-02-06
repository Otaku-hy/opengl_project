#include <shader.hpp>

namespace OpenGL_TEST
{
    Shader::Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path)
    {
        GLuint vertex_shader, fragment_shader;
        int success;
        char info_log[512];

        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertex_shader_src_string = ShaderSource(vertex_shader_path);
        std::string fragment_shader_src_string = ShaderSource(fragment_shader_path);
        const char *vertex_shader_source = vertex_shader_src_string.c_str();
        const char *fragment_shader_source = fragment_shader_src_string.c_str();

        glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);

        glCompileShader(vertex_shader);
        glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << info_log << std::endl;
        };
        glCompileShader(fragment_shader);
        glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                      << info_log << std::endl;
        };

        shader_ = glCreateProgram();
        glAttachShader(shader_, vertex_shader);
        glAttachShader(shader_, fragment_shader);
        glLinkProgram(shader_);

        glGetProgramiv(shader_, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader_, 512, NULL, info_log);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << info_log << std::endl;
        }

        // ShaderUniformProcess(vertex_shader_path, shader_, uniforms_);
        // ShaderUniformProcess(fragment_shader_path, shader_, uniforms_);

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    Shader::Shader(Shader &&other)
    {
        shader_ = other.shader_;
        other.shader_ = 0;
        uniforms_ = std::move(other.uniforms_);
    }

    Shader::~Shader()
    {
        glDeleteProgram(shader_);
    }

    Shader &Shader::operator=(Shader &&other)
    {
        this->~Shader();
        new (this) Shader(std::move(other));
        return *this;
    }

    glm::mat4 Shader::model_mat()
    {
        return object_ptr_->model_mat();
    }

    void Shader::SetUniform(const std::string &variable_name, int variable)
    {
        // auto index = FindUniform(variable_name, uniforms_);
        GLuint variable_location = glGetUniformLocation(this->shader_, variable_name.c_str());
        glUniform1i(variable_location, variable);
    }

    void Shader::SetUniform(const std::string &variable_name, float variable)
    {
        GLuint variable_location = glGetUniformLocation(this->shader_, variable_name.c_str());
        glUniform1f(variable_location, variable);
    }

    void Shader::SetUniform(const std::string &variable_name, glm::vec3 variable)
    {
        GLuint variable_location = glGetUniformLocation(this->shader_, variable_name.c_str());
        glUniform3fv(variable_location, 1, &variable[0]);
    }

    void Shader::SetUniform(const std::string &variable_name, glm::mat4 variable)
    {
        GLuint variable_location = glGetUniformLocation(this->shader_, variable_name.c_str());
        glUniformMatrix4fv(variable_location, 1, GL_FALSE, &variable[0][0]);
    }

    void Shader::SetUniforms(std::vector<Uniform> uniforms)
    {
        for (auto &uniform : uniforms)
        {
            std::visit([&](auto &value)
                       { SetUniform(uniform.name, value); },
                       uniform.variable);
        }
    }

    void Shader::BindObjectToShader(std::shared_ptr<VertexObject> object_ptr)
    {
        object_ptr_ = object_ptr;
    }

    void Shader::BindShader()
    {
        glUseProgram(shader_);
    }

    void Shader::DrawObjects()
    {
        object_ptr_->BindVertexObject();
        object_ptr_->DrawObjectOnScreen();
        object_ptr_->ReleaseVertexObject();
    }

} // namespace OpenGL_TEST