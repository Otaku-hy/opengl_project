#include <iterator1.hpp>

namespace OpenGL_TEST
{
    Iterator1::Iterator1(GLFWwindow *window, int frame_pre_second) : RenderingIterator(window, frame_pre_second)
    {
    }

    Iterator1::~Iterator1()
    {
        RenderingIterator::~RenderingIterator();
    }

    void Iterator1::RenderingEvent(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shader>> shaders)
    {
        glm::mat4 view_mat = glm::lookAt(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
        glm::mat4 projection_mat = glm::perspective(glm::radians(38.8f), 1.0f, 0.1f, 7000.0f);

        shaders[0]->BindShader();
        shaders[0]->SetUniform("model_mat", shaders[0]->model_mat());
        shaders[0]->SetUniform("view_mat", view_mat);
        shaders[0]->SetUniform("projection_mat", projection_mat);
        shaders[0]->DrawObjects();
    }
} // namespace OpenGL_TEST