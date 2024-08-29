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

typedef struct textTureStruct {
unsigned int texture;
float transform[16];// = {1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0};
float colour[4];// = {1.0,1.0,1.0,1.0};
char * text;
unsigned int sizeOfText;
}textTure; // get it? Cause like... text...Ture... it's a texture for text... textture... I'm funny

extern texture * MKT_VisualObject;
extern textTure * MKT_FontObject;

extern unsigned long long int GL_ShaderSize;
extern unsigned long long int MKT_VisualObjectSize;
extern unsigned long long int MKT_FontObjectSize;

extern char buttonPressed;

extern long long int MKT_selectedFontObject;


#define SHADER_TEST 0
#define SHADER_IMAGE 1
#define SHADER_FONTS 2
