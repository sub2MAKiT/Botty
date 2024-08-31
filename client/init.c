#include "init.h"
#include "main.h"
#include "MKTUtil.h"
#include "shaders.h"
#include "input.h"


#define STB_IMAGE_IMPLEMENTATION
#include "./external/stb_image.h"

texture * MKT_VisualObject;
texture * MKT_FontObject;

text * MKT_textObject;

float vertices[] = {
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f,   // top right
     0.5f, -0.5f, 0.0f,   1.0f, 1.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 1.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   0.0f, 0.0f    // top left 
};

float verticesFont[] = {
     0.25f/10,  0.5f/10, 0.0f/10,   0.02f, 0.0f,   // top right
     0.25f/10, -0.5f/10, 0.0f/10,   0.02f, 1.0f,   // bottom right
    -0.25f/10, -0.5f/10, 0.0f/10,   0.01f, 1.0f,   // bottom left
    -0.25f/10,  0.5f/10, 0.0f/10,   0.01f, 0.0f    // top left 
};

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};



GLFWwindow* window;
unsigned int * GL_BufferID;
unsigned int * GL_ArrayID;
unsigned int * GL_IndiceID;
unsigned int * GL_shaderProgram;

unsigned long long int GL_ShaderSize = 0;
unsigned long long int MKT_VisualObjectSize = 0;
unsigned long long int MKT_FontObjectSize = 0;
unsigned long long int MKT_textObjectSize = 0;
int init() { // innit it an int init?
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        DEBUG("Failed to create a window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        DEBUG("Failed to initialize GLAD");
        return -1;
    }   

        

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    GL_BufferID = malloc(1);
    GL_ArrayID = malloc(1);
    GL_IndiceID = malloc(1);
    GL_shaderProgram = malloc(1);
    MKT_VisualObject = malloc(1);
    MKT_FontObject = malloc(1);
    MKT_textObject = malloc(1);


    GL_createShader(SC_TestVS,SC_TestFS,vertices,indices,20,6);
    GL_createShader(SC_ImageVS,SC_ImageFS,vertices,indices,20,6);
    GL_createShader(SC_FontVS,SC_FontFS,verticesFont,indices,20,6);
    GL_createImage("./testSource/Pie.png");
    GL_createImage("./testSource/MAKiT.png");
    GL_createFont("./testSource/font2bitmap.png");
    MKT_createText(0);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

int GL_createShader(const char * int_vertexShaderSource, const char *int_fragmentShaderSource, float * verticesInternal,unsigned int * indices, unsigned int sizeOfVertices, unsigned int sizeOfIndices)
{
    GL_ShaderSize++;
    GL_BufferID = realloc(GL_BufferID,GL_ShaderSize*sizeof(unsigned int));
    GL_ArrayID = realloc(GL_ArrayID,GL_ShaderSize*sizeof(unsigned int));
    GL_IndiceID = realloc(GL_IndiceID,GL_ShaderSize*sizeof(unsigned int));
    GL_shaderProgram = realloc(GL_shaderProgram,GL_ShaderSize*sizeof(unsigned int));


    unsigned int vertexShader;
    unsigned int fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &int_vertexShaderSource, NULL);
    glShaderSource(fragmentShader, 1, &int_fragmentShaderSource, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glGenBuffers(1, &GL_IndiceID[GL_ShaderSize-1]);
    glGenBuffers(1,&GL_BufferID[GL_ShaderSize-1]);
    
    GL_shaderProgram[GL_ShaderSize-1] = glCreateProgram();

    glAttachShader(GL_shaderProgram[GL_ShaderSize-1], vertexShader);
    glAttachShader(GL_shaderProgram[GL_ShaderSize-1], fragmentShader);

    glLinkProgram(GL_shaderProgram[GL_ShaderSize-1]);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glGenVertexArrays(1, &GL_ArrayID[GL_ShaderSize-1]);  
    glBindVertexArray(GL_ArrayID[GL_ShaderSize-1]);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_IndiceID[GL_ShaderSize-1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*sizeOfIndices, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, GL_BufferID[GL_ShaderSize-1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*sizeOfVertices, verticesInternal, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glfwSetKeyCallback(window, key_callback);

    return 0;
}


int GL_createImage(const char * file)
{
    
    MKT_VisualObjectSize++;
    MKT_VisualObject = realloc(MKT_VisualObject,MKT_VisualObjectSize*sizeof(texture));
    for(int i = 0; i < 16; i++)
        MKT_VisualObject[MKT_VisualObjectSize-1].transform[i] = (i==0|i==5|i==10|i==15 ? 1.0 : 0.0);
    for(int i = 0; i < 4; i++)
        MKT_VisualObject[MKT_VisualObjectSize-1].colour[i] = 1.0;
        
    // printf("\n");
    glGenTextures(1, &MKT_VisualObject[MKT_VisualObjectSize-1].texture);
    glBindTexture(GL_TEXTURE_2D, MKT_VisualObject[MKT_VisualObjectSize-1].texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0); 

    // printf("%d\n",nrChannels);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,    GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

    return 0;
}


int GL_createFont(const char * file)
{
    
    MKT_FontObjectSize++;
    MKT_FontObject = realloc(MKT_FontObject,MKT_FontObjectSize*sizeof(texture));
    for(int i = 0; i < 16; i++)
        MKT_FontObject[MKT_FontObjectSize-1].transform[i] = (i==0|i==5|i==10|i==15 ? 1.0 : 0.0);
    for(int i = 0; i < 4; i++)
        MKT_FontObject[MKT_FontObjectSize-1].colour[i] = 1.0;
        
    // printf("\n");
    glGenTextures(1, &MKT_FontObject[MKT_FontObjectSize-1].texture);
    glBindTexture(GL_TEXTURE_2D, MKT_FontObject[MKT_FontObjectSize-1].texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0); 

    // printf("%d\n",nrChannels);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,    GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);


    return 0;
}


int MKT_createText(unsigned int font) {
    MKT_textObjectSize++;
    MKT_textObject = realloc(MKT_textObject,MKT_textObjectSize);
    MKT_textObject[MKT_textObjectSize-1].text = malloc(100);
    MKT_textObject[MKT_textObjectSize-1].sizeOfText = 0;
    MKT_textObject[MKT_textObjectSize-1].font = font;
    for(int i = 0; i < 16; i++)
        MKT_textObject[MKT_textObjectSize-1].transform[i] = (i==0|i==5|i==10|i==15 ? 1.0 : 0.0);
    for(int i = 0; i < 4; i++)
        MKT_textObject[MKT_textObjectSize-1].colour[i] = 1.0;

    
    MKT_textObject[MKT_textObjectSize-1].transform[12] = -1;
}