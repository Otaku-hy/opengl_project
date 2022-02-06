#include <mesh.hpp>

namespace OpenGL_TEST
{
    Mesh::Mesh(/* args */)
    {
    }

    Mesh::~Mesh()
    {
    }

    void Mesh::PushBackVertex(glm::vec3 vertex_position, glm::vec3 vertex_normal, glm::vec2 vertex_texture_coord)
    {
        position_mesh_.push_back(vertex_position);
        normal_mesh_.push_back(vertex_normal);
        texture_coord_mesh_.push_back(vertex_texture_coord);
    }
    
} //namespace OpenGL_TEST