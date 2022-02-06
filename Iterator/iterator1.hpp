#ifndef OPENGL_TEST_ITERATOR_1_H_
#define OPENGL_TEST_ITERATOR_1_H_

#include <rendering_iterator.hpp>

namespace OpenGL_TEST
{
    class Iterator1 : public RenderingIterator
    {
    private:
        /* data */
    public:
        Iterator1(GLFWwindow* window,int frame_pre_second);
        ~Iterator1() override;

        void RenderingEvent(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shader>> shaders) override;
    };

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_ITERATOR_1_H