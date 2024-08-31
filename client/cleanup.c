#include "cleanup.h"
#include "main.h"
#include "MKTUtil.h"

int Cleanup(){
    DEBUG("started cleanup");

    free(GL_BufferID);
    DEBUG("free");
    free(GL_ArrayID);
    DEBUG("free");
    free(GL_IndiceID);
    DEBUG("free");
    free(GL_shaderProgram);
    DEBUG("free"); // I tried freeing, didn't work so... whoops ¯\_(ツ)_/¯
    // free(MKT_VisualObject);
    DEBUG("cleaned up GL");

    // for(int i = 0; i < MKT_textObjectSize; i++)
        // free(MKT_textObject[i].text);

    // free(MKT_textObject);

    return 0;
}