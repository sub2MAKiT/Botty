#include "cleanup.h"
#include "main.h"

int Cleanup(){

    free(GLBufferID);
    free(GLArrayID);
    free(GLIndiceID);
    free(shaderProgram);

    return 0;
}