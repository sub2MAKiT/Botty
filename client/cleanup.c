#include "cleanup.h"
#include "main.h"

int Cleanup(){

    free(GL_BufferID);
    free(GL_ArrayID);
    free(GL_IndiceID);
    free(GL_shaderProgram);
    free(MKT_VisualObject);

    return 0;
}