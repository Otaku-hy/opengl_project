#ifndef OPENGL_TEST_CAMERA_CAMERA_H_
#define OPENGL_TEST_CAMERA_CAMERA_H_

#include <cmath>
#include <tuple>
#include <iostream>

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
        Camera(glm::vec3 camera_pos, glm::vec3 look_pos, int film_width, int film_height);
        ~Camera();

        std::tuple<int, int> film_size();
        glm::vec3 &look_direction();
        glm::vec3 &camera_pos();
        glm::mat4 &view_mat();
        glm::mat4 &projection_mat();

        void set_film_size(int film_width, int film_height);

        void UpdateViewMat();
        void UpdateProjectionMat();

        void Translate(glm::vec3 move_vec, float move_time);
        void Rotate(glm::vec2 rotate_vec, float rotate_time);

    private:
        glm::mat4 view_mat_, projection_mat_;
        glm::vec3 camera_pos_;
        glm::vec3 look_direction_;
        float look_distance_;
        int film_width_, film_height_;

        const float kMoveSpeed = 3.3;
        const float kRotateSpeed = 8.0;
        // default perspective parameter : zNear = 0.1 zFar = 7000 fov = 38.8
    };

} // namespace OpenGL_TEST

#endif