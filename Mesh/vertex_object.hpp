#ifndef OPENGL_TEST_MESH_VERTEX_OBJECT_H_
#define OPENGL_TEST_MESH_VERTEX_OBJECT_H_

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <mesh.hpp>

namespace OpenGL_TEST
{
    class VertexObject // uses a VertexObject to both process vbo vao
    {                  // after init this object, mesh can be delete
    public:
        explicit VertexObject(std::shared_ptr<Mesh> mesh);
        VertexObject(const VertexObject &other) = delete;
        VertexObject(VertexObject &&other);

        ~VertexObject();

        VertexObject &operator=(const VertexObject &other) = delete;
        VertexObject &operator=(VertexObject &&other);

        glm::mat4 model_mat();

        void BindVertexObject();
        void ReleaseVertexObject();
        void SendDataToVBO(std::shared_ptr<Mesh> mesh);
        void SetModelMatrixValue(const glm::mat4& matrix);

        void DrawObjectOnScreen();

    private:
        GLuint vbos_[3];
        GLuint vao_;
        size_t vertex_size_;

        glm::mat4 model_mat_;
    };

} // namespace OpenGL_TEST

#endif // OPENGL_TEST_MESH_VERTEX_OBJECT_H_