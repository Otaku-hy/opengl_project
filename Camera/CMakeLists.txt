add_library(Camera "")
target_sources(Camera
    PRIVATE
    camera.hpp
    camera.cpp    
)

target_link_libraries(Camera PRIVATE OpenGL::GL GLEW::GLEW glm::glm glfw)
target_include_directories(Camera PUBLIC .)