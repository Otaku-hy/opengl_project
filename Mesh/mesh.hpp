#ifndef OPENGL_TEST_MESH_MESH_H_
#define OPENGL_TEST_MESH_MESH_H_

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OpenGL_TEST
{
    class Mesh
    {
    public:
        Mesh(/* args */);
        ~Mesh();

        void PushBackVertex(glm::vec3 vertex_position,glm::vec3 vertex_normal,glm::vec2 vertex_texture_coord);

        std::vector<glm::vec3> position_mesh_;
        std::vector<glm::vec3> normal_mesh_;
        std::vector<glm::vec2> texture_coord_mesh_;
    };

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_MESH_MESH_H_