#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


extern GLFWwindow* window;
extern unsigned int * GL_BufferID;
extern unsigned int * GL_ArrayID;
extern unsigned int * GL_IndiceID;
extern unsigned int * GL_shaderProgram;

typedef struct textureStruct {
unsigned int texture;
float transform[16];// = {1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0};
float colour[4];// = {1.0,1.0,1.0,1.0};
}texture;

extern texture * MKT_VisualObject;

extern unsigned long long int GL_ShaderSize;
extern unsigned long long int MKT_VisualObjectSize;

#define SHADER_TEST 0
#define SHADER_IMAGE 1
