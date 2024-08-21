#include "main.h"
#include "init.h"
#include "render.h"
#include "MKTUtil.h"
#include "input.h"
#include "cleanup.h"

int main(void) {

    init();

    DEBUG("Client initialized");


    while (!glfwWindowShouldClose(window)) {

        // printf("%f\n",glfwGetTime());

        getInput();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(GL_shaderProgram[SHADER_IMAGE]);
        glBindVertexArray(GL_ArrayID[SHADER_IMAGE]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_IndiceID[SHADER_IMAGE]);
        if(glfwGetTime() > 1)
            glBindTexture(GL_TEXTURE_2D, MKT_VisualObject[0].texture);
        else
            glBindTexture(GL_TEXTURE_2D, MKT_VisualObject[1].texture);

        MKT_VisualObject[0].colour[0] += MKT_input.key[1];
        MKT_VisualObject[0].colour[0] -= MKT_input.key[2];

        MKT_VisualObject[0].transform[12] += MKT_input.arrow[0]?0.1:0.0;
        MKT_VisualObject[0].transform[12] -= MKT_input.arrow[1]?0.1:0.0;

        MKT_VisualObject[0].transform[13] -= MKT_input.arrow[2]?0.1:0.0;
        MKT_VisualObject[0].transform[13] += MKT_input.arrow[3]?0.1:0.0;

        unsigned int colorLoc = glGetUniformLocation(GL_shaderProgram[SHADER_IMAGE], "modColor");
        unsigned int transformLoc = glGetUniformLocation(GL_shaderProgram[SHADER_IMAGE], "transform");
        glUniform4fv(colorLoc, 1, MKT_VisualObject[0].colour);
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, MKT_VisualObject[0].transform);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DEBUG("Draw loop terminated");

    glfwTerminate();
    DEBUG("GLFW terminated");

    Cleanup();
    DEBUG("Cleaned up");
    return 0;
}