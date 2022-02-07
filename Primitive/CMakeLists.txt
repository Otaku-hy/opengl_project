add_library(Primitive "")
target_sources(Primitive
    PRIVAITE
    primitive.hpp
    primitive.cpp
)

target_link_libraries(Iterator PRIVATE OpenGL::GL glfw glm::glm GLEW::GLEW)
target_link_libraries(Iterator PUBLIC Shader )
target_include_directories(Iterator PUBLIC .)
