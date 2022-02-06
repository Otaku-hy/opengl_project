cmake_minimum_required(VERSION 3.13)
project(OpenGLTest LANGUAGES CXX)
 
include_directories(/usr/local/Cellar/glfw/3.3.6/include /usr/local/Cellar/glew/2.2.0_1/include /usr/local/Cellar/glm/0.9.9.8/include .)
# link_directories(/usr/local/Cellar/glew/2.2.0_1/lib /usr/local/Cellar/glfw/3.3.6/lib)

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(Threads REQUIRED)

add_subdirectory(Mesh)
add_subdirectory(Shader)
add_subdirectory(Camera)
add_subdirectory(Iterator)

add_executable(gl main.cpp window_event_process.cpp window_event_process.hpp)

set_target_properties(gl PROPERTIES CXX_STANDARD 20)
set_target_properties(gl PROPERTIES CXX_STANDARD_REQUIRED True)

target_link_libraries(gl PUBLIC OpenGL::GL GLEW::GLEW glm::glm glfw Threads::Threads Mesh Shader Camera Iterator)

# target_link_libraries(gl PUBLIC libGLEW.2.2.0.dylib libglfw.3.3.dylib Mesh Shader)





