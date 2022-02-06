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

int main()
{
    glfw_config();

    GLFWwindow *window = glfwCreateWindow(700, 700, "abc", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glew_config();
    SetOpenGLParameter();

    MeshLoader loader;
    auto r = loader("../model/box1.obj");
    std::shared_ptr<VertexObject> mesh_object = std::make_shared<VertexObject>(r);
    // r->~Mesh();

    std::shared_ptr<Shader> shader = std::make_shared<Shader>("../ShaderSource/vert.glsl", "../ShaderSource/frag.glsl");
    shader->BindObjectToShader(mesh_object);
    // std::cout << ShaderSource("../ShaderSource/vert.glsl");

    glm::mat4 model_mat(1.0f);
    model_mat = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0, 1, 0));
    mesh_object->SetModelMatrixValue(model_mat);

    std::shared_ptr<Camera> pc = std::make_shared<Camera>();
    std::vector<std::shared_ptr<Shader>> vs;
    vs.push_back(shader);

    Iterator1 iter(window, 60);
    iter.Rendering(pc, vs);

}