
cmake_minimum_required(VERSION 3.10)

project(SimpleGLFW LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

add_executable(opengl-glfw-glew main.cpp)

target_link_libraries(opengl-glfw-glew
    ${OPENGL_LIBRARY}
    glfw
    GLEW
)

