#include <rendering_iterator.hpp>

namespace OpenGL_TEST
{
    RenderingIterator::RenderingIterator(std::shared_ptr<Camera> camera, int frame_pre_second) : camera_(camera), kFramePreSecond(frame_pre_second)
    {
        auto [width, height] = camera_->film_size();
        window_ = glfwCreateWindow(width, height, "1", nullptr, nullptr);
        glfwMakeContextCurrent(window_);
        glew_config();

        glfwGetFramebufferSize(window_, &width, &height);
        camera_->set_film_size(width, height);

        glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    RenderingIterator::~RenderingIterator()
    {
        glfwTerminate();
    }

    const int &RenderingIterator::frame_pre_second()
    {
        return kFramePreSecond;
    }

    std::shared_ptr<Camera> &RenderingIterator::camera()
    {
        return camera_;
    }

    GLFWwindow *RenderingIterator::window()
    {
        return window_;
    }

    void RenderingIterator::Rendering(std::vector<std::shared_ptr<Shader>> shaders)
    {
        auto [width, height] = camera_->film_size();
        glViewport(0, 0, width, height);

        // camera_->Rotate(glm::vec2(1, 1), 1.8);
        // camera_->Rotate(glm::vec2(-1, 0), 1.8);

        while (!glfwWindowShouldClose(window_))
        {
            InputProcess(this);

            glClearColor(0.0, 0.0, 0.0, 1.0); //重置缓冲区时填充的颜色
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            RenderingEvent(shaders);

            glfwSwapBuffers(window_); //绘制屏幕
            glfwPollEvents();         //处理窗口相关事件，如按键事件

            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(1000 / kFramePreSecond)));
        }
    }

    void RenderingIterator::RenderingEvent(std::vector<std::shared_ptr<Shader>> shaders)
    {
    }

    void InputProcess(RenderingIterator *iterator)
    {
        if (glfwGetKey(iterator->window(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(iterator->window(), true);
        }
        glm::vec3 move_vec = MoveMonitor(iterator);
        if (!IsZero(move_vec))
        {
            iterator->camera()->Translate(move_vec, 1.0 / iterator->frame_pre_second());
        }
    }

    glm::vec3 MoveMonitor(RenderingIterator *iterator)
    {
        glm::vec3 move_vec(0.0f);
        glm::vec3 forward_vec = iterator->camera()->look_direction();
        glm::vec3 left_vec = glm::normalize(glm::cross(glm::vec3(0, 1, 0), forward_vec));
        if (glfwGetKey(iterator->window(), GLFW_KEY_W) == GLFW_PRESS)
        {
            move_vec += forward_vec;
        }
        if (glfwGetKey(iterator->window(), GLFW_KEY_S) == GLFW_PRESS)
        {
            move_vec -= forward_vec;
        }
        if (glfwGetKey(iterator->window(), GLFW_KEY_A) == GLFW_PRESS)
        {
            move_vec += left_vec;
        }
        if (glfwGetKey(iterator->window(), GLFW_KEY_D) == GLFW_PRESS)
        {
            move_vec -= left_vec;
        }

        return move_vec;
    }
} // namespace OpenGL_TEST