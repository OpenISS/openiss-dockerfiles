cmake_minimum_required(VERSION 3.11)

project(GLFWTest)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

set(EXEC glfwTest)

add_executable(${EXEC} glfw_test.cpp)

target_link_libraries(${EXEC} OpenGL::GL GLEW glfw)

