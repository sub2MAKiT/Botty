#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

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

typedef struct textStruct {
char * text;
unsigned int sizeOfText;
unsigned int font;
float transform[16];
float colour[4];
}text;  // textTure; // get it? Cause like... text...Ture... it's a texture for text... textture... I'm funny

typedef struct terminalStruct {
text line;
text log;
} terminal;

typedef struct selectedObjectStruct {
long long int type;
long long int index;
text * text;
} selectedObject;

extern texture * MKT_VisualObject;
extern texture * MKT_FontObject;
extern text * MKT_textObject;

extern unsigned long long int GL_ShaderSize;
extern unsigned long long int MKT_VisualObjectSize;
extern unsigned long long int MKT_FontObjectSize;
extern unsigned long long int MKT_textObjectSize;

extern char buttonPressed;

extern selectedObject MKT_selectedTextObject;


#define SHADER_TEST 0
#define SHADER_IMAGE 1
#define SHADER_FONTS 2
