add_library(Iterator "")

target_sources(Iterator
    PRIVATE
    rendering_iterator.hpp
    rendering_iterator.cpp
    iterator1.hpp
    iterator1.cpp    
)

target_link_libraries(Iterator PRIVATE OpenGL::GL glfw glm::glm GLEW::GLEW Threads::Threads)
target_link_libraries(Iterator PUBLIC Shader)
target_include_directories(Iterator PUBLIC .)