#include "init.h"
#include "main.h"

float vertices[9] = {
    -0.5,-0.5,0.0,
    0.5,-0.5,0.0,
    0.0,0.5,0.0
};
GLFWwindow* window;
unsigned int GLBufferID;

int init() { // innit it an int init?
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create a window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    return 0;
}