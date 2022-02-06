#include <shader_data_process.hpp>

namespace OpenGL_TEST
{
    void TypeProcess(const std::string &type_name, Uniform &uniform_variable)
    {
        if (type_name == "vec3")
        {
            uniform_variable.variable = glm::vec3(0, 0, 0);
        }
        else if (type_name == "mat4")
        {
            uniform_variable.variable = glm::mat4(1.0f);
        }
        else if (type_name == "int")
        {
            uniform_variable.variable = int{};
        }
        else if (type_name == "float")
        {
            uniform_variable.variable = float{};
        }
    }

    void ShaderUniformProcess(const std::string &filename, const GLuint &shader, std::vector<Uniform> &uniforms)
    {
        std::ifstream file_stream(filename);
        std::string line;
        while (getline(file_stream, line))
        {
            if (line == "void main()")
            {
                break;
            }
            std::string tag;
            std::stringstream line_stream(line);
            line_stream >> tag;
            if (tag == "uniform")
            {
                std::string variable_name;
                const char *variable_name_c = variable_name.c_str();
                line_stream >> tag >> variable_name;
                variable_name = variable_name.substr(0, variable_name.size() - 1);
                auto index = FindUniform(variable_name, uniforms);
                if (index)
                {
                    continue;
                }
                Uniform uniform_variable;
                uniform_variable.name = variable_name;
                uniform_variable.location = glGetUniformLocation(shader, variable_name_c);
                TypeProcess(tag, uniform_variable);
                uniforms.push_back(uniform_variable);
            }
        }
    }

    std::optional<size_t> FindUniform(const std::string &variable_name, const std::vector<Uniform> &uniforms)
    {
        for (size_t i = 0; i < uniforms.size(); i++)
        {
            if (variable_name == uniforms[i].name)
            {
                return i;
            }
        }
        return std::nullopt;
    }

    std::string ShaderSource(const std::string &filename)
    {
        std::ifstream file_stream(filename);
        std::stringstream string_stream;
        string_stream << file_stream.rdbuf();
        std::string shader_source = string_stream.str();

        return shader_source;
    }

} // namespace OpenGL_TEST
