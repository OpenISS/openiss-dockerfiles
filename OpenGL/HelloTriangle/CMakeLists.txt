cmake_minimum_required(VERSION 3.11)

project(HelloTriangle)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

set(EXEC triangle)

add_executable(${EXEC} triangle.cpp)

target_link_libraries(${EXEC} OpenGL::GL GLEW glfw glm::glm)

