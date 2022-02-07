#ifndef OPENGL_TEST_HELP_FUNCTION_H_
#define OPENGL_TEST_HELP_FUNCTION_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL_TEST
{
    inline bool IsZero(glm::vec3 vec)
    {
        if (vec.x != 0 || vec.y != 0 || vec.z != 0)
        {
            return false;
        }
        return true;
    }
} // namespace OpenGL_TEST

#endif // OPENGL_TEST_HELP_FUNCTION_H_