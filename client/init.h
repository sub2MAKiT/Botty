#include "main.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080



int init();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int GL_createShader(const char * int_vertexShaderSource, const char *int_fragmentShaderSource, float * vertices,unsigned int * indices, unsigned int sizeOfVertices, unsigned int sizeOfIndices);