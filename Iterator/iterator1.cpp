#include <iterator1.hpp>

namespace OpenGL_TEST
{
    Iterator1::Iterator1(std::shared_ptr<Camera> camera, int frame_pre_second) : RenderingIterator(camera, frame_pre_second)
    {
    }

    Iterator1::~Iterator1()
    {
        RenderingIterator::~RenderingIterator();
    }

    void Iterator1::RenderingEvent(std::vector<std::shared_ptr<Shader>> shaders)
    {
        shaders[0]->BindShader();
        shaders[0]->SetUniform("model_mat", shaders[0]->model_mat());
        shaders[0]->SetUniform("view_mat", camera_->view_mat());
        shaders[0]->SetUniform("projection_mat", camera_->projection_mat());

        shaders[0]->SetUniform("camera_pos", camera_->camera_pos());
        shaders[0]->SetUniform("light_pos", glm::vec3(0, 8, 10));
        shaders[0]->SetUniform("light_color", glm::vec3(1, 1, 1));
        shaders[0]->SetUniform("object_color", glm::vec3(1, 1, 1));

        // uniform vec3 camera_pos;
        // uniform vec3 light_pos;
        // uniform vec3 object_color;
        // uniform vec3 light_color;

        shaders[0]->DrawObjects();
    }
} // namespace OpenGL_TEST