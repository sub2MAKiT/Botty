#include "cleanup.h"
#include "main.h"

int Cleanup(){

    free(GL_BufferID);
    free(GL_ArrayID);
    free(GL_IndiceID);
    free(GL_shaderProgram);
    free(MKT_VisualObject);

    for(int i = 0; i < MKT_FontObjectSize; i++)
        free(MKT_FontObject[i].text);

    return 0;
}