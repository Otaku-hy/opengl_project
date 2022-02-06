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

namespace OpenGL_TEST
{
    class RenderingIterator
    {
    public:
        explicit RenderingIterator(GLFWwindow* window,int frame_pre_second);
        RenderingIterator(const RenderingIterator& other) = delete;
        RenderingIterator(RenderingIterator&& other) = delete;
        virtual ~RenderingIterator();

        RenderingIterator& operator=(const RenderingIterator& other) = delete;
        RenderingIterator& operator=(RenderingIterator&& other) = delete;
        void Rendering(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shader>> shaders);

        virtual void RenderingEvent(std::shared_ptr<Camera> camera,std::vector<std::shared_ptr<Shader>> shaders);

    protected:
        GLFWwindow *window_;
        int window_width_, window_height_;

    private:
        const int kFramePreSecond;
    };

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_ITERATOR_RENDERING_H_