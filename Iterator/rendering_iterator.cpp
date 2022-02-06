#include <rendering_iterator.hpp>

namespace OpenGL_TEST
{
    RenderingIterator::RenderingIterator(GLFWwindow *window, int frame_pre_second) : window_(window), kFramePreSecond(frame_pre_second)
    {
        glfwGetFramebufferSize(window_, &window_width_, &window_height_);
    }

    RenderingIterator::~RenderingIterator()
    {
        glfwTerminate();
    }

    void RenderingIterator::Rendering(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shader>> shaders)
    {
        while (!glfwWindowShouldClose(window_))
        {
            InputProcess(window_);
            glViewport(0, 0, window_width_, window_height_);
            glClearColor(0.0, 0.0, 0.0, 1.0); //重置缓冲区时填充的颜色
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            RenderingEvent(camera, shaders);

            glfwSwapBuffers(window_); //绘制屏幕
            glfwPollEvents();         //处理窗口相关事件，如按键事件

            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000 / kFramePreSecond)));
        }
    }

    void RenderingIterator::RenderingEvent(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shader>> shaders)
    {
    }
} // namespace OpenGL_TEST