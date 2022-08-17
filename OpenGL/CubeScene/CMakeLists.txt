cmake_minimum_required(VERSION 3.11)

project(Cubes)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

set(EXEC cubes)

add_executable(${EXEC} cubes.cpp)

target_link_libraries(${EXEC} OpenGL::GL GLEW glfw glm::glm)

