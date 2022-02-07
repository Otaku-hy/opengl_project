#include <mesh_loader.hpp>

namespace OpenGL_TEST
{
    std::shared_ptr<Mesh> MeshLoader::operator()(const std::string &filename) //uses a function-liked class to load files
    {
        std::vector<glm::vec3> position;
        std::vector<glm::vec3> normal;
        std::vector<glm::vec2> texture_coordinate;

        std::ifstream file_stream(filename);
        std::string line;

        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();

        while (getline(file_stream, line))
        {
            std::stringstream line_stream(line);
            std::string word;
            while (line_stream >> word)
            {
                if (word == "v")
                {
                    glm::vec3 vertex_pos;
                    line_stream >> vertex_pos.x >> vertex_pos.y >> vertex_pos.z;
                    position.push_back(vertex_pos);
                }
                else if (word == "vn")
                {
                    glm::vec3 vertex_normal;
                    line_stream >> vertex_normal.x >> vertex_normal.y >> vertex_normal.z;
                    normal.push_back(vertex_normal);
                }
                else if (word == "vt")
                {
                    glm::vec2 vertex_texture_coord;
                    line_stream >> vertex_texture_coord.x >> vertex_texture_coord.y;
                    texture_coordinate.push_back(vertex_texture_coord);
                }
                else if (word == "f")
                {
                    std::string vertex_index;
                    while (line_stream >> vertex_index)
                    {
                        auto segment1 = vertex_index.find_first_not_of("0123456789");
                        auto segment2 = vertex_index.find_last_not_of("0123456789");

                        int pos_index = std::stoi(vertex_index.substr(0, segment1));
                        int texture_coord_index = std::stoi(vertex_index.substr(segment1 + 1, segment2 - segment1 - 1));
                        int normal_index = std::stoi(vertex_index.substr(segment2 + 1));

                        mesh->PushBackVertex(position[pos_index - 1], normal[normal_index - 1], texture_coordinate[texture_coord_index - 1]);
                    }
                }
            }
        }

        return mesh;
    }
} //namespace OpenGL_TEST