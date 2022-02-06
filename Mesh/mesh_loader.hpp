#ifndef OPENGL_TEST_MESH_MESH_LOADER_H_
#define OPENGL_TEST_MESH_MESH_LOADER_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <mesh.hpp>

namespace OpenGL_TEST
{
    struct MeshLoader
    {
    public:
        std::shared_ptr<Mesh> operator()(const std::string &filename);
    };

} //namespace OpenGL_TEST

#endif // OPENGL_TEST_MESH_MESH_LOADER_H_