#include "main.h"
#include "init.h"
#include "MKTUtil.h"
#include "input.h"
#include "cleanup.h"

int main(void) {

    init();

    DEBUG("Client initialized");

    while (!glfwWindowShouldClose(window)) {

        getInput();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram[0]);
        glBindVertexArray(GLArrayID[0]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GLIndiceID[0]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    DEBUG("Draw loop terminated");

    glfwTerminate();

    Cleanup();
    return 0;
}