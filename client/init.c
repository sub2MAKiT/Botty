#include "init.h"
#include "main.h"
#include "MKTUtil.h"
#include "shaders.h"

#define STB_IMAGE_IMPLEMENTATION
#include "./external/stb_image.h"

float vertices[] = {
     0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // top right
     0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f    // top left 
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

unsigned int * GL_texture;

unsigned long long int GL_ShaderSize = 0;
unsigned long long int GL_TextureSize = 0;
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
    GL_texture = malloc(1);


    GL_createShader(SC_TestVS,SC_TestFS,vertices,indices,32,6);
    GL_createShader(SC_ImageVS,SC_ImageFS,vertices,indices,32,6);
    GL_createImage();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

int GL_createShader(const char * int_vertexShaderSource, const char *int_fragmentShaderSource, float * vertices,unsigned int * indices, unsigned int sizeOfVertices, unsigned int sizeOfIndices)
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*sizeOfVertices, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    return 0;
}


int GL_createImage()
{
    
    GL_TextureSize++;
    GL_texture = realloc(GL_texture,GL_TextureSize*sizeof(unsigned int));
    glGenTextures(1, &GL_texture[GL_TextureSize-1]);
    glBindTexture(GL_TEXTURE_2D, GL_texture[GL_TextureSize-1]);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("./testSource/MAKiT.png", &width, &height, &nrChannels, 0); 

    printf("%s",data);

    // data[0] = 1.0;
    // data[1] = 0.0;
    // data[2] = 0.0;
    // data[3] = 0.0;
    // data[4] = 0.0;
    // data[5] = 1.0;
    // data[6] = 0.6;
    // data[7] = 0.6;
    // data[8] = 0.0;
    // data[9] = 0.0;
    // data[10] = 1.0;
    // data[11] = 0.0;

    // data[0] = 0;
    // data[1] = 0;
    // data[2] = 0;
    // data[3] = 0;
    // data[4] = 0;
    // data[5] = 0;
    // data[6] = 0;
    // data[7] = 0;
    // data[8] = 0;
    // data[9] = 0;
    // data[10] = 0;
    // data[11] = 0;
    
    //[1.0f,0.0f,0.0f,
      //              0.0f,0.0f,1.0f,
        //            0.6f,0.6f,0.0f,
          //          0.0f,1.0f,0.0f];



    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,    GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    // stbi_image_free(data);

    return 0;
}