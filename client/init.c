#include "init.h"
#include "main.h"
#include "MKTUtil.h"
#include "shaders.h"

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 1.0f, 0.8f, 1.0f);\n"
    "}\0";
float vertices[12] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[6] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};



GLFWwindow* window;
unsigned int * GLBufferID;
unsigned int * GLArrayID;
unsigned int * GLIndiceID;
unsigned int * shaderProgram;

unsigned long long int GLShaderSize = 0;

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

    GLBufferID = malloc(1);
    GLArrayID = malloc(1);
    GLIndiceID = malloc(1);
    shaderProgram = malloc(1);


    GL_createShader(vertexShaderSource,fragmentShaderSource,vertices,indices,12,6);

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
    GLShaderSize++;
    GLBufferID = realloc(GLBufferID,GLShaderSize*sizeof(unsigned int));
    GLArrayID = realloc(GLArrayID,GLShaderSize*sizeof(unsigned int));
    GLIndiceID = realloc(GLIndiceID,GLShaderSize*sizeof(unsigned int));
    shaderProgram = realloc(shaderProgram,GLShaderSize*sizeof(unsigned int));

    glGenBuffers(1,&GLBufferID[GLShaderSize-1]);

    glBindBuffer(GL_ARRAY_BUFFER,GLBufferID[GLShaderSize-1]);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &int_vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &int_fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGenBuffers(1, &GLIndiceID[GLShaderSize-1]);
    
    shaderProgram[GLShaderSize-1] = glCreateProgram();

    glAttachShader(shaderProgram[GLShaderSize-1], vertexShader);
    glAttachShader(shaderProgram[GLShaderSize-1], fragmentShader);
    glLinkProgram(shaderProgram[GLShaderSize-1]);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 2. use our shader program when we want to render an object

    glGenVertexArrays(1, &GLArrayID[GLShaderSize-1]);  
    glBindVertexArray(GLArrayID[GLShaderSize-1]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GLIndiceID[GLShaderSize-1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*sizeOfIndices, indices, GL_STATIC_DRAW);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, GLBufferID[GLShaderSize-1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*sizeOfVertices, vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return 0;
}