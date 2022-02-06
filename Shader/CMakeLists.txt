add_library(Shader "")
target_sources(Shader
    PRIVATE
    shader.hpp
    shader.cpp
    shader_data_process.hpp
    shader_data_process.cpp
)

target_include_directories(Shader PUBLIC .)
# target_link_libraries(Shader PRIVATE libGLEW.2.2.0.dylib libglfw.3.3.dylib)
target_link_libraries(Shader PRIVATE OpenGL::GL glfw glm::glm GLEW::GLEW)
target_link_libraries(Shader PUBLIC OpenGL::GL Mesh)