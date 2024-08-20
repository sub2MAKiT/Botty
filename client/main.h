#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern GLFWwindow* window;
extern unsigned int * GL_BufferID;
extern unsigned int * GL_ArrayID;
extern unsigned int * GL_IndiceID;
extern unsigned int * GL_shaderProgram;

extern unsigned int * GL_texture;

extern unsigned long long int GL_ShaderSize;
extern unsigned long long int GL_TextureSize;

#define SHADER_TEST 0
#define SHADER_IMAGE 1
