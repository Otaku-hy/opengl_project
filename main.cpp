#include <thread>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader.hpp>
#include <mesh.hpp>
#include <mesh_loader.hpp>
#include <vertex_object.hpp>
#include <window_event_process.hpp>
#include <iterator1.hpp>
#include <camera.hpp>

using namespace OpenGL_TEST;

namespace
{
    std::shared_ptr<Camera> pc = std::make_shared<Camera>(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), 700, 700);
    bool first_mouse_interact = true;
    float last_x_pos, last_y_pos;
}

void mouse_callback(GLFWwindow *window, double x_pos_in, double y_pos_in)
{
    float x_pos = static_cast<float>(x_pos_in);
    float y_pos = static_cast<float>(y_pos_in);

    if (first_mouse_interact)
    {
        last_x_pos = x_pos;
        last_y_pos = y_pos;
        first_mouse_interact = false;
    }

    glm::vec2 offset;
    offset.x = last_x_pos - x_pos;
    offset.y = last_y_pos - y_pos;

    last_x_pos = x_pos;
    last_y_pos = y_pos;

    pc->Rotate(offset, 1 / 60.0f);
}

int main()
{
    glfw_config();

    Iterator1 iter(pc, 60);

    SetOpenGLParameter();
    glfwSetCursorPosCallback(iter.window(), mouse_callback);

    MeshLoader loader;
    auto r = loader("../model/box1.obj");
    // for (int i = 0; i < r->normal_mesh_.size(); i++)
    // {
    //     std::cout << r->normal_mesh_[i].x << " " << r->normal_mesh_[i].y << " " << r->normal_mesh_[i].z << std::endl;
    // }

    // r->position_mesh_
    std::shared_ptr<VertexObject>
        mesh_object = std::make_shared<VertexObject>(r);
    glm::mat4 model_mat(1.0f);
    model_mat = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0, 1, 0));
    mesh_object->SetModelMatrixValue(model_mat);

    std::shared_ptr<Shader> shader = std::make_shared<Shader>("../ShaderSource/vert.glsl", "../ShaderSource/frag.glsl");
    shader->BindObjectToShader(mesh_object);
    std::vector<std::shared_ptr<Shader>> vs;
    vs.push_back(shader);

    iter.Rendering(vs);
}