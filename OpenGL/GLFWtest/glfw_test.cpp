#include <iostream>
#include <map>

#define GLEW_STATIC 1
#include <GL/glew.h>

#include <GLFW/glfw3.h>

using namespace std;

map<int, const char*> glfwErrors {
    { GLFW_NO_ERROR           , "GLFW_NO_ERROR" },
    { GLFW_NOT_INITIALIZED    , "GLFW_NOT_INITIALIZED" },
    { GLFW_NO_CURRENT_CONTEXT , "GLFW_NO_CURRENT_CONTEXT" },
    { GLFW_INVALID_ENUM       , "GLFW_INVALID_ENUM" },
    { GLFW_INVALID_VALUE      , "GLFW_INVALID_VALUE" },
    { GLFW_OUT_OF_MEMORY      , "GLFW_OUT_OF_MEMORY" },
    { GLFW_API_UNAVAILABLE    , "GLFW_API_UNAVAILABLE" },
    { GLFW_VERSION_UNAVAILABLE, "GLFW_VERSION_UNAVAILABLE" },
    { GLFW_PLATFORM_ERROR     , "GLFW_PLATFORM_ERROR" },
    { GLFW_FORMAT_UNAVAILABLE , "GLFW_FORMAT_UNAVAILABLE" },
    { GLFW_NO_WINDOW_CONTEXT  , "GLFW_NO_WINDOW_CONTEXT" }
};

void error_cb(int error_code, const char* description)
{
    cerr << "Error: " << glfwErrors[error_code] << " " << description << endl;
}

int main(int argc, char*argv[])
{
    glfwSetErrorCallback(error_cb);
    glfwInit();
    
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Test - Press ESC to Quit", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;

        glfwTerminate();
        return -1;
    }

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    
	return 0;
}
