#include "main.h"
#include "init.h"
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
        glBindTexture(GL_TEXTURE_2D, GL_texture[0]);
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