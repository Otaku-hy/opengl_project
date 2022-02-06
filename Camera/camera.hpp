#ifndef OPENGL_TEST_CAMERA_CAMERA_H_
#define OPENGL_TEST_CAMERA_CAMERA_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL_TEST
{
    class Camera
    {

    public:
        Camera(/* args */);
        ~Camera();

    private:
        glm::vec3 camera_pos_;
        glm::vec3 look_direction_;
        float look_distance_;
        int film_width_, film_height_;

        //default perspective parameter : zNear = 0.1 zFar = 7000 fov = 38.8
    };

} // namespace OpenGL_TEST

#endif