#include <camera.hpp>

namespace OpenGL_TEST
{
    Camera::Camera(glm::vec3 camera_pos, glm::vec3 look_pos, int film_width, int film_height)
        : camera_pos_(camera_pos), film_width_(film_width), film_height_(film_height)
    {
        look_direction_ = glm::normalize(look_pos - camera_pos_);
        look_distance_ = glm::distance(look_pos, camera_pos_);

        UpdateViewMat();
        UpdateProjectionMat();
    }

    Camera::~Camera()
    {
    }

    std::tuple<int, int> Camera::film_size()
    {
        return {film_width_, film_height_};
    }

    glm::vec3 &Camera::look_direction()
    {
        return look_direction_;
    }

    glm::vec3 &Camera::camera_pos()
    {
        return camera_pos_;
    }

    glm::mat4 &Camera::view_mat()
    {
        return view_mat_;
    }

    glm::mat4 &Camera::projection_mat()
    {
        return projection_mat_;
    }

    void Camera::set_film_size(int film_width, int film_height)
    {
        film_width_ = film_width;
        film_height_ = film_height;

        UpdateProjectionMat();
    }

    void Camera::UpdateViewMat()
    {
        view_mat_ = glm::lookAt(camera_pos_, camera_pos_ + look_direction_ * look_distance_, glm::vec3(0, 1, 0));
    }

    void Camera::UpdateProjectionMat()
    {
        projection_mat_ = glm::perspective(glm::radians(38.8f), float(film_width_) / film_height_, 0.1f, 7000.0f);
    }

    void Camera::Translate(glm::vec3 move_vec, float move_time)
    {
        camera_pos_ = camera_pos_ + glm::normalize(move_vec) * move_time * kMoveSpeed;
        UpdateViewMat();
    }

    void Camera::Rotate(glm::vec2 rotate_vec, float rotate_time)
    {
        float pitch = rotate_vec.y * rotate_time * kRotateSpeed;
        float yaw = rotate_vec.x * rotate_time * kRotateSpeed;

        if (glm::dot(look_direction_, glm::vec3(0, 1, 0)) > 0.95f && pitch > 0)
        {
            return;
        }
        if (glm::dot(look_direction_, glm::vec3(0, 1, 0)) < -0.95f && pitch < 0)
        {
            return;
        }

        glm::vec3 left_vec = glm::normalize(glm::cross(glm::vec3(0, 1, 0), look_direction_));
        glm::vec3 up_vec = glm::normalize(glm::cross(look_direction_, left_vec));

        glm::vec3 direction;
        direction.y = std::sin(glm::radians(pitch));
        direction.x = std::cos(glm::radians(pitch)) * std::sin(glm::radians(yaw));
        direction.z = std::cos(glm::radians(pitch)) * std::cos(glm::radians(yaw));

        look_direction_ = direction.x * left_vec + direction.y * up_vec + direction.z * look_direction_;
        UpdateViewMat();
    }

    // TODO: adds a lock to make sure the camera will not upset down
} // namespace OpenGL_TEST