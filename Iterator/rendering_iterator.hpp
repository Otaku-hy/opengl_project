#ifndef OPENGL_TEST_ITERATOR_RENDERING_H_
#define OPENGL_TEST_ITERATOR_RENDERING_H_

#include <chrono>
#include <thread>
#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <window_event_process.hpp>
#include <Camera/camera.hpp>
#include <Shader/shader.hpp>
#include <help_function.hpp>

namespace OpenGL_TEST
{
    class RenderingIterator
    {
    public:
        explicit RenderingIterator(std::shared_ptr<Camera> camera, int frame_pre_second);
        RenderingIterator(const RenderingIterator &other) = delete;
        RenderingIterator(RenderingIterator &&other) = delete;
        virtual ~RenderingIterator();

        const int &frame_pre_second();
        std::shared_ptr<Camera> &camera();
        GLFWwindow* window();

        RenderingIterator &operator=(const RenderingIterator &other) = delete;
        RenderingIterator &operator=(RenderingIterator &&other) = delete;

        void Rendering(std::vector<std::shared_ptr<Shader>> shaders);

        virtual void RenderingEvent(std::vector<std::shared_ptr<Shader>> shaders);

    protected:
        GLFWwindow *window_;
        std::shared_ptr<Camera> camera_;

    private:
        const int kFramePreSecond;
    };

    void InputProcess(RenderingIterator *iterator);
    glm::vec3 MoveMonitor(RenderingIterator *iterator);

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_ITERATOR_RENDERING_H_