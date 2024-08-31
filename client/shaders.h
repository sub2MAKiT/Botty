
const char *SC_TestVS = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *SC_TestFS = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.0f, 1.0f, 0.8f, 1.0f);\n"
    "}\0";
    

const char *SC_ImageVS = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "uniform mat4 transform;\n"
    "uniform vec4 modColor;\n"
    "out vec4 ourColor;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = transform * vec4(aPos, 1.0f);\n"
    "   ourColor = modColor;\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";



    
const char *SC_ImageFS = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec4 ourColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "   FragColor = texture(ourTexture, TexCoord) * ourColor;\n"
    "}\0";


const char *SC_FontVS = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "uniform mat4 transform;\n"
    "uniform vec4 modColor;\n"
    "uniform int letter;\n"
    "uniform int offset;\n"
    "uniform int newline;\n"
    "out vec4 ourColor;\n"
    "out vec2 TexCoord;\n"
    "out float outLetter;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = transform * vec4(aPos.x+float(offset)*0.05,aPos.y-float(newline)*0.1,aPos.z, 1.0f);\n"
    "   ourColor = modColor;\n"
    "   outLetter = float(letter);\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";



    
const char *SC_FontFS = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec4 ourColor;\n"
    "in vec2 TexCoord;\n"
    "in float outLetter;\n"
    "uniform sampler2D ourTexture;\n"
    "void main()\n"
    "{\n"
    "   FragColor = texture(ourTexture, vec2(TexCoord.x+outLetter/95,TexCoord.y)) * ourColor;\n"
    "}\0";