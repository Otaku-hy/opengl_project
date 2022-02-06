add_library(Mesh "")
target_sources(Mesh
    PRIVATE
    mesh_loader.hpp
    mesh_loader.cpp
    mesh.hpp
    mesh.cpp
    vertex_object.hpp
    vertex_object.cpp
)

# target_link_libraries(Mesh PRIVATE libGLEW.2.2.0.dylib libglfw.3.3.dylib)
target_link_libraries(Mesh PRIVATE OpenGL::GL glfw glm::glm GLEW::GLEW)
target_include_directories(Mesh PUBLIC .)