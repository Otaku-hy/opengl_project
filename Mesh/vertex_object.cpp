#include <vertex_object.hpp>

namespace OpenGL_TEST
{
    VertexObject::VertexObject(std::shared_ptr<Mesh> mesh)
    {
        glGenBuffers(3, vbos_);
        glGenVertexArrays(1, &vao_);

        SendDataToVBO(mesh);
        model_mat_ = glm::mat4(1.0f);
        vertex_size_ = mesh->position_mesh_.size();
    }

    VertexObject::VertexObject(VertexObject &&other)
    {
        for (int i = 0; i < 3; i++)
        {
            vbos_[i] = other.vbos_[i];
        }
        vao_ = other.vao_;
        other.vao_ = 0;
        for (int i = 0; i < 3; i++)
        {
            other.vbos_[i] = 0;
        }
    }

    VertexObject::~VertexObject()
    {
        glDeleteVertexArrays(1, &vao_);
        glDeleteBuffers(3, vbos_);
    }

    VertexObject &VertexObject::operator=(VertexObject &&other)
    {
        this->~VertexObject();
        new (this) VertexObject(std::move(other));
        return *this;
    }

    glm::mat4 VertexObject::model_mat()
    {
        return model_mat_;
    }

    void VertexObject::BindVertexObject()
    {
        glBindVertexArray(vao_);
    }
    void VertexObject::ReleaseVertexObject()
    {
        glBindVertexArray(0);
    }

    void VertexObject::SendDataToVBO(std::shared_ptr<Mesh> mesh)
    {
        glBindVertexArray(vao_);

        glBindBuffer(GL_ARRAY_BUFFER, vbos_[0]);
        glBufferData(GL_ARRAY_BUFFER, mesh->position_mesh_.size() * sizeof(glm::vec3), &mesh->position_mesh_[0], GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vbos_[1]);
        glBufferData(GL_ARRAY_BUFFER, mesh->normal_mesh_.size() * sizeof(glm::vec3), &mesh->normal_mesh_[0], GL_STATIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)(mesh->position_mesh_.size()));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, vbos_[2]);
        glBufferData(GL_ARRAY_BUFFER, mesh->texture_coord_mesh_.size() * sizeof(glm::vec2), &mesh->texture_coord_mesh_[0], GL_STATIC_DRAW);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)(mesh->position_mesh_.size() + mesh->normal_mesh_.size()));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void VertexObject::SetModelMatrixValue(const glm::mat4 &matrix)
    {
        model_mat_ *= matrix;
    }

    void VertexObject::DrawObjectOnScreen()
    {
        glDrawArrays(GL_TRIANGLES, 0, vertex_size_);
    }

} // namespace OpenGL_TEST